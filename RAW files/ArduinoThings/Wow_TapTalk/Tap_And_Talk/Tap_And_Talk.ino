/*

Reports a tone the number of times a speaker is tapped
Speaker is connected between A0 and ground
Don't push the speaker too hard!!
Add a potentiometer for setting the threshold pulse from speaker
A piezo disk can be used with a 10k resistor in parallel with the disk
the threshold signal must be adjusted for a disk and you can tape
it to a table or box to help it sound louder
Created by Dorian McIntire - dorianmc@gmail.com

Blog: https://arduinostem.blogspot.com/2017/08/tone-tap-count.html
YouTube: https://www.youtube.com/watch?v=4fccen3ahDY&t=11s

improved by JOELwindows7 to add 16x2 LCD

*/
// include the library code:
#include <LiquidCrystal.h>

//#define is8bit;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

#ifdef is8bit
const int rs = 12, en = 11, d0 =9, d1 = 8, d2= 7, d3 = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2 , displayLamp = 10;
LiquidCrystal lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7);
#else
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2 , displayLamp = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#endif

byte PerkedelLogo[] = {
  B00000,
  B01110,
  B10001,
  B10101,
  B11111,
  B10101,
  B10001,
  B01110
};

byte SpeakerIcon[] = {
  B00001,
  B00011,
  B00101,
  B11001,
  B11001,
  B00101,
  B00011,
  B00001
};

byte SpeakerDeflate[] = {
  B00000,
  B00010,
  B00110,
  B11010,
  B11010,
  B00110,
  B00010,
  B00000
};

byte SpeakerPress[] = {
  B00000,
  B00000,
  B00100,
  B11100,
  B11100,
  B00100,
  B00000,
  B00000
};

byte TurnDown[] = {
  B00000,
  B11100,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100
};

