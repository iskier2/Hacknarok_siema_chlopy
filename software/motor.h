#ifndef MOTOR_H_
#define MOTOR_H_

void motorAutomationProcess();

#define NON_ERROR 0
#define ERROR_JUMP_FROM_QUEQUE 1 //people_sensor_up 0 people_sensor_down 1 after time
#define STAY_QUEQUE 2
#define TO_LOW_TEMP 3

class QuequeLine {
  public:
    QuequeLine(byte home_akceleration, byte distance): home_akceleration(home_akceleration), distance(distance) {
    }
    byte get_speed() {
      if (this->error == NON_ERROR) {
        return  0;
      } else if (this->error == ERROR_JUMP_FROM_QUEQUE) {
        return 0;
      } else if (this->error == STAY_QUEQUE) {
        return 10;
      } else if (people_sensor_down == false && people_sensor_up) {
        return speedInput / 2;
      }
      //braka na orczyku 10 jesli jest to zadana
      return speedInput;
    }
    byte get_error() {
      return error;
    }
    void set_current_sensors(bool  people_sensor_up, bool  people_sensor_down, byte temperature, byte current_akceleration, unsigned long current_time, byte speedInput, byte initialTemperatureMin, byte initialTemperatureMax) {
      this->people_sensor_up = people_sensor_up;
      this->people_sensor_down = people_sensor_down;
      this->temperature = temperature;
      this->current_time = current_time;
      this->initialTemperatureMin =  initialTemperatureMin;
      this->initialTemperatureMax =  initialTemperatureMax;
      if (people_sensor_down == true) {
        time_travel_max = distance / speedInput;
      }
      if (millis() - current_time >= time_travel_max && !people_sensor_up) {
        error = ERROR_JUMP_FROM_QUEQUE;
      }
      if (!people_sensor_up && !people_sensor_up) {
        error = STAY_QUEQUE;
      }
      if (initialTemperatureMin < temperature) {
        error = TO_LOW_TEMP;
      }
    }
  private:
    byte temperature = 0;
    byte speedInput = 0;
    byte initialTemperatureMin  = 0;
    byte initialTemperatureMax = 0;
    byte error = NON_ERROR;
    byte speedQueque = 0;
    byte current_akceleration = 0;
    byte home_akceleration;
    byte distance;
    bool people_sensor_up = false;
    bool people_sensor_down = false;
    unsigned long current_time = 0;
    unsigned long time_travel_max = 0;
};

QuequeLine kolejka(10, 20);

#endif
