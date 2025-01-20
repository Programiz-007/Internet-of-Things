#define BLYNK_TEMPLATE_ID "TMPL3a99vjZjX"
#define BLYNK_TEMPLATE_NAME "Smoke Sensor"
#define BLYNK_AUTH_TOKEN "8bnRIKfXQBUpBlIZmiAL1-P2uQ-IOlzm"

#define buzzer 4
#define smoke 33
#define led 27

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <LiquidCrystal_PCF8574.h> 

char auth[] = BLYNK_AUTH_TOKEN;

LiquidCrystal_PCF8574 lcd(0x27);  

char ssid[] = "Manthan";
char pass[] = "Manthan00";

BlynkTimer timer;

//pins that works with internet
//analogRead( 39 );
//analogRead( 34 );
//analogRead( 35 );
//analogRead( 32 );
//analogRead( 33 );

int data;
int ppm;
unsigned long previousMillis = 0;  // To track time
unsigned long delayTime = 5000;   // Default delay: 5 seconds

void sendSensor() {
  Blynk.virtualWrite(V0, ppm);
  lcd.print(ppm);
  Serial.println(ppm);
  if (ppm > 4335) {
    Blynk.logEvent("smoke_detected", "smoke detected");
    lcd.setCursor(0, 0);
    lcd.print("Smoke Detected:");
  } else {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("No danger:");
  }
}

void setup() {
  // initialize LCD
  lcd.begin(16, 2);
  lcd.setBacklight(255); // turn on LCD backlight                      

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(smoke, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Read sensor data
  data = analogRead(smoke);
  ppm = map(data, 75, 3500, 300, 10000);
  lcd.setCursor(0, 1);

  // Check for smoke condition
  if (ppm > 4335) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delayTime = 1000;  // If smoke is detected, reduce delay to 1 second
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delayTime = 5000;  // No smoke, increase delay to 5 seconds
  }

  

  // Check if the delay time has passed
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= delayTime) {
    previousMillis = currentMillis;  // Update the timestamp
    
    sendSensor();  // Send sensor data
    
  }

  Blynk.run();
  timer.run();
}