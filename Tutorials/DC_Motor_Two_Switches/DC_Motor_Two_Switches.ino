int pinSpeed = 13;
int dir1 = 12;
int dir2 = 11;
int mSpeed = 0;
int trueSpeed;

int velmais = 7;
int velmenos = 6;
int valmais;
int valmaisOld=1;
int valmenos;
int valmenosOld=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinSpeed,OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);

  pinMode(velmais,INPUT);
  pinMode(velmenos,INPUT);
  digitalWrite(velmais,HIGH);
  digitalWrite(velmenos,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  valmais = digitalRead(velmais);
  valmenos = digitalRead(velmenos);
  Serial.print("valmais: ");
  Serial.print(valmais);  
  Serial.print(", valmaisOld: ");
  Serial.print(valmaisOld);
  Serial.print(", ");
  Serial.print("valmenos: ");
  Serial.print(valmenos);
  Serial.print(", valmenosOld: ");  
  Serial.println(valmenosOld);
  if(valmais==0 & valmaisOld==1){
    mSpeed = mSpeed + 15;
  }
  if(valmenos==0 & valmenosOld==1){
    mSpeed = mSpeed - 15;
  }

  valmaisOld=valmais;
  valmenosOld=valmenos;
  trueSpeed = abs(mSpeed);

  if(mSpeed>0){
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    if(mSpeed>255){
      mSpeed=255;
    }
    analogWrite(pinSpeed,trueSpeed);
  }

  if(mSpeed<0){
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,HIGH);
    if(mSpeed<-255){
      mSpeed = -255;
    }
    analogWrite(pinSpeed,trueSpeed);
  }

  if(mSpeed==0){
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    analogWrite(pinSpeed,trueSpeed);
  }

  Serial.print("mSpeed: ");
  Serial.print(mSpeed);
  Serial.print(", trueSpeed: ");
  Serial.println(trueSpeed);
  
  delay(250);

}
