#ifndef PROGRAM_H_
#define PROGRAM_H_

void program();

void tests();

struct timeData {
  const int distanceSensor = 1000;
  const int temperatureSensor = 2000;
};

struct previosTimeData {
  unsigned long distanceSensor = 0;
  unsigned long temperatureSensor = 0;
};

timeData constTime;
previosTimeData previousTime;

#endif
