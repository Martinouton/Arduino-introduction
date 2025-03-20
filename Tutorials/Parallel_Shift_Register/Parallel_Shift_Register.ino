int latchPin = 11;
int clockPin = 10;
int dataPin = 12;
byte LED = 0b00001100;
int primera = 1;


int dt = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(primera==1){
    primera=0;
    if((LED&&00000001)==00000001){
    LED = LED/2+1;
    }
  }
    Serial.print(LED&&00000001);

  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin, LSBFIRST,LED);
  digitalWrite(latchPin,HIGH);

  //LED = LED + 1; 
  delay(dt);

}
