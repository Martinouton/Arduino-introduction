#include <Servo.h>
int servoPin = 8;
int readPin = A0;
int val;
int dt = 300;
float pos;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(readPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(readPin);
  Serial.println(val);
  pos = 165./700.*(val-300.);
  myServo.write(pos);  
  Serial.println(pos);
  delay(dt);
}
