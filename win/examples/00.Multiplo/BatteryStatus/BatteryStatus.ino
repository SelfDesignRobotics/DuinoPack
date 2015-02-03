//
// BatteryStatus
//
// A simple test of reading the battery charge state for
// the Duinobot and printing it to the Serial Monitor.
// 
// We are using the analog port BATTERY (pin20) on the Duinobot.
// This port is dedicated to measuring battery pack voltage.
//
//  NOTES: 
//      - Ports S0-S5 are analog input pins
//      - S0 is identical to Arduino A0 and so on (S5=A5)
//      - To use these ports as Digital pins add 14
//

// run once, when the sketch starts
void setup()
{
  Serial.begin(9600);
}

// run over and over again
void loop() {
  int sensorValue = analogRead(BATTERY);
  Serial.println(sensorValue);
  delay(100);
}
