//
// TestSensor
//
// Read the raw analog sensor reading on pin A1
// (also called port S1 on the Duinobot)
//

// run once, when the sketch starts
void setup()
{
  Serial.begin(9600);
}

// run over and over again
void loop()
{
  Serial.print("Sensor 1: ");
  Serial.println(analogRead(1));
  
  delay(500);
}







