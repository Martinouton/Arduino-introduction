#include <LiquidCrystal.h>

int rs = 5;
int en = 6;
int d4 = 7;
int d5 = 8;
int d6 = 9;
int d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int echoPin = 12;
int trigPin = 13;

float duration;
float distance;

int buttonPin = 3;
int buttonState;
int buttonStateOld = 0;
int first = 1;
int time = 0;

int dt = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(first){
    first = 0;
    lcd.setCursor(0,0);
    lcd.print("Waiting for");
    lcd.setCursor(0,1);
    lcd.print("pressed button.");
  }
  buttonState = digitalRead(buttonPin);
  if(buttonState == 0 & buttonStateOld == 1){
    lcd.clear();
    digitalWrite(trigPin,LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.0343/2;

    Serial.print(0);
    Serial.print(distance);
    Serial.println(10);

    time = time + 1;
    lcd.setCursor(0,0);
    lcd.print(time);
    lcd.print("º distance:");
    lcd.setCursor(0,1);
    lcd.print(distance); 
    lcd.print(" cm.");

    delay(dt);
  }
  buttonStateOld = buttonState;
  delay(dt);
}
