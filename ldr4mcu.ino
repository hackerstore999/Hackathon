int photoresistorPin = A0; // Analog pin to which the photoresistor is connected
int ledPin = 0; // Digital pin to which the LED is connected

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(photoresistorPin);

  // Adjust the threshold value to determine when the LED should turn on
  int threshold = 500; // You may need to adjust this value based on your setup

  if (sensorValue < threshold) {
    digitalWrite(ledPin, HIGH); // Turn on the LED when it's dark
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED when there is light
  }
}