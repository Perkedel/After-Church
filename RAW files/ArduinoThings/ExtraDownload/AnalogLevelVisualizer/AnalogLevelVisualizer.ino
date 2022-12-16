#include <LiquidCrystal.h>
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
  // put your setup code here, to run once:
  //initialize the custom characters
  lcdcharinitiate();
  //Loading Basic Screen
  LoadFirstScreen();
}
void loop() {
  // put your main code here, to run repeatedly:
  //start the visualization
  StartVisualization();
}
//initiate the lcd custom charcters
void lcdcharinitiate()
{
    byte C0[8] = {0x00,0x1F,0x00,0x1F,0x00,0x1F,0x00,0x1F};
    byte C1[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F};
    byte C2[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F};
    byte C3[8] = {0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F};
    byte C4[8] = {0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F};
    byte C5[8] = {0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F};
    byte C6[8] = {0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
    byte C7[8] = {0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
    
    lcd.createChar(0 , C0);
    lcd.createChar(1 , C1);
    lcd.createChar(2 , C2);
    lcd.createChar(3 , C3);
    lcd.createChar(4 , C4);
    lcd.createChar(5 , C5);
    lcd.createChar(6 , C6);
    lcd.createChar(7 , C7);

    lcd.begin(16 , 2);

}
//load first screen view
void LoadFirstScreen()
{
  //lcdlevelsmeter(1);
  lcdah(9);
  lcdal(9);
  lcdmax(7);
  lcdmin(7);
  
}
// this function is the core of the display wich will display the 
// values and bars
void StartVisualization()
{
  int x[6];
  int v[6];
  for(int i = 0 ; i < 6 ; i++)
  {
    v[i] = analogRead(i);
    x[i] = map(v[i], 0, 1023, 0, 16);
    levelvisualizer(x[i],i);
  }
  int themax = MaximumValue(v);
  int themin = MinimumValue(v);
  int themaxa = MaximumValueA(v);
  int themina = MinimumValueA(v);
  lcdmaxvalue(12,themax);
  lcdminvalue(12,themin);
  lcdmaxavalue(10,themaxa);
  lcdminavalue(10,themina);
}
//get maximum value
int MaximumValue(int maximum[6])
{
  int themaximum = maximum[0];
  for(int i = 1 ; i < 6 ; i++)
  {
    if(maximum[i] > themaximum)
    {
      themaximum = maximum[i];
    }
  }
  return themaximum;
}
//get maximum value analog input
int MaximumValueA(int maximum[6])
{
  int themaxi = 0;
  int themaximum = maximum[0];
  for(int i = 0 ; i < 6 ; i++)
  {
    if(maximum[i] > themaximum)
    {
      themaximum = maximum[i];
      themaxi = i;
    }
  }
  return themaxi;
}
//get minimum value
int MinimumValue(int minimum[6])
{
  int theminimum = minimum[0];
  for(int i = 1 ; i < 6 ; i++)
  {
    if(minimum[i] < theminimum)
    {
      theminimum = minimum[i];
    }
  }
  return theminimum;
}
//get minimum value analog A
int MinimumValueA(int minimum[6])
{
  int themini = 0;
  int theminimum = minimum[0];
  for(int i = 1 ; i < 6 ; i++)
  {
    if(minimum[i] < theminimum)
    {
      theminimum = minimum[i];
      themini = i;
    }
  }
  return themini;
}
//find the needed characer and added it to the needed position
void levelvisualizer(int num , int pos)
{
  if(num == 0)
  {
    lcdlevel0(pos);
  }
  if(num == 1)
  {
    lcdlevel1(pos);
  }
  if(num == 2)
  {
    lcdlevel2(pos);
  }
  if(num == 3)
  {
    lcdlevel3(pos);
  }
  if(num == 4)
  {
    lcdlevel4(pos);
  }
  if(num == 5)
  {
    lcdlevel5(pos);
  }
  if(num == 6)
  {
    lcdlevel6(pos);
  }
  if(num == 7)
  {
    lcdlevel7(pos);
  }
  if(num == 8)
  {
    lcdlevel8(pos);
  }
  if(num == 9)
  {
    lcdlevel9(pos);
  }
  if(num == 10)
  {
    lcdlevel10(pos);
  }
  if(num == 11)
  {
    lcdlevel11(pos);
  }
  if(num == 12)
  {
    lcdlevel12(pos);
  }
  if(num == 13)
  {
    lcdlevel13(pos);
  }
  if(num == 14)
  {
    lcdlevel14(pos);
  }
  if(num == 15)
  {
    lcdlevel15(pos);
  }
  if(num == 16)
  {
    lcdlevel16(pos);
  }
}

//lcd draw character functions
void lcdah(int startposition)
{
  lcd.setCursor(startposition,0);
  lcd.print("A");
}
void lcdal(int startposition)
{
  lcd.setCursor(startposition,1);
  lcd.print("A");
}
void lcdmax(int startposition)
{
  lcd.setCursor(startposition,0);
  lcd.print("H:");
}
void lcdmin(int startposition)
{
  lcd.setCursor(startposition,1);
  lcd.print("L:");
}
void lcdmaxavalue(int startposition,int thevalue)
{
  lcd.setCursor(startposition,0);
  lcd.print(String(thevalue));
}
void lcdminavalue(int startposition,int thevalue)
{
  lcd.setCursor(startposition,1);
  lcd.print(String(thevalue));
}
void lcdmaxvalue(int startposition,int thevalue)
{
  lcd.setCursor(startposition,0);
  lcd.print(String(thevalue) + "   ");
}
void lcdminvalue(int startposition,int thevalue)
{
  lcd.setCursor(startposition,1);
  lcd.print(String(thevalue) + "   ");
}
void lcdlevelsmeter(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(0));
    lcd.setCursor(startposition,1);
    lcd.write(byte(0));
}
void lcdlevel0(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(32));
}
void lcdlevel1(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(1));
}
void lcdlevel2(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(2));
}
void lcdlevel3(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(3));
}
void lcdlevel4(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(4));
}
void lcdlevel5(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(5));
}
void lcdlevel6(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(6));
}
void lcdlevel7(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(7));
}
void lcdlevel8(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(32));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel9(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(1));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel10(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(2));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel11(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(3));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel12(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(4));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel13(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(5));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel14(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(6));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel15(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(7));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
void lcdlevel16(int startposition)
{
    lcd.setCursor(startposition,0);
    lcd.write(byte(255));
    lcd.setCursor(startposition,1);
    lcd.write(byte(255));
}
