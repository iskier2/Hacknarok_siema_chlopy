
#define NON_ERROR 0
#define ERROR_JUMP_FROM_QUEQUE 1 //people_sensor_up 0 people_sensor_down 1 after time
#define STAY_QUEQUE 2


class QuequeLine {
  public:
    QuequeLine(byte home_akceleration, byte distance): home_akceleration(home_akceleration), distance(distance) {
    }
    byte get_speed() {
     if (this->error == NON_ERROR) {
        return  0;
      }
      //braka na orczyku 10 jesli jest to zadana
      return speedInput;
    }
    byte get_error() {
      return error;
    }
    void set_current_sensors(bool  people_sensor_up, bool  people_sensor_down, byte temperature, byte current_akceleration, unsigned long current_time, byte speedInput) {
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
void setup() {
  // put your setup code here, to run once:

  kolejka.set_temp_avg(10, 10);
  Serial.begin(115200);
}

void loop() {
  kolejka.set_current_sensors(true,false,20,10,millis(),20);
  // put your main code here, to run repeatedly:
  Serial.println(kolejka.get_error());
}
