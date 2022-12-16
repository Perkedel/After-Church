//ConSwitch Relay Toggle
const int relayPin = 8;
const int buttonPin = 2;

//willChange
int buttonState = 0;
bool buttonHasBeenPressed = 0;
int toggleSwitche = 0;
void setup()
{
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

//ideal turn light delay 300
void loop()
{
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH){
    if(!buttonHasBeenPressed){
      if(toggleSwitche == 0){
        toggleSwitche = 1;
      } else if(toggleSwitche == 1){
        toggleSwitche = 0;
      }
      buttonHasBeenPressed = true;
    }
  } else {

    buttonHasBeenPressed = false;
  }

  if(toggleSwitche){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(relayPin, LOW);
    
  }
}
