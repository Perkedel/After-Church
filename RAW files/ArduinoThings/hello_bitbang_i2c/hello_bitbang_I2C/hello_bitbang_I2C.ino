// BitBang I2C je oko 10% manji .hex od tinywire
// Promena SDA i SCL pinova jedino direktno u LiquidCrystal_I2C_BitBang.cpp
// ATTINY 85
// SDA 0
// SCL 2
// ATTINY 841 - Ne koristiti 841 hardware I2C slave pinove PA6(SDA) i PA4(SCL) za bitbang I2C Master ( verovatno bug u 841 core - proveriti )
// SDA PA7
// SCL PA3
// ATTMEGA 328
// SDA 3
// SCL 5

#include <LiquidCrystal_I2C_BitBang.h>   // for LCD w/ GPIO MODIFIED for the ATtiny85
#define GPIO_ADDR     0x27             // (PCA8574A A0-A2 @5V) typ. A0-A3 Gnd 0x20 / 0x38 for A - 0x27 is the address of the Digispark LCD modules.
//#define __AVR_ATmega328P__

LiquidCrystal_I2C_BitBang lcd(GPIO_ADDR,16,2);  // set address & 16 chars / 2 lines

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Fogg BitBangI2C");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
}
