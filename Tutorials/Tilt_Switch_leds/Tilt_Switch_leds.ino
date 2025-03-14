int redPin=5;
int greenPin=13;
int tiltPin=2;
int tiltVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(tiltPin,INPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal=digitalRead(tiltPin);
  if(tiltVal==1){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
  }
  else if(tiltVal==0){
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }
}
