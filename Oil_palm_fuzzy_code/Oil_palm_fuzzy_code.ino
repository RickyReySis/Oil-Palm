#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>
#include <HardwareSerial.h>

#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>
#include <TimeLib.h>
#include <StringSplitter.h>

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

// WIFI & Firebase
#define WIFI_SSID "SSID-Wifi"
#define WIFI_PASSWORD "Password-Wifi"

#define DATABASE_URL "DATABASE_URL"
#define API_KEY "API_KEY"

//choose type code
////fuzzy mmode
#define USER_EMAIL "Email"
#define USER_PASSWORD "Pwd"
DeviceAddress DS18B20 = {0x28, 0xE9, 0xA4, 0x57, 0x4, 0xE1, 0x3C, 0xE1};
const int AirValue = 2536;   // ANALOG UDARA
const int WaterValue = 1030; // ANALOG AIR
float calibrationFactor = 4.5;
int soilMoistureThreshold = 75;
const float a = 4E-5;  
const float b = -0.213;
const float c = 270.63;

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
FirebaseJson json;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7 * 3600);

HardwareSerial SerialPort(2);

// Pin definitions for Sensor
#define DHTPIN 4         // DHT PIN
#define ONE_WIRE_BUS 15  // DS18B20 PIN
#define WATER_FLOW 5     // WATER FLOW PIN
#define MOTOR1_PIN1 27
#define MOTOR1_PIN2 26
#define ENABLE1_PIN 14
#define RE 19
#define DE 18

// Motor A
int motor1Pin1 = 27;
int motor1Pin2 = 26;
int enable1Pin = 14;

//// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 255;

const int SensorPin = 34;    // SOIL MOISTURE PIN
int soilMoistureValue = 0;
int soilmoisturepercent = 0;

// Modbus RTU requests for reading NPK values
const byte nitro[] = {0x01, 0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01, 0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};

// A variable used to store NPK values
byte values[11];

// Declare global variables here
float temperature, humidity, DS18B20temperature;
int soilMoistureRaw, soilMoisturePercentage;
float flowRate, totalVolumeML, totalVolumeL, flowRateMLPerMinute, flowRateLPerMinute;
int motorStatus, motorSpeed, motorStatusPercentage;
byte val1, val2, val3;

// Sets up a new SoftwareSerial object
SoftwareSerial mod(17, 16);

// Uncomment whatever type you're using!
// #define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22  // DHT 22
DHT dht(DHTPIN, DHTTYPE);

// DS18B20 READER
// Setup a oneWire instance to communicate with a OneWire device
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

//Firebase Path
String uid;
String databasePath;
String currentTime;
String statusPath = "/status";
String temperaturePath = "/temperature";
String humidityPath = "/humidity";
String soiltemperaturePath = "/soiltemperature";
String soilMoistureRawPath = "/soilRawMoisture";
String soilMoisturePercentagePath = "/soilMoisturePercentage";
String nitrogenPath = "/nitrogen";
String phosphorousPath = "/phosphorous";
String potassiumPath = "/potassium";
String totalVolumeMLPath = "/totalVolumeML";
String totalVolumeLPath = "/totalVolumeL";
String flowRateMLPerMinutePath = "/flowRateMLPerMinute";
String flowRateLPerMinutePath = "/flowRateLPerMinute";
String motorStatusPath = "/motorStatus";
String motorStatusPercentagePath = "/motorStatusPercentage";
String motorSpeedPath = "/motorSpeed";
String pulseCountPath = "/pulseCount";
String timePath = "/timestamp";
String FuzzyValuePath = "/FuzzyValue";

String parentPath;
String timestamp;
String path; // Firebase path

bool motorRunning = false;

int dataCount = 0;

unsigned long sendDataPrevMillis = 0;
unsigned long timerDelay = 60000;
int setHours = 0;
int setMinutes = 1;
int setSeconds = 0;

// WATER FLOW SENSOR
long currentMillis = 0;
long previousMillis = 0;
int interval = 1000;
boolean ledState = LOW;
volatile byte pulseCount;
byte pulse1Sec = 0;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;

int errorCount = 0;

//Fuzzy
#include <Fuzzy.h>
// Fuzzy
Fuzzy *fuzzy = new Fuzzy(); 

