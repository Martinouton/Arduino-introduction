int redPin=8;
int botonPin=12;
int buttonRead;
int buttonOld;
int dt =250;
int LedState=HIGH;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(botonPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonRead=digitalRead(botonPin);
Serial.println(buttonRead);
if(buttonRead == 1 && buttonOld == 0){
  LedState=!LedState;
  digitalWrite(redPin,LedState);
  delay(dt);
}
buttonOld=buttonRead;
}
