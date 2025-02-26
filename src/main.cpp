#include <Arduino.h>

#define RED_PIN 23
#define YELLOW_PIN 22
#define GREEN_PIN 21

const unsigned long RED_TIME = 30000;
const unsigned long GREEN_TIME = 20000; 
const unsigned long YELLOW_TIME = 5000; 

// Waktu terakhir perubahan lampu
unsigned long previousMillis = 0;
int trafficState = 0; 

void setup() {
  Serial.begin(115200);
  Serial.println("Traffic Light System Started");

  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis(); 

  if (trafficState == 0 && currentMillis - previousMillis >= RED_TIME) {
    trafficState = 1;
    previousMillis = currentMillis;
  } 
  else if (trafficState == 1 && currentMillis - previousMillis >= GREEN_TIME) {
    trafficState = 2;
    previousMillis = currentMillis;
  } 
  else if (trafficState == 2 && currentMillis - previousMillis >= YELLOW_TIME) {
    trafficState = 0;
    previousMillis = currentMillis;
  }

  // Update status lampu
  if (trafficState == 0) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    Serial.println("RED ON");
  } 
  else if (trafficState == 1) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    Serial.println("GREEN ON");
  } 
  else if (trafficState == 2) {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    Serial.println("YELLOW ON");
  }
}
