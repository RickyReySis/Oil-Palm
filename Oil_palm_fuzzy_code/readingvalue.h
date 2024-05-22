float DHT_Temperature() {
  float temperature = dht.readTemperature();
  if (!isnan(temperature)) {
    return temperature;
  } else {
    return -1.0; // Mengembalikan -1 jika ada kesalahan
  }
}

float DHT_Humidity() {
  float humidity = dht.readHumidity();
  if (!isnan(humidity)) {
    return humidity;
  } else {
    return -1.0; // Mengembalikan -1 jika ada kesalahan
  }
}

float DS18B20_Temperature(int sensorNumber) {
  sensors.requestTemperatures();
  return sensorNumber == 1 ? sensors.getTempC(DS18B20) : -1.0;
}

int Soil_moisture() {
  return analogRead(SensorPin);
}

int Soil_moisturePercent() {
  int soilMoistureValue = Soil_moisture();
  float soilMoisturePercent = a*soilMoistureRaw*soilMoistureRaw + b*soilMoistureRaw + c;
  if(soilMoisturePercent > 100) {
    soilMoisturePercent = 100;
  }

  // jika nilai negatif maka dianggap 0%
  if(soilMoisturePercent < 0) {
    soilMoisturePercent = 0;
  }
//  int range = AirValue - WaterValue;
//  int soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
//  soilmoisturepercent = constrain(soilmoisturepercent, 0, 100);  // Ensure the result is within the valid range
  return soilMoisturePercent;
}

float WaterFlow_Flowrate() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    
    pulse1Sec = pulseCount;
    pulseCount = 0;
  
    flowRate = ((1000.0 / (millis() - previousMillis)) * pulse1Sec) / calibrationFactor;
    previousMillis = millis();
    return flowRate;
  } else {
    return -1.0; // Mengembalikan -1 jika ada kesalahan
  }
}

// Fungsi untuk menghitung laju aliran dalam mL per menit
float calculateFlowRateMLPerMinute() {
  return flowRate * 1000;
}

// Fungsi untuk menghitung laju aliran dalam L per menit
float calculateFlowRateLPerMinute() {
  return flowRate;
}

byte nitrogen(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(nitro,sizeof(nitro))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
    }
//    Serial.println();
  }
  return values[4];
}
 
byte phosphorous(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(phos,sizeof(phos))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
    }
//    Serial.println();
  }
  return values[4];
}
 
byte potassium(){
  digitalWrite(DE,HIGH);
  digitalWrite(RE,HIGH);
  delay(10);
  if(mod.write(pota,sizeof(pota))==8){
    digitalWrite(DE,LOW);
    digitalWrite(RE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
//    Serial.print(values[i],HEX);
    }
//    Serial.println();
  }
  return values[4];
}

unsigned long convertToMillis(int hours, int minutes, int seconds) {
  return (hours * 3600 + minutes * 60 + seconds) * 1000;
}

String getCurrentTime() {
  timeClient.update();
  unsigned long now = timeClient.getEpochTime();
  time_t now_t = static_cast<time_t>(now);
  struct tm *timeinfo = localtime(&now_t);
  
  char timeString[25];
  strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeinfo);
  
  Serial.println(timeString);
  return String(timeString);
}

unsigned long getCurrentEpochTime() {
  timeClient.update();
  unsigned long now = timeClient.getEpochTime() + 7 * 3600;
  return now;
}

unsigned long getRawTime() {
  timeClient.update();
  unsigned long now = timeClient.getEpochTime() + 1 * 3600;
  return now;
}

void IRAM_ATTR pulseCounter()
{
  pulseCount++;
}
