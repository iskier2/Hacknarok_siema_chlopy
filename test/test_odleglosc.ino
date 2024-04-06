#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void setup() 
{
  Serial.begin(9600);
}

void loop(void) 
{
  sensors_event_t event; 
  mag.getEvent(&event);
  Serial.print("X axis: "); Serial.print(event.magnetic.x); Serial.print(" uT   ");
  Serial.print("Y axis: "); Serial.print(event.magnetic.y); Serial.print(" uT   ");
  Serial.print("Z axis: "); Serial.print(event.magnetic.z); Serial.println(" uT");
  delay(500);
}
