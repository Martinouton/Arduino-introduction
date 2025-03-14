#include <Stepper.h> //librería step motor
int stepsPerRevolution = 2048;  //Concreto para este step motor
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); //Pins para este driver, Creación objeto motor
int motSpeed = 100; //Velocidad giro
int dt= 250;
int buttonPin= 2;
int buttonVal;
int buttonStateOld=1;
int direction=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH); //Genérase a R de pull up por código, non se necesita no circuito

}

void loop() {
  //put your main code here, to run repeatedly:
  buttonVal = digitalRead(buttonPin);
  Serial.print("Estado botón: ");
  Serial.println(buttonVal);
  if(buttonVal==0 && buttonStateOld==1){
      direction = direction*(-1);    
  }
  myStepper.step(direction);
  buttonStateOld = buttonVal;
}
