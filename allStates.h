#include "rgb_lcd.h"
#include "DS1307.h";
#include <Wire.h>
DS1307 clock;

//Tillader farveskifte
rgb_lcd lcd;



//variables for state 2
  long milSekunder = 0;
  int sekunder = 0;
  int minutter = 0;

  int knapValue2 = 0;
  int knapState2 = 0;
  bool buttonHasBeenPressed2 = false;
  long startTime=0;

//variables for state 3
  unsigned long dinTid=0;
  unsigned long startTid=0;
  unsigned long randomTid=0;

  int knapValue3 = 0;
  int knapState3 = 0;
  bool buttonHasBeenPressed3 = false;

//Variables for state 4
  int knapValue4 = 0;
  int knapState4 = 0;
  bool buttonHasBeenPressed4 = false;

  int minutter4=0;
  int sekunder4=0;

  long startTid4=0;
  long milSekunder4=0;

void StopUr()
{
  knapValue2 = digitalRead(8);

  if (knapValue2==HIGH && !buttonHasBeenPressed2)
  {
    knapState2 = knapState2 + 1;
    buttonHasBeenPressed2 = true;
  }

  if (knapValue2==LOW)
  {
    buttonHasBeenPressed2 = false;
  }

  if(knapState2==0)
  {  
    startTime=millis();  
    sekunder=0;
    minutter=0;
  }

  if(knapState2==1)
  {
    milSekunder=millis()-startTime;
    sekunder=(milSekunder/1000);
    minutter = milSekunder/60000; 

    if (sekunder >=59)
    { 
     sekunder=sekunder-(minutter*60);
    } 
  }

  if(knapState2==2)
  {
    milSekunder=milSekunder;
  }

  if(knapState2==3)
  {
  knapState2=0;
  }

// Display setup
lcd.setCursor(0,0);
lcd.setRGB(50,15,50);
lcd.print("Stop Ur   ");

lcd.print(minutter);
lcd.print(":");
lcd.print(sekunder);
lcd.print("    ");

    lcd.setCursor(0,1);
    lcd.print("                ");
}

void GaetTid()
{
  knapValue3 = digitalRead(8);

    if (knapValue3==HIGH && !buttonHasBeenPressed3)
  {
    knapState3 = knapState3 + 1;
    buttonHasBeenPressed3 = true;
  }

  if (knapValue3==LOW)
  {
    buttonHasBeenPressed3 = false;
  }
 
 lcd.setRGB(10,15,80);
  if(knapState3==0)
  {
    lcd.setCursor(0,0);
    lcd.print("Gaet tid");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print("                ");

    dinTid=0;
    randomTid=0;
  }

  if(knapState3==1)
  {
    startTid=millis();

    lcd.setCursor(0,0);
    lcd.print("Gaet tid");
    lcd.setCursor(12,0);
    lcd.print(randomTid);
    lcd.setCursor(0,1);
    lcd.print("                ");

    if(buttonHasBeenPressed3)
    {
      randomTid=random(1,9);
    }
  }

  if(knapState3==2)
  {
    lcd.setCursor(0,0);
    lcd.print("Gaet tid");
    lcd.setCursor(12,0);
    lcd.print(randomTid);
    lcd.setCursor(0,1);
    lcd.print("Running...");
    lcd.print("                ");

    dinTid=(millis()-startTid)/1000;
  }

  if(knapState3==3)
  {
    lcd.setCursor(0,0);
    lcd.print("Gaet tid");
    lcd.setCursor(12,0);
    lcd.print(randomTid);

    lcd.setCursor(0,1);
    lcd.print("Din tid:   ");

    lcd.setCursor(12,1);
    lcd.print(dinTid);
    lcd.print("                ");
  }

  if(knapState3==4)
  {
    knapState3=0;
  }
}



