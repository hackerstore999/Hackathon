#include <AllThingsTalk_WiFi.h>       // Load (include) the AllThingsTalk WiFi SDK - Read more about it on https://gitub.com/allthingstalk/arduino-wifi-sdk

auto wifiCreds    = WifiCredentials("Your_WiFi", "Your_WiFi_Password");         // Your WiFi Network Name and Password
auto deviceCreds  = DeviceConfig("Your_Device_ID", "maker:Your_Device_Token");  // Go to AllThingsTalk Maker > Devices > Your Device > Settings > Authentication to get your Device ID and Token
auto device       = Device(wifiCreds, deviceCreds);                             // Create "device" object
char* sensorAsset = "analog-example";                                           // Name of asset on AllThingsTalk to which you'll receive the value (automatically created below)

const long    period        = 1000;   // Change this to change how many milliseconds you want between analog port readings
int           analogValue   = 0;      // Variable that will store the value of the analog port
unsigned long startMillis;            // Used to keep track of send intervals
unsigned long currentMillis;          // Used to keep track of send intervals

void setup() {                        // This function is only called once, when the device boots
  Serial.begin(115200);               // Starts the Serial port for debugging (at baud rate 115200)
  device.debugPort(Serial);           // Enable debug output from AllThingsTalk SDK. 
  device.wifiSignalReporting(true);   // Enable AllThingsTalk WiFi SDK's feature that sends NodeMCU's WiFi Signal Strength to your AllThingsTalk Maker
  device.createAsset(sensorAsset, "Analog Value", "sensor", "integer"); // Create asset on AllThingsTalk to send analog value to
  device.init();                      // Initialize WiFi and AllThingsTalk
  startMillis = millis();             // Saves the initial millis value at boot to startMillis variable
}

void analogCheck() {                               // This is the function that checks the value of analog port
  currentMillis = millis();                        // Saves the value of "millis()" at the time of execution of this line
  if (currentMillis - startMillis >= period) {     // If current time minus the last saved 'startMillis' time is bigger than the period defined above, it'll run the code below
    analogValue = analogRead(A0);                  // Reads the analog port A0 of ESP8266 (NodeMCU) and saves it to "analogButton" variable
    Serial.print("Current Analog Value: ");        // Prints to Serial port
    Serial.println(analogValue);                   // Prints to Serial port
    device.send(sensorAsset, analogValue);         // Sends the data to AllThingsTalk. Data is sent to "sensorAsset"
    startMillis = currentMillis;                   // Resets the startMillis by assigning it the value of currentMillis
  }
}

void loop() {        // Main code that'll be run in loop all the time
  device.loop();     // Keep AllThingsTalk and WiFi connection alive
  analogCheck();     // Runs our "analogCheck" function, which checks the value of analog port and publishes it
}