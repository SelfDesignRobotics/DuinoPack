//
// FadeBlocking
//
// fade an LED without PWM ...
// uses delay() instead
//
// Notes:
// Assumes an LED is properly connected to pin D9
//

#define ledPin 9

#define DURATION 512
#define SCALE 40

void setup()
{
  pinMode(ledPin, OUTPUT);
}


void loop()
{
  // fade from on to off
  for (int i = 0; i < DURATION; i++)
  {
    digitalWrite(ledPin, 0);
    delay(i/SCALE);
  
    digitalWrite(ledPin, 1);
    delay((DURATION - i)/SCALE);
  }

  // glow more nothing to fully on
  for (int i = DURATION; i >= 0 ; i--)
  {
    digitalWrite(ledPin, 0);
    delay(i/SCALE);
  
    digitalWrite(ledPin, 1);
    delay((DURATION - i)/SCALE);
  }

}


