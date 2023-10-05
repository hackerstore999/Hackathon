int sensorPin = A0;  // Analog pin to which the LDR (photoresistor) is connected
int ledPin = 9;      // Digital pin to which the LED is connected
int threshold = 300; // Adjust this value based on your setup

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    digitalWrite(ledPin, HIGH); // Turn on the LED when it's dark
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED when there is light
  }

  delay(100); // Wait for 100 milliseconds
}
