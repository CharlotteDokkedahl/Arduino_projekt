//inkludere encoder og rgb display
#include <Encoder.h>
#include "rgb_lcd.h"
#include "allStates.h"



//Opsætter encoder
Encoder encoder(2, 3);



//Opretter varriabler
int encoderCount=1;
int state=1;
int stateAmount=5;

void setup() 
{
  clock.begin();
  
  Wire.begin();

    //Tænder display
    lcd.begin(16, 2);

    //Tænder knap
    pinMode(8,INPUT);

    //Tænder bipper
    pinMode(7,OUTPUT);
    
    //Opsætter start
    encoder.write(4);

    Serial.begin(9600);

    
}


void loop() 
{
  //Bestemmer state
   encoderCount = encoder.read();
   state = encoderCount/4;

  if(state>5)
  {
    //Bestemmer state hvis >5
    encoder.write(4);
     encoderCount = encoder.read();
     state = encoderCount/4;
  }

  if(state<1)
  {
    //Bestemmer state hvis <0
    encoder.write(20);
     encoderCount = encoder.read();
     state = encoderCount/4;
  }

  if(state==1)
  {
    //State 1 ur
    lcd.setRGB(100,20,15);
    Ur();
  }

  if(state==2)
  {
    //State 2 stop ur
    StopUr();
  }

  if(state==3)
  {
    //State 3 gæt tid
    GaetTid();
  }

  if(state==4)
  {
    //state 4 kog æg  

KogAeg();
  }

  if(state==5)
  {
    //state 5 vækkeur
    lcd.setRGB(50,60,15);
    lcd.setCursor(0,0);
    lcd.print("Vaekke ur"); 
    lcd.print("   "); 

    lcd.setCursor(0,1);
    lcd.print("                ");
  }
}