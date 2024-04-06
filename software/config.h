#ifndef CONFIG_H_
#define CONFIG_H_

void config();

void pinSetup();

const char* ssid = "KPT-Conference";
const char* password = "E2ue6Tm&";

const int webPort = 4200;
const char* host = "172.98.3.8";

struct remoteData {
  byte max = 10;
  byte min = 0;
  int speed = 0;
  const byte distanceUpSensorMax = 10;
  const byte distanceDownSensorMax = 10;
};

remoteData remote;

struct devicesData {
  byte temperatureSensor = 0;
  bool distanceUpSensor = false;
  bool distanceDownSensor = false;
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

enum ServerData {
  //post
  TEMPERATURE, 
  PEOPLE_COUNT, 
  ERROR, 
  SPEED, 
  //get
  MIN_TEMP, 
  MAX_TEMP, 
  CURR_SPEED
};

unsigned long currentTime = 0;

#endif
