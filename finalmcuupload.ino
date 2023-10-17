int photoresistorPin = A0; // Analog pin to which the photoresistor is connected
int pirSensorPin = 5;     // Digital pin to which the PIR motion sensor is connected (change as needed)
int ledPin = 4;           // Digital pin to which the LED is connected (change as needed)


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirSensorPin, INPUT);
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
