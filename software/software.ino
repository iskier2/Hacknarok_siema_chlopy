#include <DHT.h>
#include <WiFi.h>
#include "config.h"
#include "sensors.h"
#include "program.h"
#include "web.h"
#include "ServerCon.h"
#define softwareVersion "v1.0.2b"
#define codeName "kolejka"

void setup() {
  delay(100);
  config();
  Serial.println("Config finish");
}

void loop() {
  currentTime = millis();
  program();
}
