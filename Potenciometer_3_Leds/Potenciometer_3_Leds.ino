int readPin = A5;
int redLed = 7;
int blueLed = 6;
int greenLed = 5;
int readVal;
float V5;
int dt=500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(readPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(readPin);
  V5 = (5./1023.)*readVal;
  Serial.print("Valor de tensión no potenciómetro: ");
  Serial.print(V5);
  Serial.println(" V.");
  if(V5>=4){
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, LOW);
  }
  if(V5<4 && V5>=2.3){
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, HIGH);    
  }
  if(V5<2.3){
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    digitalWrite(greenLed, LOW);    
  }
  delay(dt);
}
