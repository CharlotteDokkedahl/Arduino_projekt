/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

Encoder encoder(5, 6);

int encoderCount=0;
int realEncoderCount=0;

int stateAmount=5;


void setup() 
{

  pinMode(8,OUTPUT);

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
}


void loop() 
{
  int encoderCount = encoder.read();
  int realEncoderCount = encoderCount/4;

if(realEncoderCount>stateAmount)
{
  int realEncoderCount=1;
}

if(realEncoderCount==1)
{
     lcd.setCursor(6,0)
    lcd.print("Ur");
}

if(realEncoderCount==2)
{
     lcd.setCursor(4,0)
    lcd.print("Stop ur");
}

if(realEncoderCount==3)
{
     lcd.setCursor(4,0)
    lcd.print("Gæt  tid");
}

if(realEncoderCount==4)
{
     lcd.setCursor(4,0)
    lcd.print("Kog æg");
}

if(realEncoderCount==5)
{
     lcd.setCursor(4,0)
    lcd.print("Vække ur");
}

 




}