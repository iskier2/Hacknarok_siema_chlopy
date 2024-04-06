#include "program.h"
#include "config.h"

void program() {
  if (currentTime - previousTime.distanceSensor >= constTime.distanceSensor) {
    previousTime.distanceSensor = currentTime;
    distanceUpSensorProbe();
    distanceDownSensorProbe();

    tests();////////////////////////////////////////
  }

  if (currentTime - previousTime.temperatureSensor >= constTime.temperatureSensor) {
    previousTime.temperatureSensor = currentTime;
    temperatureSensorProbe();
    lightSensorProbe();
  }
}

void tests() {
  Serial.print(data.distanceUpSensor);
  Serial.print("|");
  Serial.print(data.distanceDownSensor);
  Serial.print("|");
  Serial.print(data.temperatureSensor);
  Serial.print("|");
  Serial.println(data.lightSensor);
}
