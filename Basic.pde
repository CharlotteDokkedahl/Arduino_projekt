/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

Encoder encoder(5, 6);

int encoderValue=0;


void setup() 
{

  pinMode(8,OUTPUT);

    // set up the LCD's number of columns and rows:
    lcd.begin(8, 5);
    
}


void loop() 
{
  int encoderValue= encoder.read();
  //int encoderButton= encoder.digitalRead();

  lcd.setCursor(0, 0);
    // Print a message to the LCD.
    //lcd.print(encoderValue);
    lcd.print("    ");
    lcd.print("00:00:00");

  if(encoderValue>=20)
  {
    digitalWrite(8,HIGH);
  }
  else 
  {
     digitalWrite(8,LOW);
  }



}
