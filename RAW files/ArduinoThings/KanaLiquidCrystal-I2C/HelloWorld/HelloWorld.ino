// HelloWorld.ino
//
// このスケッチはKanaLiquidCrystalライブラリの使い方を説明するための物です
// スイッチサイエンスで発売しているLCDシールドキット(緑)でこのスケッチがそのまま動きます。
// 購入ページ:http://www.switch-science.com/catalog/724/
// 他の液晶でも、LiquidCrystalライブラリで使える液晶は、全て使えます。(ピン接続の宣言のみ
// 手直しが必要)

#include <KanaLiquidCrystal.h> // この#includeで、KanaLiquidCrystalライブラリを呼び出します。
#include <LiquidCrystal_I2C.h> // LiquidCrystalライブラリも間接的に使うので、この#includeも必要です

// 使用するピンを指定します。指定の方法はLiquidCrystalライブラリと同様です。
// LCDのRS    ピン → Arduinoの12番ピン(第1引数)
// LCDのEnableピン → Arduinoの11番ピン(第2引数)
// LCDのD4    ピン → Arduinoの 5番ピン(第3引数)
// LCDのD5    ピン → Arduinoの 4番ピン(第4引数)
// LCDのD6    ピン → Arduinoの 3番ピン(第5引数)
// LCDのD7    ピン → Arduinoの 2番ピン(第6引数)
// LCDのR/W   ピン → GND
// LCDのVO    ピン → 10kΩの可変抵抗の真ん中のピン
// 10kΩの可変抵抗の両端のピン → 5VとGND
KanaLiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2); // 横16桁、縦2行のディスプレイを使うことを宣言します。
  lcd.setCursor(0,0); // 1行目の行頭にカーソルを移動します。
  lcd.print("ｺﾝﾆﾁﾊ"); // 試しに半角カナを表示すると、文字化けするはずです。
  lcd.setCursor(0,1); // 2行目の行頭にカーソルを移動します。
  lcd.kanaOn(); // この行を実行して以降、半角カナは文字化けせずに表示されます。
  lcd.print("ｺﾝﾆﾁﾊ"); // 文字化けせずにｺﾝﾆﾁﾊと表示されます。
}

void loop()
{
}