// Fuzzy Input Soil
FuzzySet *kering = new FuzzySet(0, 0, 20, 40);
FuzzySet *normal = new FuzzySet(40, 55, 65, 80); 
FuzzySet *basah = new FuzzySet(80, 90, 100, 101);

// Fuzzy Input Temp
FuzzySet *dingin = new FuzzySet(0, 0, 10, 20);
FuzzySet *hangat = new FuzzySet(20, 23, 27, 30);
FuzzySet *panas = new FuzzySet(30, 40, 49, 49);

// Fuzzy Input Humidity
FuzzySet *tidaklembap = new FuzzySet(0, 15, 25, 40);
FuzzySet *lembapsedang = new FuzzySet(40, 50, 60, 70);
FuzzySet *lembap = new FuzzySet(70, 80, 90, 100); 

// Fuzzy Output
FuzzySet *on = new FuzzySet(50, 50, 100, 100);
FuzzySet *off = new FuzzySet(0, 0, 50, 50); 


#include "fuzzy_rule.h"
#include "fuzzy_set.h"
#include "readingvalue.h"
#include "setup1.h"
#include "print.h"

void setup() {
  Serial.begin(115200);
//  Serial.begin(115200, SERIAL_8N1, 3, 1);
  Serial.begin(115200, SERIAL_8N1, 16, 17);

  setupDHT();
  setupDS18B20();
  setupSoilMoisture();
  setupWaterFlow();
  setupMOTOR();
  setupLEDC();
  setupNPKSensor();
  setupWiFi();
  setupFirebase();
  //Memanggil Fungsi Logika Fuzzy
  fuzzyrule();
  fuzzyset();
}

void loop() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  // put your main code here, to run repeatedly:
  // DHT 11
  temperature = DHT_Temperature();
  humidity = DHT_Humidity();

  // DS18B20
  DS18B20temperature = DS18B20_Temperature(1);
  
  // Soil Moisture
  soilMoistureRaw = Soil_moisture();
  soilMoisturePercentage = Soil_moisturePercent();
  
  // Water Flow
  flowRate = WaterFlow_Flowrate();
  //totalMilliLitres = pulseCount / calibrationFactor;
  
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    pulse1Sec = pulseCount;
    flowRate = ((1000.0 / interval) * pulse1Sec) / calibrationFactor;
  }

  // NPK Sensor
  val1 = nitrogen();
  delay(250);
  val2 = phosphorous();
  delay(250);
  val3 = potassium();
  delay(250);

  
  // Evaluasi nilai linguistik untuk variabel input
  fuzzy->setInput(2, temperature);
  fuzzy->setInput(3, humidity);
  fuzzy->setInput(1, soilMoisturePercentage);


  fuzzy->fuzzify();
  
  // Defuzzifikasi untuk mendapatkan nilai output
  float FuzzyValue = fuzzy->defuzzify(1); 

  Serial.println("\nResult: ");
  Serial.print("\t\t\tMotor Status: ");
  Serial.print(FuzzyValue); 
  
  // Atur durasi motor terbuka berdasarkan nilai FuzzyValue
  int motorDuration = map(FuzzyValue, 0, 100, 0, 600); // Durasi dalam detik

  if (FuzzyValue >= 6) {
    // Motor sudah menyala
//    unsigned long currentTime = millis();
      // Matikan motor jika durasi sudah tercapai
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      motorRunning = false;
      delay(FuzzyValue);
    }
  else {
    // Matikan motor
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    motorRunning = false;
  }

  // Calculate additional values
  totalVolumeML = 0.6449 * FuzzyValue + 0.36;
  totalVolumeL = totalVolumeML/1000;
  
  // Motor control based on soil moisture
  motorSpeed = motorSpeed;
  motorStatusPercentage = motorSpeed * 100 / 255;
  motorStatus = (motorSpeed != 0) ? 1 : 0;
  motorRunning = (motorStatus == 1) ? true : false;
  
  ledcWrite(pwmChannel, motorSpeed  );  

  // Call the printSensorData function whenever you want to print the sensor data
  printSensorData();

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection lost. Retrying in the background...");
    setupWiFi(); // Attempt to reconnect
  }

  if ( Firebase.ready() && ((millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0)) ){
    sendDataPrevMillis = millis();
    unsigned long hours = (getRawTime() % 86400L) / 3600;
    if ( (hours % 4 == 0) ){
      post_data("Recording");
    }else{
      post_data("Standby");
    } 
  }
}
