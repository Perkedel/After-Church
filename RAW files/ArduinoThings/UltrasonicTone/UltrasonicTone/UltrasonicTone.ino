const int trigPin = 6; //pin trigger
const int echoPin = 5; //pin echo
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(trigPin, random(432,1000));
  delay(1000);
}
