
#include <Encoder.h>
#include "rgb_lcd.h"

rgb_lcd lcd;


int timer = 00;
int sekunder = 00;
int msekunder = 00;

void Ur()
{

}


void setup() 
{
  lcd.begin(8, 3);
  lcd.print(timer);
  lcd.print(":");
  lcd.print(sekunder);
  lcd.print(":");
  lcd.print(msekunder);
}


void loop() 
{
  if(state==2)
{
  //State 2 stop ur
   lcd.setRGB(255,0,0);
   lcd.setCursor(0,0);
   lcd.print("Stop ur");
   if(//button pressed)
   {
    
   }
}
}