byte Empty[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte tapCount = 0;
unsigned int tapCountInt = 0;
bool hadTapped = false;
long int tapTime = millis();
long int timeIsLeft = 0;
long int timeIsLeftDisplay = 0;
long int predictedMillis = 0;
int toneFreqRightNow = 0;

//Parameter
int sensitivity = 10; //default = 40
int toneFreqMin = 10; //default = 1500
int toneFreqMax = 2000;
long int LCDLampTimeout = 10000;
long int ScreenSaverTimeout = 5000; bool ScreenSaverTimeoutStarted = false; long int catchScreenSaverTimeout = 0;

bool enableScreenSaver = false;
long int catchTimer = 0;
long int subCatchTimer = 0; bool subCaughtTimer = false;
long int landTimer = 0; bool timeLanded = false;
long int subLandTimer = 0; bool subTimeLanded = false;
int frameKey = 0;
int subFrameKey = 0;
bool walkNotFreeze = true;
long int frozenCatchTime = 0;
bool hasBeenFrozen = true;
int fakeCounter = 0;
void demo(){
  //lcd.clear();
  if(frameKey == 0){
    if(!timeLanded) {
      lcd.clear();
      landTimer = millis();
      walkNotFreeze = true;
      timeLanded = true;
    }
    lcd.setCursor(0,0);
    lcd.print("Ketuk Speaker");
    lcd.setCursor(15,0);
    lcd.write(4);
    if(walkNotFreeze){
      if(subFrameKey == 0){
        if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
       lcd.setCursor(0,1);
       lcd.print(String("Taps: " + String(fakeCounter) + " (" + String(400) + "ms)")); 
       lcd.setCursor(15,1); lcd.write(2);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          //fakeCounter++;
          subFrameKey++;
       }
     }
      if(subFrameKey == 1){
        if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
       lcd.setCursor(0,1);
       lcd.print(String("Taps: " + String(fakeCounter) + " (" + String(400) + "ms)")); 
       lcd.setCursor(15,1); lcd.write(3);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          fakeCounter++;
          subFrameKey--;
        }
      }
      if(fakeCounter >= 4){
        walkNotFreeze = false;
      }
    } else {
      if(!hasBeenFrozen){
        frozenCatchTime = millis();
        hasBeenFrozen = true;
      } else {
        if(frozenCatchTime < (millis() - 1000)){
          subCaughtTimer = false;
          subFrameKey = 0;
          timeLanded = false;
          walkNotFreeze = true;
          frameKey++;
        }
      }
    }
  }
  if(frameKey == 1){
    if(!timeLanded) {
      lcd.clear();
      landTimer = millis();
      walkNotFreeze = true;
      timeLanded = true;
    }
    lcd.setCursor(0,0);
    lcd.print("Dapat Bunyi");
    if(walkNotFreeze){
      if(subFrameKey == 0){
        if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
        lcd.setCursor(0,1);
        lcd.print(String("BEEP: " + String(fakeCounter) + " (" + String(432) + "Hz)")); 
        lcd.setCursor(15,1); lcd.write(2);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          //fakeCounter--;
          subFrameKey++;
       }
     }
      if(subFrameKey == 1){
       if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
       lcd.setCursor(0,1);
       lcd.print(String("    : " + String(fakeCounter) + " (" + String(432) + "Hz)")); 
       lcd.setCursor(15,1); lcd.write(1);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          fakeCounter--;
          subFrameKey--;
        }
      }
      if(fakeCounter <= 0){
        walkNotFreeze = false;
      }
    } else {
      if(!hasBeenFrozen){
        frozenCatchTime = millis();
        hasBeenFrozen = true;
      } else {
        if(frozenCatchTime < (millis() - 1000)){
          subCaughtTimer = false;
          subFrameKey = 0;
          timeLanded = false;
          walkNotFreeze = true;
          frameKey++;
        }
      }
    } 
  }
  if(frameKey == 2){
    if(!timeLanded) {
      lcd.clear();
      landTimer = millis();
      walkNotFreeze = true;
      timeLanded = true;
    }
    lcd.setCursor(0,0);
    lcd.print("Tap Speaker");
    lcd.setCursor(15,0);
    lcd.write(4);
    if(walkNotFreeze){
      if(subFrameKey == 0){
        if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
       lcd.setCursor(0,1);
       lcd.print(String("Taps: " + String(fakeCounter) + " (" + String(400) + "ms)")); 
       lcd.setCursor(15,1); lcd.write(2);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          //fakeCounter++;
          subFrameKey++;
       }
     }
      if(subFrameKey == 1){
        if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
       lcd.setCursor(0,1);
       lcd.print(String("Taps: " + String(fakeCounter) + " (" + String(400) + "ms)")); 
       lcd.setCursor(15,1); lcd.write(3);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          fakeCounter++;
          subFrameKey--;
        }
      }
      if(fakeCounter >= 4){
        walkNotFreeze = false;
      }
    } else {
      if(!hasBeenFrozen){
        frozenCatchTime = millis();
        hasBeenFrozen = true;
      } else {
        if(frozenCatchTime < (millis() - 1000)){
          subCaughtTimer = false;
          subFrameKey = 0;
          timeLanded = false;
          walkNotFreeze = true;
          frameKey++;
        }
      }
    }
  }
  if(frameKey == 3){
    if(!timeLanded) {
      lcd.clear();
      landTimer = millis();
      walkNotFreeze = true;
      timeLanded = true;
    }
    lcd.setCursor(0,0);
    lcd.print("To Get Sound");
    if(walkNotFreeze){
      if(subFrameKey == 0){
        if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
        lcd.setCursor(0,1);
        lcd.print(String("BEEP: " + String(fakeCounter) + " (" + String(432) + "Hz)")); 
        lcd.setCursor(15,1); lcd.write(2);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          //fakeCounter--;
          subFrameKey++;
       }
     }
      if(subFrameKey == 1){
       if(!subCaughtTimer){
          subCatchTimer = millis();
          subCaughtTimer = true;
        }
       lcd.setCursor(0,1);
       lcd.print(String("    : " + String(fakeCounter) + " (" + String(432) + "Hz)")); 
       lcd.setCursor(15,1); lcd.write(1);
       if(subCatchTimer < (millis() - 500)){
          subCaughtTimer = false;
          fakeCounter--;
          subFrameKey--;
        }
      }
      if(fakeCounter <= 0){
        walkNotFreeze = false;
      }
    } else {
      if(!hasBeenFrozen){
        frozenCatchTime = millis();
        hasBeenFrozen = true;
      } else {
        if(frozenCatchTime < (millis() - 1000)){
          subCaughtTimer = false;
          subFrameKey = 0;
          timeLanded = false;
          walkNotFreeze = true;
          frameKey = 0;
        }
      }
    } 
  }
}

void setup()
{
  lcd.createChar(7,PerkedelLogo);
  lcd.createChar(1,SpeakerIcon);
  lcd.createChar(2,SpeakerDeflate);
  lcd.createChar(3,SpeakerPress);
  lcd.createChar(4,TurnDown);
  lcd.createChar(5,Empty);
  pinMode(displayLamp, OUTPUT);
  analogWrite(displayLamp, 0);
  lcd.begin(16,2);
  lcd.home();
  lcd.print("Tap & Talk");
  lcd.setCursor(0,1);
  lcd.print("by Arduino Stem");
  for(int i = 0; i < 255; i++){
    analogWrite(displayLamp, i);
    delay(10);
  }
  lcd.clear();
  lcd.home();
  lcd.print("++:JOELwindows7");
  lcd.setCursor(0,1);
  lcd.write(7);
  lcd.setCursor(1,1);
  lcd.print(" Perkedel");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  enableScreenSaver = true;
}

