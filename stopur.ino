
#include "rgb_lcd.h"

//tillader farveskifte
rgb_lcd lcd;

int milSekunder = 0;
int sekunder = 0;
int minutter = 0;

int knapValue = 0;
int knapState = 0;

int tStart=0;
unsigned long tNyStart=0;
unsigned long milliForskel=0;

void setup() {
  // put your setup code here, to run once:

lcd.begin(16,2);

Serial.begin(9600);


pinMode(6,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
StopUr();

Serial.println(knapState);

}

void StopUr()
{

unsigned long tStart=millis();

knapValue = digitalRead(6);



if( knapValue == HIGH )
{
  knapState = knapState + 1;  

}
if(knapState>1)
{
  
  long milSekunder=millis();
sekunder=milSekunder/1000;
    minutter = millis()/60000;
   
   
   if (sekunder >=59)
    { 
     sekunder=sekunder-(minutter*60);
    }
    

}


 
      

// Display setup

lcd.setCursor(0,0);
lcd.print("Stop Ur   ");

lcd.print(minutter);
lcd.print(":");
lcd.print(sekunder);
lcd.print("    ");


}
