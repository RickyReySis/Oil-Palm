void setupDHT() {
  dht.begin();
}

void setupDS18B20() {
  sensors.begin();
  sensors.setResolution(DS18B20, 12);  // Ubah resolusi sesuai kebutuhan
}

void setupSoilMoisture() {
  pinMode(SensorPin, INPUT);
}

//void setupRainSensore() {
//  pinMode(Rain_PIN, OUTPUT);  // configure the power pin pin as an OUTPUT
//  pinMode(RainAO_PIN, INPUT);
//}

void setupLEDC() {
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(enable1Pin, pwmChannel);
}

void setupNPKSensor() {
  mod.begin(9600);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
}

void setupMOTOR() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
}

void setupWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    attempts++;

//    if (attempts > 15) {
//      // If unable to connect after 30 seconds, reset the Arduino
//      ESP.restart();
//    }

    if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect to WiFi. Retrying in the background...");
  } else {
    Serial.println("Connected to WiFi");
  }
  }

  Serial.println("Connected to WiFi");
}

void setupFirebase() {
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);
  config.token_status_callback = tokenStatusCallback;
  config.max_token_generation_retry = 5;
  Firebase.begin(&config, &auth);

  Serial.println("Getting User UID");
  while ((auth.token.uid) == "") {
    Serial.print('.');
    delay(1000);
  }
  uid = auth.token.uid.c_str();
  Serial.print("User UID: ");
  Serial.println(uid);
  databasePath = "/UsersData/" + uid + "/readings";
}


void setupWaterFlow() {
  pinMode(WATER_FLOW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(WATER_FLOW), pulseCounter, FALLING);
}
