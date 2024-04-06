#include "config.h"
#include "program.h"
#include "web.h"

#define softwareVersion "v1.0.2b"

void setup() {
  delay(100);
  config();
  Serial.println("Config finish");
}

void loop() {
  currentTime = millis();
}
