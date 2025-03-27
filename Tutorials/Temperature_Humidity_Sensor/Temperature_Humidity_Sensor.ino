#include "DHT.h"
#define Type DHT11

int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;
int dt = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(setTime);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true); // To read temperatures in Fahrenheit

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", temperature Cº: ");
  Serial.print(tempC);
  Serial.print(", temperature F: ");
  Serial.println(tempF);
  delay(dt);
}
