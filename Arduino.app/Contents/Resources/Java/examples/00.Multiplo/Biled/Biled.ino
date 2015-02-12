//
// Biled
//
// Alternately blink red/green LED's on the Duinobot Controller.
//
// The Duinobot controller comes with two LED's; one red, the other green.
// These LED's can be in one of three states:
//    1 Neither LED on
//    2 green LED on  / red LED off
//    3 green LED off / red LED on 
// 
// The bicolour LED is controlled via the digital port BILED (pin 21).
// Setting this port to:
//    * GREEN_LED turns the green LED on and the red LED off
//    * RED_LED turns the green LED off and the red LED on
//  
//

#define GREEN_LED  1
#define RED_LED    0

// run once, when the sketch starts
void setup ()
{
  pinMode(BILED, OUTPUT);
}

// run over and over again
void loop ()
{
  digitalWrite(BILED, GREEN_LED);
  delay(100);
  digitalWrite(BILED, RED_LED);
  delay(100);
}
