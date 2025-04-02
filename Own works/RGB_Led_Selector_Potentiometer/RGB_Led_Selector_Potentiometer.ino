int potPin = A0;
int buttonPin = 4;
int redPin = 11;
int greenPin = 10;
int bluePin = 6;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int dt = 100;
String color;
int buttonState = 1;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(buttonPin, INPUT_PULLUP); // Activar resistencia pull-up interna
  pinMode(potPin, INPUT);

  Serial.println("Arduino RGB Controller Ready.");
}

void loop() {
  Serial.println("Choose one color (red, green, blue):");

  while (Serial.available() == 0) {
    // Espera a que el usuario escriba algo
  }

  color = Serial.readString();
  color.trim(); // Elimina espacios o saltos de línea

  // Lee el botón hasta que se presione y devuelve el valor del potenciómetro convertido
  int selectedValue = readPotUntilButton();

  if (color == "red") {
    redValue = selectedValue;
    analogWrite(redPin, redValue);
    Serial.println("Red value set.");
  }
  else if (color == "green") {
    greenValue = selectedValue;
    analogWrite(greenPin, greenValue);
    Serial.println("Green value set.");
  }
  else if (color == "blue") {
    blueValue = selectedValue;
    analogWrite(bluePin, blueValue);
    Serial.println("Blue value set.");
  }
  else {
    Serial.println("Invalid color. Try again.");
  }

  // Mostrar la combinación actual
  Serial.print("Current RGB -> R: ");
  Serial.print(redValue);
  Serial.print(", G: ");
  Serial.print(greenValue);
  Serial.print(", B: ");
  Serial.println(blueValue);

  delay(500); // Pausa breve antes del siguiente ciclo
}

// Función que lee el potenciómetro hasta que se presione el botón
int readPotUntilButton() {
  int value = 0;
  int buttonState = digitalRead(buttonPin);

  Serial.println("Turn the potentiometer and press the button to set the value.");

  while (buttonState == HIGH) { // El botón está en pull-up, así que HIGH = no presionado
    value = analogRead(potPin);
    int mappedValue = map(value, 0, 1023, 0, 255);
    Serial.print("Current value: ");
    Serial.println(mappedValue);
    buttonState = digitalRead(buttonPin);
    delay(dt);
  }

  return map(analogRead(potPin), 0, 1023, 0, 255);
}
