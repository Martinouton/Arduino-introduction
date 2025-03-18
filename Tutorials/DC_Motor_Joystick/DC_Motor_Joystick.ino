int xVal = A0;
int yVal = A1;
int switchPin = 7;
int xPos;
int yPos;
int switchVal=1;
int dt = 100;

int dir1 = 2;
int dir2 = 3;
int pSpeed = 4;
int mSpeed;

void setup() {
  // put your setup code here, to run once:
  pinMode(xVal,INPUT);
  pinMode(yVal,INPUT);
  pinMode(switchPin,INPUT);

  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pSpeed,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  xPos = analogRead(xVal);
  yPos = analogRead(yVal);
  switchVal = digitalRead(switchPin);
  Serial.print(xPos);
  Serial.print(", ");
  Serial.print(yPos);
  Serial.print(", ");
  Serial.println(switchVal);

  if(yPos>512){
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    mSpeed = (255./512.)*yPos-255.;
    analogWrite(pSpeed,mSpeed);
  }

  if(yPos<508){
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    mSpeed = -255./512.*yPos+255.;
    analogWrite(pSpeed,mSpeed);
  }

  if(yPos>508 && yPos<512){
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    mSpeed = 0;
    analogWrite(pSpeed,mSpeed);
  }

  delay(dt);
}
