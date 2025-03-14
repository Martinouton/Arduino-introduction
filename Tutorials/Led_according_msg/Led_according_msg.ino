String msg = "Elige LED";
String led;
int dt = 200;
String red = "RED";
String blue = "BLUE";
String green = "GREEN";
int redPin = 7;
int bluePin = 8;
int greenPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  Serial.println(msg);
  
  while (Serial.available() == 0) {
    // Espera a recibir datos
  }

  led = Serial.readString();
  led.trim(); // Elimina espacios en blanco y saltos de línea
  
  Serial.println(led);

  if (led=="red") {
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
  } 
  else if (led.equalsIgnoreCase("blue")) {
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
  } 
  else if (led.equalsIgnoreCase("green")) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}
