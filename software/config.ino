#include "config.h"

void config() {
  Serial.begin(115200);
  delay(100);
  
  pinSetup();
  dht.begin();

 wifiConnection();
}

void wifiConnection() {

}

void pinSetup() {
  pinMode(pin.temperatureSensor, INPUT);
  pinMode(pin.distanceUpEchoSensor, INPUT);
  pinMode(pin.distanceUpTrigSensor, OUTPUT);
  pinMode(pin.distanceDownEchoSensor, INPUT);
  pinMode(pin.distanceDownTrigSensor, OUTPUT);
  pinMode(pin.lightSensor, INPUT);
  pinMode(pin.motor, OUTPUT);
  pinMode(pin.light, OUTPUT);
}
