#include <IRremote.h>

const int IR_RECEIVE_PIN = 9;

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("Iniciando receptor IR...");

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Esperando señal IR...");
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
        Serial.println("Up");
      }
      if(valor == 0xF807FF00){
        Serial.println("Down");
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
