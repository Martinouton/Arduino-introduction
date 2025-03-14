int stateButton1;
int stateButton2;
int button1 = 13;
int button2 = 10;
int button1Old;
int button2Old;
int dt=500;
int redLed = 6;
int brightness;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2,INPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  stateButton1 = digitalRead(button1);
  stateButton2 = digitalRead(button2);
  if(stateButton1 == 0 && button1Old == 1){
      brightness = brightness + 20;
      analogWrite(redLed, brightness);
  }

  if(stateButton2 == 0 && button2Old == 1){
      brightness = brightness - 20;
      analogWrite(redLed, brightness);
  }

  if(stateButton1 == 0 && button1Old == 0){
      brightness = brightness + 20;
      analogWrite(redLed, brightness);
  }

  if(stateButton1 == 0 && button1Old == 0){
      brightness = brightness + 20;
      analogWrite(redLed, brightness);
  }
  Serial.print("Botón 1: ");
  Serial.print(stateButton1);
  Serial.print(", Botón 2: ");
  Serial.print(stateButton2);
  Serial.print(", brillo led: ");
  Serial.println(brightness);
  delay(dt);
  button1Old = stateButton1;
  button2Old = stateButton2;
}
