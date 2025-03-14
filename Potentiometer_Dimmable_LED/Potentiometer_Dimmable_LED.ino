int redPin = 6;
int readVal;
float V5;
int readPin = A5;
int dt = 250;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(readPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(readPin);
  V5 = (255./1023.)*readVal;
  analogWrite(redPin, V5);
  Serial.print("Valor tensión = ");
  Serial.print(V5);
  Serial.println(" V.");
  delay(dt);
}
