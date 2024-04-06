#include "sensors.h"
#include "config.h"

void temperatureSensorProbe() {
  data.temperatureSensor = dht.readTemperature();
  if (isnan(data.temperatureSensor)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
}

void distanceUpSensorProbe() {
  digitalWrite(pin.distanceUpTrigSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(pin.distanceUpTrigSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin.distanceUpTrigSensor, LOW);

  data.distanceUpSensor = (pulseIn(pin.distanceUpEchoSensor, HIGH) * .0343) / 2;
}

void distanceDownSensorProbe() {
  digitalWrite(pin.distanceDownTrigSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(pin.distanceDownTrigSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin.distanceDownTrigSensor, LOW);

  data.distanceDownSensor = (pulseIn(pin.distanceDownEchoSensor, HIGH) * .0343) / 2;
}

void lightSensorProbe() {
  data.lightSensor = map(analogRead(pin.lightSensor), 0, 1023, 0, 100);
}
