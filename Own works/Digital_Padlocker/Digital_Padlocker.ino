#include <LiquidCrystal.h>
#include <Servo.h>
Servo myServo;
#include <IRremote.h>

int rs = 7;
int en = 6;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int servoPin = 8;

int IR_RECEIVE_PIN = 9;

int buzzPin = 11;
int buzzTime = 500000;
int greenPin = 12;
int redPin = A4;
int button1Pin = A3;
int button2Pin = A2;
int photoresistor = A1;
int lightVal;

String stringPassword;
int password = 0;
int passSaved;
int tries = 3;
int pos;
bool valid = false;

int digitCounter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  myServo.attach(servoPin);

  lcd.begin(16,2);

  pinMode(buzzPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(button1Pin, INPUT);
  digitalWrite(button1Pin, HIGH);
  pinMode(button2Pin, INPUT);
  digitalWrite(button2Pin, HIGH);
  pinMode(photoresistor, INPUT);

  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (valid == false) {
    digitCounter = 0;
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    pos = 0;
    myServo.write(pos);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Set a password");
    lcd.setCursor(0,1);
    lcd.print("of 4 digits:");
    while(digitCounter < 4){
        if (IrReceiver.decode()) {
          unsigned long valor = IrReceiver.decodedIRData.decodedRawData;

          // Ignorar códigos 0x0 (repeticiones)
          if (valor != 0x0) {
            if(valor == 0xE916FF00){
              Serial.println("Zero");
              password = password*10;
              digitCounter += 1;
            }
            if(valor == 0xF30CFF00){
              Serial.println("One");
              password = password*10+1;
              digitCounter += 1;
            }
            if(valor == 0xE718FF00){
              Serial.println("Two");
              password = password*10+2;
              digitCounter += 1;
            }
            if(valor == 0xA15EFF00){
              Serial.println("Three");
              password = password*10+3;
              digitCounter += 1;
            }
            if(valor == 0xF708FF00){
              Serial.println("Four");
              password = password*10+4;
              digitCounter += 1;
            }
            if(valor == 0xE31CFF00){
              Serial.println("Five");
              password = password*10+5;
              digitCounter += 1;
            }
            if(valor == 0xA55AFF00){
              Serial.println("Six");
              password = password*10+6;
              digitCounter += 1;
            }
            if(valor == 0xBD42FF00){
              Serial.println("Seven");
              password = password*10+7;
              digitCounter += 1;
            }
            if(valor == 0xAD52FF00){
              Serial.println("Eight");
              password = password*10+8;
              digitCounter += 1;
            }
            if(valor == 0xB54AFF00){
              Serial.println("Nine");
              password = password*10+9;
              digitCounter += 1;
            }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Set a password");
      lcd.setCursor(0,1);
      lcd.print("of 4 digits:");
      if(password!=0){
      lcd.print(password);
      }
    }
    IrReceiver.resume();
       }
    }

    if(password>9999 || password <0){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Password denied");
      delay(2000);
    }else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Password saved.");
      passSaved = password;
      password = 0;
      valid = true;
      delay(2000);
    }
  }else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter password");
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitCounter = 0;
    password = 0;
    while(digitCounter < 4){
      if(digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW){
          lightVal = analogRead(photoresistor);
          delay(500);
          if(lightVal > 700){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Reset: new ");
            lcd.setCursor(0, 1);
            lcd.print("password needed");
            while(Serial.available()==0){

            }
            stringPassword = Serial.readStringUntil('\n');
            stringPassword.trim();
            passSaved = stringPassword.toInt();
            password = 0;
            tries = 3;
            return;
          }
        }
        if (IrReceiver.decode()) {
          unsigned long valor = IrReceiver.decodedIRData.decodedRawData;

          // Ignorar códigos 0x0 (repeticiones)
          if (valor != 0x0) {
            if(valor == 0xE916FF00){
              Serial.println("Zero");
              password = password*10;
              digitCounter += 1;
            }
            if(valor == 0xF30CFF00){
              Serial.println("One");
              password = password*10+1;
              digitCounter += 1;
            }
            if(valor == 0xE718FF00){
              Serial.println("Two");
              password = password*10+2;
              digitCounter += 1;
            }
            if(valor == 0xA15EFF00){
              Serial.println("Three");
              password = password*10+3;
              digitCounter += 1;
            }
            if(valor == 0xF708FF00){
              Serial.println("Four");
              password = password*10+4;
              digitCounter += 1;
            }
            if(valor == 0xE31CFF00){
              Serial.println("Five");
              password = password*10+5;
              digitCounter += 1;
            }
            if(valor == 0xA55AFF00){
              Serial.println("Six");
              password = password*10+6;
              digitCounter += 1;
            }
            if(valor == 0xBD42FF00){
              Serial.println("Seven");
              password = password*10+7;
              digitCounter += 1;
            }
            if(valor == 0xAD52FF00){
              Serial.println("Eight");
              password = password*10+8;
              digitCounter += 1;
            }
            if(valor == 0xB54AFF00){
              Serial.println("Nine");
              password = password*10+9;
              digitCounter += 1;
            }
      }
      IrReceiver.resume();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter password");
      lcd.setCursor(0, 1);
      if(password!=0){
      lcd.print(password);
      }
      }
    }
    // stringPassword = Serial.readStringUntil('\n');
    // stringPassword.trim();
    // password = stringPassword.toInt();
    if(password == passSaved){
      tries = 3;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Correct password");
      lcd.setCursor(0, 1);
      lcd.print("Opening padlock");
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
      pos = 90;
      myServo.write(pos);
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Locking padlock");
      pos = 0;
      myServo.write(pos);
      delay(3000);
    }else{
      password = 0;
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      tries -= 1;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Wrong password");
      lcd.setCursor(0, 1);
      lcd.print("Tries left: ");
      lcd.print(tries);
      delay(3000);
      digitalWrite(redPin, LOW);
      if(tries == 0){
        digitalWrite(redPin, HIGH);
        delay(250);
        digitalWrite(redPin, LOW);
        delay(250);
        digitalWrite(redPin, HIGH);
        delay(250);
        digitalWrite(redPin, LOW);
        delay(250);
        digitalWrite(redPin, HIGH);  
        tone(buzzPin, 1000);
        delay(300); 
        noTone(buzzPin);
        delay(300);
        tone(buzzPin, 1000);
        delay(300);         
        noTone(buzzPin);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Padlock locked");
        lcd.setCursor(0, 1);
        lcd.print("Too many tries");
        delay(5000);

      }
    }


  }

}