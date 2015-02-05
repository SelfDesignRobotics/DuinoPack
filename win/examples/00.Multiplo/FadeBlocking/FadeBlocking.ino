//
// FadeBlocking
//
// fade an LED without PWM and analogWrite...
// uses delay() instead
//
// Notes:
//   - Assumes an LED is properly connected to pin D9
//   - not using analogWrite because PWM not configured on Duinobot
//


#define DURATION 512
#define SCALE 40

int led = 9;


void setup()
{
  pinMode(led, OUTPUT);
}


void loop()
{
  // fade from on to off
  for (int i = 0; i < DURATION; i++)
  {
    digitalWrite(led, 0);
    delay(i/SCALE);
  
    digitalWrite(led, 1);
    delay((DURATION - i)/SCALE);
  }

  // glow more nothing to fully on
  for (int i = DURATION; i >= 0 ; i--)
  {
    digitalWrite(led, 0);
    delay(i/SCALE);
  
    digitalWrite(led, 1);
    delay((DURATION - i)/SCALE);
  }

}


