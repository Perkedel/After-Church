#include<Servo.h>
const int trigPin = 7; //pin trigger
const int echoPin = 6; //pin echo
Servo aServo;
long duration;
int distance;
int potVal;
int servoOut = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  aServo.attach(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Clears pin trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //set pin trigger selama 10 microsecond
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //membaca jarak yang dihasilkan
  duration = pulseIn(echoPin, HIGH);
  //memperkirakan jarak
  distance= (duration*0.034)/2;
  //tampilkan diserial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  servoOut = map(distance, 1, 20, 0, 180);
  aServo.write(servoOut);
  delay(15);
}
