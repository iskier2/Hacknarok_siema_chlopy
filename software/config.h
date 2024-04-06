#ifndef CONFIG_H_
#define CONFIG_H_

void config();

void pinSetup();

const char* ssid = "KPT-Conference";
const char* password = "E2ue6Tm&";

const int webPort = 4200;
const char* host = "172.98.3.8";

struct devicesData {
  byte temperatureSensor = 0;
  byte distanceUpSensor = 0;
  byte distanceDownSensor = 0;
  byte lightSensor = 0;
  byte motor = 0;
  bool light = false;
  bool error = false;
};

struct devicesPin {
  const byte temperatureSensor = 2;
  const byte distanceUpEchoSensor = 11;
  const byte distanceUpTrigSensor = 10;
  const byte distanceDownEchoSensor = 7;
  const byte distanceDownTrigSensor = 6;
  const byte lightSensor = 28;
  const byte motor = 3;
  const byte light = 5;
};

devicesData data;
devicesPin pin;

#define DHTTYPE DHT22
DHT dht(pin.temperatureSensor, DHTTYPE);


unsigned long currentTime = 0;

#endif
