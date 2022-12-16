

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(A0) == LOW){
    //Pressed Button
    digitalWrite(LED_BUILTIN, HIGH);
  } else if(digitalRead(A0) == HIGH){
    //depressed button
    digitalWrite(LED_BUILTIN, LOW);
  }
}
