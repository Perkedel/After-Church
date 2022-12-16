int SoundPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(SoundPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(SoundPin, 100);
}
