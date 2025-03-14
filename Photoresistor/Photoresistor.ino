int readVal;
int photoPin=A5;
int dt=250;
int redPin=8;
int greenPin=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photoPin,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal=analogRead(photoPin);
  Serial.println(readVal);
  if(readVal>=500){
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
  else{
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
  }

  delay(dt);
}
