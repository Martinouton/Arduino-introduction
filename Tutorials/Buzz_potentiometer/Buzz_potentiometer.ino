int pinBuzz=13;
int potPin=A5;
int potVal;
int buzzTime1=10;
float buzzTime2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinBuzz,OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  Serial.println(potVal);
  buzzTime2=10000-9.72*potVal;
  digitalWrite(pinBuzz,HIGH);
  delayMicroseconds(buzzTime2);
  digitalWrite(pinBuzz, LOW);
  delayMicroseconds(buzzTime2);
}
