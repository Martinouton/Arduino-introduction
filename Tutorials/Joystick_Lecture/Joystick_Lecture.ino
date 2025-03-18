int xVal = A0;
int yVal = A1;
int switchPin = 7;
int xPos;
int yPos;
int switchVal=1;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(xVal,INPUT);
  pinMode(yVal,INPUT);
  pinMode(switchPin,INPUT);
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
  delay(dt);
}
