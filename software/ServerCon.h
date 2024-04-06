#include <WiFi.h>

class ServerCon {
private:
  WiFiClient client;
public:
  ServerCon();
  void sendData(String str);
  void stopCon(){client.stop();}
};