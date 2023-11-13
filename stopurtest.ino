
#include <Encoder.h>
#include "rgb_lcd.h"

rgb_lcd lcd;


int minutter = 0;
int sekunder = 0;
int msekunder = 0;


void Ur()
{

}


void setup() 
{
  lcd.begin(16, 2);
  pinMode(6, INPUT);
}


void loop() 
{
  if(state==2)
{
  //State 2 stop ur
   lcd.setRGB(255,0,0);
   lcd.setCursor(0,0);
   lcd.print("Stop ur");
   if(6 == HIGH)
   {
    msekunder = millis();
   }
      
      
       if(msekunder == 1000)
       {
         sekunder = sekunder+1;
         msekunder = msekunder-1000;
       }


       if(sekunder == 60)
       {
        minutter = minutter+1;
        sekunder = sekunder-60;
       }

    
      lcd.print(minutter);
      lcd.print(":");
      lcd.print(sekunder);
      lcd.print(":");
      lcd.print(msekunder);
   }
  
}
}




