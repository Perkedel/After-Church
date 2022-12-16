LiquidCrystal_I2C lcd(0x27,16,2);
int karakter = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print(karakter);
}
