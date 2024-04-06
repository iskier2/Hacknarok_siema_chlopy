#include "motor.h"
#include "config.h"

void motorAutomationProcess() {
  kolejka.set_current_sensors(data.distanceUpSensor, data.distanceDownSensor, data.temperatureSensor, 0, currentTime, remote.speed, remote.min, remote.max);
  Serial.println(kolejka.get_error());
  Serial.println(kolejka.get_speed());
}
