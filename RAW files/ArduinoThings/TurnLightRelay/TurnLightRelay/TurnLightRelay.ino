//Relay
void setup()
{
  pinMode(8, OUTPUT);
}

//ideal turn light delay 300
void loop()
{
  digitalWrite(8, HIGH); //relay hidup
  delay(300); 
  digitalWrite(8, LOW); //matikan relay
  delay(300);
}
