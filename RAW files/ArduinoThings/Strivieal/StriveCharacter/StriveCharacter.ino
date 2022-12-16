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
int karakter = 0;

void displayMan(void){
  uint8_t i = 0;
  while(1){
    lcd.setCursor(0,0);
    for(int j = karakter; j < 16; j++){
      
      lcd.printByte(i+j);
    }
    i+=16;
    delay(4000);
  }
}

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(1);

  //lcd.print("アルドゥイーノ");
  lcd.print(String((char)208) + String((char)185));

  lcd.setCursor(0,1);
  
  
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,1);
  for(int o = 0; o < 16;o++){
    lcd.printByte(48+o);
  }
  displayMan();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
