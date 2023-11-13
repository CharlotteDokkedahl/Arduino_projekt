//includere
#include <Encoder.h>
#include "rgb_lcd.h"

//tillader farveskifte
rgb_lcd lcd;

//Opsætter encoder
Encoder encoder(5, 6);

//Opretter varriabler
int encoderCount=1;
int state=1;
int stateAmount=5;


void setup() 
{
  //Display
  pinMode(8,OUTPUT);

    //Tænder display
    lcd.begin(16, 2);

    //Tænder knap
    pinMode(6,INPUT);
    
    //Opsætter start
    encoder.write(4);
    
}


void loop() 
{
  //Bestemmer state
  int encoderCount = encoder.read();
  int state = encoderCount/4;




if(state>5)
{
  //Bestemmer state hvis >5
    encoder.write(4);
    int encoderCount = encoder.read();
    int state = encoderCount/4;
}

if(state<0)
{
  //Bestemmer state hvis <0
    encoder.write(20);
    int encoderCount = encoder.read();
    int state = encoderCount/4;
}

if(state==1)
{
  //State 1 ur
   lcd.setRGB(255,0,0);
   lcd.setCursor(0,0);
    lcd.print("Ur");  
    lcd.print("        ");

}

if(state==2)
{
  //State 2 stop ur
   lcd.setRGB(255,0,0);
   lcd.setCursor(0,0);
   lcd.print("Stop ur");
   lcd.print("    ");
}

if(state==3)
{
  //State 3 gæt tid
   lcd.setCursor(0,0);
   lcd.print("Gaet tid");
   lcd.print("    ");
}

if(state==4)
{
   
  //state 4 kog æg  
   lcd.setRGB(255,0,0);
   lcd.setCursor(0,0);
    lcd.print("Kog aeg");
     lcd.print("    ");
}

if(state==5)
{

 //state 5 vækkeur
lcd.setCursor(0,0);
    lcd.print("Vaekke ur"); 
     lcd.print("   "); 
}

 




}