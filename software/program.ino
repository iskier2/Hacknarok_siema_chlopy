#include "program.h"
#include "config.h"

void program() {
  if (currentTime - previousTime.distanceSensor >= constTime.distanceSensor) {
    previousTime.distanceSensor = currentTime;
    distanceUpSensorProbe();
    distanceDownSensorProbe();

    // tests();////////////////////////////////////////
    sendSensorsData();
  }

  if (currentTime - previousTime.temperatureSensor >= constTime.temperatureSensor) {
    previousTime.temperatureSensor = currentTime;
    temperatureSensorProbe();
    lightSensorProbe();
  }

  if (currentTime - previousTime.motor >= constTime.motor) {
    previousTime.motor = currentTime;
    motorAutomationProcess();
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


void sendSensorsData(){
  //con.sendData(TEMPERATURE, String(data.temperatureSensor));
  return;
}
