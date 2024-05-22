void printSensorData() {
  Serial.print("DHT_Temperature: ");
  Serial.println(temperature);
  Serial.print("DHT_Humidity: ");
  Serial.println(humidity);
  Serial.print("DS18B20_Temperature_Sensor1: ");
  Serial.println(DS18B20temperature);
  Serial.print("Soil Moisture (Raw): ");
  Serial.println(soilMoistureRaw);
  Serial.print("Soil Moisture (Percentage): ");
  Serial.println(soilMoisturePercentage);
  Serial.print("NPK_Nitrogen: ");
  Serial.println(val1);
  Serial.print("NPK_Phosphorous: ");
  Serial.println(val2);
  Serial.print("NPK_Potassium: ");
  Serial.println(val3);
  Serial.print("Total Volume (mL): ");
  Serial.println(totalVolumeML);
  Serial.print("Total Volume (L): ");
  Serial.println(totalVolumeL);
  Serial.print("Flow Rate (mL/min): ");
  Serial.println(flowRateMLPerMinute);
  Serial.print("Flow Rate (L/min): ");
  Serial.println(flowRateLPerMinute);
  Serial.print("Motor status: ");
  Serial.println(motorStatus);
  Serial.print("Motor statuspercentage: ");
  Serial.println(motorStatusPercentage);
  Serial.print("Motor Speed: ");
  Serial.println(motorSpeed);
  Serial.print("Motor Running: ");
  Serial.println(motorRunning ? "true" : "false");
  Serial.println("--------------");
}

void post_data(String status){
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

 
  // Calculate additional values
  totalVolumeML = 0.6449 * FuzzyValue + 0.36;
  totalVolumeL = totalVolumeML/1000;

  // Motor control based on soil moisture
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
  
  // Motor control based on soil moisture
  motorSpeed = motorSpeed;
  motorStatusPercentage = motorSpeed * 100 / 255;
  motorStatus = (motorSpeed != 0) ? 1 : 0;
  motorRunning = (motorStatus == 1) ? true : false;
  
  ledcWrite(pwmChannel, motorSpeed  );  

  // Call the printSensorData function whenever you want to print the sensor data
  printSensorData();
    
    timestamp = getCurrentTime();

//    // Variables for sensor data
//    float temperature, humidity, DS18B20temperature, flowRate, flowRateMLPerMinute, flowRateLPerMinute;
//    int soilMoistureRaw, soilMoisturePercentage, val1, val2, val3, motorStatus, motorStatusPercentage, pulseCount;
//    float totalVolumeML, totalVolumeL;
    
    unsigned long rawTime = getRawTime();
    time_t rawTime_t = static_cast<time_t>(rawTime);
    const struct tm *timeinfo = localtime(&rawTime_t);
  
    char dateBuffer[20];
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", timeinfo);
    String str_date = dateBuffer;
  
    parentPath = databasePath + "/" + str_date + "/" + timestamp;

    json.clear();
    json.set(FuzzyValuePath.c_str(),(FuzzyValue));
    json.set(temperaturePath.c_str(),(temperature));
    json.set(humidityPath.c_str(),(humidity));
    json.set(soiltemperaturePath.c_str(),(DS18B20temperature));
    json.set(soilMoistureRawPath.c_str(),(soilMoistureRaw));
    json.set(soilMoisturePercentagePath.c_str(),(soilMoisturePercentage));
    json.set(nitrogenPath.c_str(),(val1));
    json.set(phosphorousPath.c_str(),(val2));
    json.set(potassiumPath.c_str(),(val3));
    json.set(totalVolumeMLPath.c_str(),(totalVolumeML));
    json.set(totalVolumeLPath.c_str(),(totalVolumeL));
    json.set(flowRateMLPerMinutePath.c_str(),(flowRateMLPerMinute));
    json.set(flowRateLPerMinutePath.c_str(),(flowRateLPerMinute));
    json.set(motorStatusPath.c_str(),(motorStatus));
    json.set(motorStatusPercentagePath.c_str(),(motorStatusPercentage));
    json.set(motorSpeedPath.c_str(),(motorSpeed));
    json.set(pulseCountPath.c_str(),(pulseCount));
    json.set(timePath.c_str(),(timestamp));
    
    Serial.printf("Set json... %s\n", Firebase.RTDB.setJSON(&fbdo, parentPath.c_str(), &json) ? "ok" : fbdo.errorReason().c_str());
    String jsonString;
  json.toString(jsonString);
  Serial.println("JSON String: " + jsonString);

  Serial.print("Setting JSON... ");
  if (Firebase.RTDB.set(&fbdo, parentPath.c_str(), jsonString.c_str())) {
    Serial.println("OK");
  } else {
    Serial.println("Failed");
    Serial.println(fbdo.errorReason());
  }
}
