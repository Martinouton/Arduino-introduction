#include <IRremote.h>

const int IR_RECEIVE_PIN = 8;

int greenPin = 9; // Reasignado a un pin disponible
int redPin = 10;
int bluePin = 5;
int value=255;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, false); // LED de feedback deshabilitado
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long valor = IrReceiver.decodedIRData.decodedRawData;

    // Ignorar códigos 0x0 (repeticiones)
    if (valor != 0x0) {
      if(valor == 0xE916FF00){
        Serial.println("Zero");
        analogWrite(redPin, value);
        analogWrite(bluePin, 0);
        analogWrite(greenPin, 0);
      }
      if(valor == 0xF30CFF00){
        Serial.println("One");
        analogWrite(redPin, 0);
        analogWrite(bluePin, value);
        analogWrite(greenPin, 0);
      }
      if(valor == 0xE718FF00){
        Serial.println("Two");
        analogWrite(redPin, 0);
        analogWrite(bluePin, 0);
        analogWrite(greenPin, value);
      }
      if(valor == 0xA15EFF00){
        Serial.println("Three");
        analogWrite(redPin, 0);
        analogWrite(bluePin, value);
        analogWrite(greenPin, value);
      }
      if(valor == 0xF708FF00){
        Serial.println("Four");
        analogWrite(redPin, value);
        analogWrite(bluePin, 0);
        analogWrite(greenPin, value*165/255);
      }
      if(valor == 0xE31CFF00){
        Serial.println("Five");
        analogWrite(redPin, value);
        analogWrite(bluePin, 0);
        analogWrite(greenPin, value);
      }
      if(valor == 0xA55AFF00){
        Serial.println("Six");
        analogWrite(redPin, value);
        analogWrite(bluePin, value);
        analogWrite(greenPin, 0);
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
      }
      if(valor == 0xB946FF00){
        Serial.println("Vol+");
      }
      if(valor == 0xEA15FF00){
        Serial.println("Vol-");
      }
      if(valor == 0xBB44FF00){
        Serial.println("Previous");
      }
      if(valor == 0xBF40FF00){
        Serial.println("Start/Pause");
      }
      if(valor == 0xBC43FF00){
        Serial.println("Next");
      }
      if(valor == 0xF609FF00){
        Serial.print("Up: ");
        value = value + 15;
        if(value > 255){
          value = 255;
        }
        Serial.println(value);
      }
      if(valor == 0xF807FF00){
        Serial.print("Down: ");
        value = value - 15;
        if(value < 0){
          value = 0;
        }
        Serial.println(value);
      }
      if(valor == 0xB847FF00){
        Serial.println("Func/Stop");
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