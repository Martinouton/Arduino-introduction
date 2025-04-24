int redPin = 11;
int greenPin = 10;
int bluePin = 13;
int yellowPin = 12;

int buzzPin = A0;

int buttonBlue = A2;
int buttonRed = A3;
int buttonYellow = A4;
int buttonGreen = A5;

int buttonBlueState;
int buttonRedState;
int buttonYellowState;
int buttonGreenState;

int buttonBlueStateOld = 1;
int buttonRedStateOld = 1;
int buttonYellowStateOld = 1;
int buttonGreenStateOld = 1;

int ledActive;
int ledSequence[100];
int buttonSequence[100];
int i = 0;
int counter = 0;
int buttonCounter = 0;
int fail = 0;

int mini = 300;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);

  pinMode(buttonBlue, INPUT);
  digitalWrite(buttonBlue, HIGH);
  pinMode(buttonRed, INPUT);
  digitalWrite(buttonRed, HIGH);
  pinMode(buttonYellow, INPUT);
  digitalWrite(buttonYellow, HIGH);
  pinMode(buttonGreen, INPUT);
  digitalWrite(buttonGreen, HIGH);

  randomSeed( analogRead(A1));
  
}

void loop() {
  // put your main code here, to run repeatedly:
  ledSequence[i] = random(1,5);
  Serial.println(ledSequence[i]);
  i ++;
  counter = 0;
  while(counter < i){
    sequence(ledSequence[counter]);
    counter ++;
  }
  
  buttonCounter = 0;
  Serial.println("Introduce the correct colour sequence");
  while(buttonCounter < i){
    buttonBlueState = digitalRead(buttonBlue);
    buttonRedState = digitalRead(buttonRed);
    buttonYellowState = digitalRead(buttonYellow);
    buttonGreenState = digitalRead(buttonGreen);

    if(buttonBlueState==0 && buttonBlueStateOld == 1){
      buttonSequence[buttonCounter]=1;
      buttonCounter ++;
      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      delay(mini);
      digitalWrite(bluePin, LOW);
      if(ledSequence[buttonCounter-1] == buttonSequence[buttonCounter-1]){
        if(buttonCounter == i){
          Serial.println("Next");
        }
      }else{
        Serial.println("qqq");
        gameOver();
      }
      }
    if(buttonRedState==0 && buttonRedStateOld == 1){
      buttonSequence[buttonCounter]=2;
      buttonCounter ++;
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      delay(mini);
      digitalWrite(redPin, LOW);
      if(ledSequence[buttonCounter-1] == buttonSequence[buttonCounter-1]){
        if(buttonCounter == i){
          Serial.println("Next");
        }
      }else{
        gameOver();
      }
      }
    if(buttonYellowState == 0 && buttonYellowStateOld==1){
      buttonSequence[buttonCounter]=3;
      buttonCounter ++;
      digitalWrite(yellowPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      delay(mini);
      digitalWrite(yellowPin, LOW);
      if(ledSequence[buttonCounter-1] == buttonSequence[buttonCounter-1]){
        if(buttonCounter == i){
          Serial.println("Next");
        }
      }else{
        gameOver();
      }
      }
    if(buttonGreenState==0 && buttonGreenStateOld == 1){
      buttonSequence[buttonCounter]=4;
      buttonCounter ++;
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      delay(mini);
      digitalWrite(greenPin, LOW);
      if(ledSequence[buttonCounter-1] == buttonSequence[buttonCounter-1]){
        if(buttonCounter == i){
          Serial.println("Next");
        }
      }else{
        gameOver();
      }
      }
    buttonBlueStateOld = buttonBlueState;
    buttonRedStateOld = buttonRedState;
    buttonYellowStateOld = buttonYellowState;
    buttonGreenStateOld = buttonGreenState;
    if(fail == 1){
      fail = 0;
      break;
    }

  }
}


  


  void sequence(int led){
    switch (led){
    case 1:
      digitalWrite(bluePin, LOW);
      delay(mini);
      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      break;
    case 2:
      digitalWrite(redPin, LOW);
      delay(mini);
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      break;
    case 3:
      digitalWrite(yellowPin, LOW);
      delay(mini);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      break;
    case 4:
      digitalWrite(greenPin, LOW);
      delay(mini);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      break;
  }
  delay(500);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  }

void gameOver(){
  tone(buzzPin, 200);  
  delay(100);
  noTone(buzzPin);
  delay(100);
  tone(buzzPin, 200);  
  delay(100);
  noTone(buzzPin);
  for(int j = 0; j == i; j ++){
    ledSequence[j] = 0;
    buttonSequence[j] = 0;
    buttonCounter = 0;
  }
    Serial.println("GAME OVER");
    Serial.print("Current score = ");
    Serial.println(i-1);
    fail = 1;
    i = 0;
    counter = 0;
    buttonCounter = 0;
    delay(3000);
    Serial.println("Reseting values...");
    delay(3000);
}

