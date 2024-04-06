#ifndef SERVERCON_H_
#define SERVERCON_H_

WiFiMulti multi;

class ServerCon {
private:
  WiFiClient client;
public:
  ServerCon();
  void sendData(String str);
  void stopCon(){client.stop();}
};

ServerCon con = ServerCon();
#endif