void KogAeg() {
  // put your main code here, to run repeatedly:
  knapValue4 = digitalRead(8);

  if (knapValue4==HIGH && !buttonHasBeenPressed4)
  {
    knapState4 = knapState4 + 1;
    buttonHasBeenPressed4 = true;
  }

  if (knapValue4==LOW)
  {
    buttonHasBeenPressed4 = false;
  }

  if (knapState4==0)
{
      lcd.setRGB(40,60,180);
    lcd.setCursor(0,0);
    lcd.print("Kog aeg");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print("                ");
}

  if (knapState4==1)
{
      lcd.setRGB(40,60,180);
    lcd.setCursor(0,0);
    lcd.print("Bloed kogt aeg");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print("                ");
}

  if (knapState4==2)
{
      lcd.setRGB(40,60,180);
    lcd.setCursor(0,0);
    lcd.print("Bloed kogt aeg");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print("5 minutter                ");  
    
    startTid4=millis();
}

  if (knapState4==3)
{

milSekunder4=millis()-startTid4;
  sekunder4=milSekunder4/1000;
  minutter4=sekunder4/60;

    if (sekunder4 >=59)
    { 
     sekunder4=sekunder4-(minutter4*60);
    } 

    if (milSekunder4>=300000)
    {
      minutter4=5;
      sekunder4=0;

      digitalWrite(7, HIGH);
    }



    if(sekunder4<10)
{
    lcd.setCursor(0,1);
    lcd.print(minutter4);
    lcd.print(":");
    lcd.print("0");
    lcd.print(sekunder4);
    lcd.print("                ");
}    



      lcd.setRGB(40,60,180);
    lcd.setCursor(0,0);
    lcd.print("Bloed kogt aeg");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print(minutter4);
    lcd.print(":");
    lcd.print(sekunder4);
    lcd.print("                ");

   
}
 Serial.println(sekunder4);
  if (knapState4==4)
{
      lcd.setRGB(40,60,180);
    lcd.setCursor(0,0);
    lcd.print("Haard kogt aeg");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print("                ");

digitalWrite(7, LOW);
milSekunder4=0;
startTid4=0;

}

  if (knapState4==5)
{
      lcd.setRGB(40,60,180);
    lcd.setCursor(0,0);
    lcd.print("Haard kogt aeg");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print("10 minutter                ");
        startTid4=millis();
}

  if (knapState4==6)
{

  milSekunder4=millis()-startTid4;
  sekunder4=milSekunder4/1000;
  minutter4=sekunder4/60;

      if (sekunder4 >=59)
    { 
     sekunder4=sekunder4-(minutter4*60);
    } 

    if (milSekunder4>=600000)
    {
      minutter4=10;
      sekunder4=0;

digitalWrite(7, HIGH);
    }

    if(sekunder4<10)
{
    lcd.setCursor(0,1);
    lcd.print(minutter4);
    lcd.print(":");
    lcd.print("0");
    lcd.print(sekunder4);
    lcd.print("                ");
}   

    lcd.setRGB(40,60,180);
    lcd.setCursor(0,0);
    lcd.print("Haard kogt aeg");
    lcd.print("                ");

    lcd.setCursor(0,1);
    lcd.print(minutter4);
    lcd.print(":");
    lcd.print(sekunder4);
    lcd.print("                ");
}

  if (knapState4==7)
{
  milSekunder4=0;
startTid4=0;
digitalWrite(7, LOW);
knapState4=0;
}

}

void Ur()
{
  clock.getTime();
  lcd.setCursor(0,0);
  if(clock.hour<10)
  {
    lcd.print("    0");
    lcd.print(clock.hour);
  }
  else
    {   
    lcd.print("    ");
    lcd.print(clock.hour);
    }

    if(clock.minute<10)
  {
    lcd.print(":");
    lcd.print("0");
    lcd.print(clock.minute);
  }
  else
    {   
         lcd.print(":");
    lcd.print(clock.minute);
    }

        if(clock.second<10)
  {
    lcd.print(":");
    lcd.print("0");
    lcd.print(clock.second);
  }
  else
    {   
         lcd.print(":");
    lcd.print(clock.second);
    }

lcd.setCursor(3,1);
    if(clock.dayOfMonth<10)
  {

    lcd.print("0");
    lcd.print(clock.dayOfMonth);
  }
  else
    {   

    lcd.print(clock.dayOfMonth);
    }

     if(clock.month<10)
  {
    lcd.print(":");
    lcd.print("0");
    lcd.print(clock.month);
  }
  else
    {   
         lcd.print(":");
    lcd.print(clock.month);
    }
       lcd.print(":");
    lcd.print(clock.year+2000);
}