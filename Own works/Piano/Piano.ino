int button1 = 2;
int button2 = 3;
int button3 = 4;
int button4 = 5;
int button5 = 6;

int State1;
int State1Old;
int State2;
int State2Old;
int State3;
int State3Old;
int State4;
int State4Old;
int State5;
int State5Old;

int buzzer = A1;

int potentiometer = A0;
int freq;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button1, INPUT);
  digitalWrite(button1, HIGH);
  pinMode(button2, INPUT);
  digitalWrite(button2, HIGH);
  pinMode(button3, INPUT);
  digitalWrite(button3, HIGH);
  pinMode(button4, INPUT);
  digitalWrite(button4, HIGH);
  pinMode(button5, INPUT);
  digitalWrite(button5, HIGH);
  pinMode(potentiometer, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  freq = analogRead(potentiometer)/100;
  if(freq == 0){
    freq = 1;
  }
  Serial.println(freq);
  State1 = digitalRead(button1);
  State2 = digitalRead(button2);
  State3 = digitalRead(button3);
  State4 = digitalRead(button4);
  State5 = digitalRead(button5);

  if(State1 == 0 && State1Old == 1){
    tone(buzzer, 100 * freq);  
    delay(100);
    noTone(buzzer);
  }
  State1Old = State1;
  
  if(State2 == 0 && State2Old == 1){
    tone(buzzer, 200 * freq);  
    delay(100);
    noTone(buzzer);
  }
  State2Old = State2;
  
  if(State3 == 0 && State3Old == 1){
    tone(buzzer, 300 * freq);  
    delay(100);
    noTone(buzzer);
  }
  State3Old = State3;
  
  if(State4 == 0 && State4Old == 1){
    tone(buzzer, 400 * freq);  
    delay(100);
    noTone(buzzer);
  }
  State4Old = State4;
  
  if(State5 == 0 && State5Old == 1){
    tone(buzzer, 500 * freq);  
    delay(100);
    noTone(buzzer);
  }
  State5Old = State5;
}
