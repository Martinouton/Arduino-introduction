int redPin=9;
int greenPin=11;
int bluePin=13;
String msg="Elige un color";
String myColor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  while(Serial.available()==0){

  }
  myColor=Serial.readString();
  myColor.trim();

  if(myColor.equalsIgnoreCase("red")){
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
  }

  if(myColor.equalsIgnoreCase("green")){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,HIGH);
    digitalWrite(bluePin,LOW);
  }

  if(myColor.equalsIgnoreCase("blue")){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,HIGH);
  }

  if(myColor.equalsIgnoreCase("off")){
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
  }    

  if(myColor.equalsIgnoreCase("cyan")){
    analogWrite(redPin,0);
    analogWrite(greenPin,255);
    analogWrite(bluePin,255);
  }  

  if(myColor.equalsIgnoreCase("magenta")){
    analogWrite(redPin,255);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
  } 

  if(myColor.equalsIgnoreCase("yellow")){
    analogWrite(redPin,255);
    analogWrite(greenPin,10);
    analogWrite(bluePin,0);
  } 
}
