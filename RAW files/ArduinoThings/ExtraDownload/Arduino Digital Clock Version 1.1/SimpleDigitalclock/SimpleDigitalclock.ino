#include <LiquidCrystal.h>
#include "TimerOne.h"
#define btnRIGHT  1
#define btnUP     2
#define btnDOWN   3
#define btnLEFT   4
#define btnSELECT 5
#define btnNONE   0
int btnSelected = 0;
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int lcd_key     = 0;
int adc_key_in0  = 0;
int adc_key_in1  = 0;
int adc_key_in2  = 0;
int adc_key_in3  = 0;
int adc_key_in4  = 0;
int adc_key_in5  = 0;
int thesec = 0;
int thesec2 = 0;
int themin = 0;
int themin2 = 0;
int thehr = 1;
int thehr2 = 0;
bool backlightstatus = true;
bool semicol = true;
bool ampm = true;


void setup() {
  //initialize serial port
  Serial.begin(9600);
  //initialize the custom characters
  lcdcharinitiate();
  //initiate timer1 with 1 sec delay
  Timer1.initialize(1000000);
  //add the function that will be run every 1 sec
  Timer1.attachInterrupt(thedisplayfunction);
  lcd.clear();
  theclock();
}
//checking if buuton is pressed and do its function
void loop()
{
  int theinput = read_LCD_buttons();
  if(theinput == btnRIGHT && btnSelected != btnRIGHT)
  {
    btnSelected = btnRIGHT;
    themin++;
    if(themin > 9)
    {
      themin=0;
      themin2++;
      if(themin2 > 5)
      {
        themin2 =0;
      }
    }
  }
  else if(theinput == btnLEFT && btnSelected != btnLEFT)
  {
    btnSelected = btnLEFT;
    thehr++;
          if(thehr > 9 && thehr2 == 0)
          {
            thehr = 0;
            thehr2++;
            if(thehr2 >1)
            {
              thehr2 = 0;
            }
          }
          if(thehr > 2 && thehr2 == 1)
          {
            thehr = 1;
            thehr2++;
            if(thehr2 >1)
            {
              thehr2 = 0;
              ampm=!ampm;
            }
          }
  }
  else if(theinput == btnSELECT && btnSelected != btnSELECT)
  {
    btnSelected = btnSELECT;
    backlightstatus = !backlightstatus;
    if(backlightstatus)
    {
        digitalWrite(10,LOW);  
    }
    else
    {
        digitalWrite(10,HIGH);
    }
  }
  else if(theinput == btnNONE && btnSelected != btnNONE)
  {
    btnSelected = btnNONE;
  }
  delay(200);
}
//get which button is pressed
int read_LCD_buttons()
{
  adc_key_in0 = analogRead(0);      // read the value from the sensor
  // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
  // we add approx 50 to those values and check to see if we are close
  if (adc_key_in0 > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
  if (adc_key_in0 < 50)   return btnRIGHT;
  if (adc_key_in0 < 150)  return btnUP;
  if (adc_key_in0 < 300)  return btnDOWN;
  if (adc_key_in0 < 450)  return btnLEFT;
  if (adc_key_in0 < 700)  return btnSELECT;
  return btnNONE;  // when all others fail, return this...
}
//the clock timer call function
void thedisplayfunction()
{ 
  semicol=!semicol;
  thesec++;
  if(thesec > 9)
  {
    thesec=0;
    thesec2++;
    if(thesec2 > 5)
    {
      thesec2 = 0;
      themin++;
      if(themin > 9)
      {
        themin=0;
        themin2++;
        if(themin2 > 5)
        {
          themin2 =0;
          thehr++;
          if(thehr > 9 && thehr2 == 0)
          {
            thehr = 0;
            thehr2++;
            if(thehr2 >1)
            {
              thehr2 = 0;
            }
          }
          if(thehr > 2 && thehr2 == 1)
          {
            thehr = 1;
            thehr2++;
            if(thehr2 >1)
            {
              thehr2 = 0;
              ampm=!ampm;
            }
          }
        }
      }
    }
  }
  theclock();
}
//print the value of the varaiable in its position
void theclock()
{
  numberprinter(themin,12);
  numberprinter(themin2,8);
  numberprinter(thehr,4);
  numberprinter(thehr2,0);
  if(ampm)
  {
    lcdam(15);
  }
  else
  {
    lcdpm(15);
  }
  if(semicol)
  {
    lcdnumbersemicolon(7);
  }
  else
  {
    lcdnumbersemicolonoff(7);
  }
}
//find the needed characer and added it to the needed position
void numberprinter(int num , int pos)
{
  if(num == 0)
  {
    lcdnumber0(pos);
  }
  if(num == 1)
  {
    lcdnumber1(pos);
  }
  if(num == 2)
  {
    lcdnumber2(pos);
  }
  if(num == 3)
  {
    lcdnumber3(pos);
  }
  if(num == 4)
  {
    lcdnumber4(pos);
  }
  if(num == 5)
  {
    lcdnumber5(pos);
  }
  if(num == 6)
  {
    lcdnumber6(pos);
  }
  if(num == 7)
  {
    lcdnumber7(pos);
  }
  if(num == 8)
  {
    lcdnumber8(pos);
  }
  if(num == 9)
  {
    lcdnumber9(pos);
  }
}
//initiate the lcd custom charcters
void lcdcharinitiate()
{
    byte C0[8] = {0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00};
    byte C1[8] = {0x1F,0x1F,0x1F,0x00,0x00,0x1F,0x1F,0x1F};
    byte C2[8] = {0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F};
    byte C3[8] = {0x00,0x00,0x0E,0x0A,0x0A,0x0E,0x00,0x00};
    
    lcd.createChar(0 , C0);
    lcd.createChar(1 , C1);
    lcd.createChar(2 , C2);
    lcd.createChar(3 , C3);
    lcd.begin(16 , 2);

}
//lcd draw character functions
void lcdnumber0(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(2));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumber1(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(2));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(255));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(2));
}
void lcdnumber2(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(2));
}
void lcdnumber3(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(1));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumber4(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(2));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(32));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(32));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumber5(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(2));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(2));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumber6(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumber7(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(32));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(0));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumber8(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumber9(int startposition)
{
    lcd.setCursor(startposition+0,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+1,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition+2,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition+0,1);
    lcd.write(byte(2));
    lcd.setCursor(startposition+1,1);
    lcd.write(byte(2));
    lcd.setCursor(startposition+2,1);
    lcd.write(byte(255));
}
void lcdnumbersemicolon(int startposition)
{
  lcd.setCursor(startposition+0,0);
  lcd.write(byte(3));
  lcd.setCursor(startposition+0,1);
  lcd.write(byte(3));
}
void lcdnumbersemicolonoff(int startposition)
{
  lcd.setCursor(startposition+0,0);
  lcd.write(byte(32));
  lcd.setCursor(startposition+0,1);
  lcd.write(byte(32));
}
void lcdam(int startposition)
{
  lcd.setCursor(startposition+0,0);
  lcd.write(byte(97));
  lcd.setCursor(startposition+0,1);
  lcd.write(byte(109));
}
void lcdpm(int startposition)
{
  lcd.setCursor(startposition+0,0);
  lcd.write(byte(112));
  lcd.setCursor(startposition+0,1);
  lcd.write(byte(109));
}
//the function recive time from pc bye the application using serial

void serialEvent() {
  while (Serial.available()) {
    // get the stringdate:
    String thetime = Serial.readString();
    if(thetime[6] == 'A')
    {
      ampm = true;
    }
    else
    {
      ampm = false;
    }
    thesec = (int)thetime[5]-48;
    thesec2 = (int)thetime[4]-48;
    themin = (int)thetime[3]-48;
    themin2 = (int)thetime[2]-48;
    thehr = (int)thetime[1]-48;
    thehr2 = (int)thetime[0]-48;
  }
}
