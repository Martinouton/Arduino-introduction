int latchPin = 8;
int clockPin = 13;
int dataPin = 12;
int dt = 500;
int i = 0;

byte numbers[] = {
  0b11101101, //0 
  0b00000101, //1 
  0b11110001, //2 
  0b10110101, //3 
  0b00011101, //4 
  0b10111100, //5 
  0b11111100, //6 
  0b10000101, //7 
  0b11111101, //8 
  0b10111101, //9 
  0b00000010  //.
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin, LSBFIRST,numbers[i]);
  digitalWrite(latchPin,HIGH);

  i++;
  delay(dt);
  if (i > 10){
    i = 0;
  }

}
