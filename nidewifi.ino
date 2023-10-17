#include <ESP8266WiFi.h>

int photoresistorPin = A0; // Analog pin to which the photoresistor is connected
int pirSensorPin = D1;     // Digital pin to which the PIR motion sensor is connected (change as needed)
int ledPin = D2;           // Digital pin to which the LED is connected (change as needed)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirSensorPin, INPUT);
  Serial.begin(115200);
  delay(100);

  // Connect to Wi-Fi
  const char* ssid = "Hacker's Device";
  const char* password = "i76d5400";
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  int sensorValue = analogRead(photoresistorPin);
  int threshold = 500; // You may need to adjust this value based on your setup

  if (sensorValue < threshold) {
    int pirSensorState = digitalRead(pirSensorPin);
    if (pirSensorState == HIGH) {
      digitalWrite(ledPin, HIGH); // Turn on the LED when it's dark and motion is detected
    } else {
      digitalWrite(ledPin, LOW); // Turn off the LED when it's dark but no motion is detected
    }
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED when there is light
  }
}
