#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String number1;
int num1;
String number2;
int num2;
int result;
String oper;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2); // 16 columns, 2 rows
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear;
  lcd.setCursor(0,0);
  lcd.print("calculator");
  lcd.setCursor(0,1);
  lcd.print("First number: ");
  while(Serial.available()==0){

  }
  number1 = Serial.readStringUntil('\n'); //To avoid let useless characters in the serial monitor
  num1 = number1.toInt();
  // while(Serial.available()){   This would be another solution to the issue explain above
  //   Serial.read();             With these lines, buffer will be cleaned
  // }
  lcd.print(num1);
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("calculator");
  lcd.setCursor(0,1);
  lcd.print("Operator: ");
  while(Serial.available()==0){

  }
  oper = Serial.readStringUntil('\n');
  oper.trim(); // Remove unwanted spaces
  lcd.print(oper);
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("calculator");
  lcd.setCursor(0,1);
  lcd.print("Second number: ");
  while(Serial.available()==0){

  }
  number2 = Serial.readStringUntil('\n');
  num2 = number2.toInt();
  // while(Serial.available()){
  //   Serial.read();
  // }
  lcd.print(num2);
  delay(2000);  
  lcd.clear();

  if(oper == "+"){
    result = num1 + num2;
  } 
  else if(oper == "-"){
    result = num1 - num2;
  }
  else if(oper == "*"){
    result = num1 * num2;
  }
  else if(oper == "/"){
    if(num2 == 0){
      lcd.print("Error: div/0");
      delay(3000);
      return;
    }
    else{
    result = num1 / num2;
    }
  }
  lcd.print("Result:");
  lcd.setCursor(0, 1);
  lcd.print(num1);
  lcd.print(oper);
  lcd.print(num2);
  lcd.print(" = ");
  lcd.print(result);
  delay(3000);
  lcd.clear();
}