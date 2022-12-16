#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include<stdio.h>
#include<string.h>
#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif
LiquidCrystal_I2C lcd(0x27,16,2);

//link:
//https://synapse.kyoto/lib/KanaLiquidCrystal/page001.html , Download Library KanaLCD, WARNING: raw pinout only, no i2c support yet.

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight(); //turn on LCD backlight

  //lcd.print("Hello ｺﾝﾆﾁﾊ"); //Uncommon Japanese devoted LCD, This code is not compatible with Standard LCD.
  //lcd.rightToLeft(); lcd.setCursor(15,0); //to do RTL, its cursor start position moves left. So if you set cursor 0,0 , it will move left after print char!
  lcd.leftToRight();
  lcd.print("Hello \xba\xdd\xc6\xc1\xca \xf4"); //Common Standard LCD, This code makes Standard LCD prints actual Japanese Character.

  lcd.setCursor(15,1);
  lcd.rightToLeft();
  lcd.print("Hello \xba\xdd\xc6\xc1\xca \xf4");
  //lcd.cursor();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  lcd.noDisplay();
  delay(5000);
  lcd.display();
  delay(5000);
  lcd.setBacklight(0);
  delay(5000);
  lcd.setBacklight(1);
  delay(5000);
  lcd.cursor();
  delay(5000);
  lcd.blink();
  delay(5000);
  lcd.noCursor();
  delay(5000);
  lcd.noBlink();
}
