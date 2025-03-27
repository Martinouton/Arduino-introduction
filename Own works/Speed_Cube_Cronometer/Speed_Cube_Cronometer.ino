#include <LiquidCrystal.h>
#include <EEPROM.h>

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

unsigned long start;
unsigned long end;
unsigned long time;
unsigned long bestTime = 9999999;

int first = 1;
int nTry = 0;

int buttonPin = 3;
int buttonState;
int buttonStateOld = 0;

int redPin = 4;
int greenPin = 2;

int dt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  EEPROM.get(0, bestTime);
  if (bestTime == 0xFFFFFFFF || bestTime == 0) {
    bestTime = 9999999; // Por si está vacío
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  if(first){
    first = 0;
    lcd.setCursor(0,0);
    lcd.print("Mix the cube");
    lcd.setCursor(0,1);
    lcd.print("and place it.");
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Mix it and repeat");
    lcd.setCursor(0,1);
    lcd.print("Best time: ");
    lcd.print(bestTime);
  }
  
  delay(30*dt);
  flanco();
  Serial.println(distance);
  while(distance>10){    
    flanco();
    Serial.println(distance);
    delay(dt);
  }
    lcd.clear();
  while(distance<20){
    lcd.setCursor(0,0);
    lcd.print("Take the cube");
    lcd.setCursor(0,1);
    lcd.print("to study.");
    flanco();
  }
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);

  start = millis();
  //nTry = nTry + 1;
  lcd.clear();
  end = millis();
  while(end-start<10000){
    end = millis();
    time = 10000 - (end - start);
    lcd.setCursor(0,0);
    lcd.print("Studying cube");
    lcd.setCursor(0, 1);
    lcd.print(time/1000.0,2);
    lcd.print(" s.");
  }
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Time finished");
  lcd.setCursor(0, 1);
  lcd.print("Place it again");
  flanco();
  Serial.println(distance);
  while(distance>10){
    flanco();
    Serial.println(distance);
    delay(dt);
  }
  digitalWrite(redPin, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Are you ready");
  lcd.setCursor(0, 1);
  lcd.print("to solve it?");

  flanco();
  while(distance<10){
    flanco();
    delay(dt);
  }
  start = millis();
  lcd.clear();
  flanco();
  while(distance>10){
    end = millis();
    lcd.setCursor(0,0);
    lcd.print("Working...");
    lcd.setCursor(0, 1);
    lcd.print((end-start)/1000.0,2);
    flanco();
    delay(dt);
  }

  end = millis();
  time = end - start;
  if(time<bestTime){
    bestTime = time;
    EEPROM.put(0, bestTime);
    digitalWrite(greenPin, HIGH);
  }
  else{
    digitalWrite(redPin, HIGH);
  }
  lcd.setCursor(0,0);
  lcd.print("Best time: ");
  lcd.print(bestTime/1000.0,2);
  lcd.print(" s.");
  lcd.setCursor(0,1);
  lcd.print("Last time: ");
  lcd.print(time/1000.0,2);
  lcd.print(" s.");
  delay(5000);
  lcd.clear();   
  lcd.setCursor(0,0);
  lcd.print("Press button to");
  lcd.setCursor(0,1);
  lcd.print("delete best time"); 
  start = millis();
  end = millis();
  while((end - start)<4000){
    end = millis();
    buttonState = digitalRead(buttonPin);
    if(buttonState==0){
      bestTime=99999999;
      break;
    }
    
  }
  

}

void flanco(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);  

  duration = pulseIn(echoPin, HIGH);
  if(duration>0){ // This if is because after a measure it gives me another measure of 0.0
    distance = duration * 0.0343/2;
  }
}

