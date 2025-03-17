int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int mSpeed = 120;
int tiltPin = 2;
int tiltVal;
bool first = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(tiltPin,INPUT);
  digitalWrite(tiltPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal = digitalRead(tiltPin);
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);

  analogWrite(speedPin,mSpeed);
  if(tiltVal==0){
    digitalWrite(dir1,LOW);
    first=1;
  }
  else{
    digitalWrite(dir1,HIGH);
      if (first==1){
        mSpeed=255;
        first=0;
      }
      else{
        mSpeed=120;
  }
  }
  Serial.println(tiltVal);
}
