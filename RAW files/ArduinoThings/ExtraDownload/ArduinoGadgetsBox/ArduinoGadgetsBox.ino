#include <LiquidCrystal.h>
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
//youtube subs counter
String YouCounter = "0";
void setup() {
  //initalize serial port
  Serial.begin(9600);
  //initalize the lcd
  lcd.begin(16 , 2);
  // youtube gadget
  DrawYoutube();
}

void loop() {
 
}

//draw youtube logo
void DrawYoutube()
{
  //initiate custom char for youtube
  youtubelcdcharinitiate();
  //print youtube logo
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(0,1);
  lcd.write(byte(1));
  lcd.setCursor(1,0);
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(2,0);
  lcd.write(byte(4));
  lcd.setCursor(2,1);
  lcd.write(byte(5));
  lcd.setCursor(3,0);
  lcd.write(byte(6));
  lcd.setCursor(3,1);
  lcd.write(byte(7));
  // subscrribers text
  lcd.setCursor(5,0);
  lcd.write("Subscribers");
  //clear previous number
  lcd.setCursor(5,1);
  lcd.print("           ");
  //count
  lcd.setCursor(5,1);
  lcd.print(YouCounter);
}
//initiate the lcd custom charcters For Youtube Icon
void youtubelcdcharinitiate()
{
    //number 0 charaters 2x2 decimals
    byte C0[8] = {0x03,0x07,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F};
    byte C1[8] = {0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x07,0x03};
    byte C2[8] = {0x1F,0x1F,0x1B,0x19,0x18,0x18,0x18,0x18};
    byte C3[8] = {0x18,0x18,0x18,0x18,0x19,0x1B,0x1F,0x1F};
    byte C4[8] = {0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x07,0x03};
    byte C5[8] = {0x03,0x07,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F};
    byte C6[8] = {0x18,0x1C,0x1E,0x1F,0x1F,0x1F,0x1F,0x1F};
    byte C7[8] = {0x1F,0x1F,0x1F,0x1F,0x1F,0x1E,0x1C,0x18};
    
    lcd.createChar(0 , C0);
    lcd.createChar(1 , C1);
    lcd.createChar(2 , C2);
    lcd.createChar(3 , C3);
    lcd.createChar(4 , C4);
    lcd.createChar(5 , C5);
    lcd.createChar(6 , C6);
    lcd.createChar(7 , C7);
}
void serialEvent() {
  while (Serial.available()) {
    // get the data:
    YouCounter = Serial.readString();
  }
  // youtube gadget
  DrawYoutube();
}
