void setup() {
  // put your setup code here, to run once:
  pinMode (8, OUTPUT);  //initiate pin
  pinMode (13, OUTPUT);
  pinMode (6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH);  
  digitalWrite(13, HIGH);
  digitalWrite(6, HIGH);
  delay(250);
  digitalWrite(8, LOW);
  delay(250);
  digitalWrite(8, HIGH);
  digitalWrite(13, LOW);
  delay(250);
  digitalWrite(8, LOW);
  delay(250);
  digitalWrite(8, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(6, LOW);
  delay(250);

}
