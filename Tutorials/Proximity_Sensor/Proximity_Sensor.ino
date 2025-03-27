int trigPin = 9;
int echoPin = 8;
int pingTravelTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTravelTime = pulseIn(echoPin, HIGH); // Function to read a pulse HIGH or LOW
  Serial.print(pingTravelTime); // distance = duration * 0.0343/2; to read the distance in cms
  delay(100);
}
