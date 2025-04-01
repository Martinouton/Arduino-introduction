#include <IRremote.h>

const int IR_RECEIVE_PIN = 9;

int greenPin = 3; // Reasignado a un pin disponible
int redPin = 2;

int speedPin = 5;
int dir1 = 6;
int dir2 = 4;
int mSpeed = 255;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, false); // LED de feedback deshabilitado
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long valor = IrReceiver.decodedIRData.decodedRawData;

    // Ignorar códigos 0x0 (repeticiones)
    if (valor != 0x0) {
      if(valor == 0xE916FF00){
        Serial.println("Zero");
      }
      if(valor == 0xF30CFF00){
        Serial.println("One");
      }
      if(valor == 0xE718FF00){
        Serial.println("Two");
      }
      if(valor == 0xA15EFF00){
        Serial.println("Three");
      }
      if(valor == 0xF708FF00){
        Serial.println("Four");
      }
      if(valor == 0xE31CFF00){
        Serial.println("Five");
      }
      if(valor == 0xA55AFF00){
        Serial.println("Six");
      }
      if(valor == 0xBD42FF00){
        Serial.println("Seven");
      }
      if(valor == 0xAD52FF00){
        Serial.println("Eight");
      }
      if(valor == 0xB54AFF00){
        Serial.println("NIne");
      }
      if(valor == 0xBA45FF00){
        Serial.println("Power");
        digitalWrite(dir1,HIGH);
        digitalWrite(dir2,LOW);
        analogWrite(speedPin,mSpeed);
        digitalWrite(greenPin,HIGH);
        digitalWrite(redPin,LOW);
      }
      if(valor == 0xB946FF00){
        Serial.println("Vol+");
      }
      if(valor == 0xEA15FF00){
        Serial.println("Vol-");
      }
      if(valor == 0xBB44FF00){
        Serial.println("Previous");
        digitalWrite(dir1,LOW);
        digitalWrite(dir2,HIGH);
        analogWrite(speedPin,mSpeed);
        digitalWrite(greenPin,LOW);
        digitalWrite(redPin,HIGH);
      }
      if(valor == 0xBF40FF00){
        Serial.println("Start/Pause");
      }
      if(valor == 0xBC43FF00){
        Serial.println("Next");
        digitalWrite(dir1,HIGH);
        digitalWrite(dir2,LOW);
        analogWrite(speedPin,mSpeed);
        digitalWrite(greenPin,LOW);
        digitalWrite(redPin,HIGH);
      }
      if(valor == 0xF609FF00){
        Serial.println("Up");
        mSpeed = mSpeed +15;
        if (mSpeed>255){
          mSpeed =255;
        }
        analogWrite(speedPin,mSpeed);
      }
      if(valor == 0xF807FF00){
        Serial.println("Down");
        mSpeed = mSpeed -15;
        if (mSpeed<100){
          mSpeed =100;
        }
        analogWrite(speedPin,mSpeed);
      }
      if(valor == 0xB847FF00){
        Serial.println("Func/Stop");
        digitalWrite(dir1,LOW);
        digitalWrite(dir2,LOW);
        analogWrite(speedPin,mSpeed);
        digitalWrite(greenPin,LOW);
        digitalWrite(redPin,HIGH);
      }
      if(valor == 0xE619FF00){
        Serial.println("EQ");
      }
      if(valor == 0xF20DFF00){
        Serial.println("ST/REPT");
      }
    }

    IrReceiver.resume(); // Preparado para el siguiente
  }
}