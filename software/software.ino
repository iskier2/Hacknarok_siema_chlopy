#include <DHT.h>
#include <WiFi.h>

#include "config.h"
#include "sensors.h"
#include "program.h"
#include "ServerCon.h"
#include "motor.h"

#define softwareVersion "v1.0.3b"
#define codeName "kolejka"


void setup() {
  delay(100);
  config();
  con.setClient();
  Serial.println("Config finish");
}

void loop() {
  currentTime = millis();
  program();
}
