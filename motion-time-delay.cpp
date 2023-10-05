int sensorState = 0;

void setup()
{
  pinMode(10, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  sensorState = digitalRead(10);

  if (sensorState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH); // Turn on the LED
    delay(10000); // Wait for 10 seconds (10000 milliseconds)
    digitalWrite(LED_BUILTIN, LOW); // Turn off the LED after 10 seconds
  } else {
    digitalWrite(LED_BUILTIN, LOW); // Turn off the LED if the sensor is not active
  }

  delay(10); // Delay a little bit to improve simulation performance
}
