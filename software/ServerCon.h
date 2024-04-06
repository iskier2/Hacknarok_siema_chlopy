#ifndef SERVERCON_H_
#define SERVERCON_H_
#include "WiFi.h"
WiFiMulti multi;

class ServerCon {
  private:
    WiFiClient client;
  public:
    void setClient();
    void sendData(ServerData operation, String str);
    void stopCon() {
      client.stop();
    }
};

#endif
