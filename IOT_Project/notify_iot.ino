#define MQ2_SENSOR_PIN 14 // MQ2 sensor pin
#define buzz 4             // Buzzer pin
#define led 33             // LED pin

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Initialize pins
  pinMode(MQ2_SENSOR_PIN, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(led, OUTPUT);

  // Wait for serial monitor to open
  delay(2000);
}

void loop() {
  static unsigned long previousMillis = 0;  // To track time
  unsigned long currentMillis = millis();  // Current time
  static unsigned long delayTime = 5000;   // Default delay (5 seconds)

  // Check if it's time to read the sensor
  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;

    // Read the analog value from the MQ-2 sensor
    int sensorValue = analogRead(MQ2_SENSOR_PIN);

    // Print the sensor value to the Serial Monitor
    Serial.print("MQ-2 Sensor Value: ");
    Serial.println(sensorValue);

    // Control the buzzer and LED based on the sensor value
    if (sensorValue > 1500) {
      digitalWrite(led, HIGH);
      digitalWrite(buzz, HIGH);
      delayTime = 1000;  // Smoke detected, read every 1 second
    } else {
      digitalWrite(led, LOW);
      digitalWrite(buzz, LOW);
      delayTime = 5000;  // No smoke, read every 5 seconds
    }
  }
}