bool hadBeeped = false;
void loop()
{
  tapCountInt = tapCount;
  bool isBeeping;
  bool willReset = false;;
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  String LineOne = String("Sensor: ");
  LineOne += String(sensorValue, DEC);
  String LineTwo = String("Taps: ");
  LineTwo += String(tapCountInt, DEC);
  LineTwo += String(" (" + String(timeIsLeftDisplay) + "ms)");
  if(!enableScreenSaver || hadTapped || willReset){
    lcd.setCursor(0,0); lcd.print(LineOne);
    lcd.setCursor(0,1); lcd.print(LineTwo);
    lcd.setCursor(15,1); lcd.write(2);
    //lcd.setCursor(0,1);
    //lcd.print("SValue: %d", sensorValue);
    //lcd.print(String("SenVal: " + sensorValue));
    //lcd.print(sensorValue);
  } else if (enableScreenSaver){
    demo();
  }

  if(sensorValue > sensitivity) //detect a tap
    {
      hadTapped = true;
      enableScreenSaver = false;
      catchScreenSaverTimeout = millis() + 99999;
      lcd.clear();
      lcd.setCursor(0,0); lcd.print(LineOne);
      lcd.setCursor(0,1); lcd.print(LineTwo);
      analogWrite(displayLamp, 255);
      delay(70);
      tapCount = tapCount + 1; //increment tap count
      lcd.setCursor(15,1); lcd.write(3);
      tapTime = millis(); //record current system time
      enableScreenSaver = false;
      hadTapped = true;
    }
  predictedMillis = tapTime + 400;
  timeIsLeft = predictedMillis - millis();
  if(timeIsLeft > 0 ) {
    //enableScreenSaver = false;
    timeIsLeftDisplay = timeIsLeft;
  } else timeIsLeftDisplay = 0;

  if(!enableScreenSaver || hadTapped || willReset){
    lcd.setCursor(0,0); lcd.print(LineOne);
    lcd.setCursor(0,1); lcd.print(LineTwo);
    lcd.setCursor(15,1); lcd.write(2);
  } else if (enableScreenSaver) {
    demo();
  }
  
  if(tapTime < (millis() - 400)) //if more than 0.4 seconds have elapsed since last tap
  {
    for(int x=0; x < tapCount; x++)
      { 
        enableScreenSaver = false;
        analogWrite(displayLamp, 100);
        lcd.clear();
        lcd.setCursor(0,0); lcd.print(LineOne);
        isBeeping = true;
        willReset = true;
        digitalWrite(LED_BUILTIN, HIGH);
        pinMode(A0,OUTPUT);
        toneFreqRightNow = random(toneFreqMin, toneFreqMax);
        tone(A0, toneFreqRightNow);
        //lcd.setCursor(12,0);
        //lcd.print("BEEP");
        analogWrite(displayLamp, 255);
        lcd.setCursor(0,1);
        lcd.print(String("BEEP: " + String(tapCount - x) + " (" + String(toneFreqRightNow) + "Hz)"));
        lcd.setCursor(15,1);
        lcd.write(1);
        delay(200);
        noTone(A0);
        //lcd.setCursor(12,0);
        //lcd.print("    ");
        analogWrite(displayLamp, 100);
        lcd.setCursor(0,1);
        lcd.print(String("    : " + String(tapCount - x)));
        lcd.setCursor(15,1);
        lcd.write(2);
        delay(200);
        pinMode(A0,INPUT);
        if(x >= tapCount-1){
          hadTapped = true;
          enableScreenSaver = false;
          hadBeeped = true;
          isBeeping = false;
          analogWrite(displayLamp, 255);
        }
      }
    //lcd.clear();
    tapCount = 0;
  }

  if(tapTime < (millis() - LCDLampTimeout)){
    analogWrite(displayLamp, 100);
    hadTapped = false;
    enableScreenSaver = true;
  }

  if(hadBeeped){
    //enableScreenSaver = false;
    if(!ScreenSaverTimeoutStarted){
      //hadTapped = false;
      catchScreenSaverTimeout = millis();
      ScreenSaverTimeoutStarted = true;
    }
    //enableScreenSaver = false;
  }

  if(hadTapped){
    if(ScreenSaverTimeoutStarted){
      if(catchScreenSaverTimeout < (millis() - ScreenSaverTimeout)){
        hadTapped = false;
        enableScreenSaver = true;
        hadBeeped = false;
        enableScreenSaver = true;
        ScreenSaverTimeoutStarted = false;
        catchScreenSaverTimeout = 0;
      }
    }
  }

  
  if(isBeeping) digitalWrite(LED_BUILTIN, HIGH); else{ 
    digitalWrite(LED_BUILTIN, LOW);
  }

  if(!enableScreenSaver || hadTapped || willReset){
    lcd.setCursor(0,0); lcd.print(LineOne);
    lcd.setCursor(0,1); lcd.print(LineTwo);
    lcd.setCursor(15,1); lcd.write(2);
  } else if (enableScreenSaver) {
    demo();
  }

  Serial.println(String(String(enableScreenSaver) + " " + String(hadTapped) + " " + String(willReset)));
  delay(5); // delay in between reads for stability
  if(willReset) {
    lcd.clear();
    //enableScreenSaver = false;
    hadTapped = true;
    willReset = false;
  }
} //loop
