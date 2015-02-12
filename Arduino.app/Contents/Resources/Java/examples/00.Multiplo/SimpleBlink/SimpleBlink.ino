//
// SimpleBlink
//
// Blink the LED on port LED_BUILTIN on and off.
//
//  NOTES: 
//      * The Duinobot board has a built-in LED on pin 13 (LED_BUILT_IN)
//

// run once, when the sketch starts
void setup()
{  
  pinMode(LED_BUILTIN, OUTPUT); 
}

// run over and over again
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}












