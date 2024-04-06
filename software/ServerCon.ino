#include "ServerCon.h"
#include "config.h"


ServerCon::ServerCon() {
  multi.addAP(ssid, password);
  if (multi.run() != WL_CONNECTED) {
    Serial.println("nie ma wifi");
    delay(10000);
    rp2040.reboot();
  }
  if (!client.connect(host, webPort)) {
    Serial.println("wyjebało serwer u Kamila");
    return;
  }
}

void ServerCon::sendData(ServerData operation, String str) {
  String operationS;
  switch(operation){
    case TEMPERATURE: operationS = "temperature"; break;
    case PEOPLE_COUNT: operationS = "peopleCount"; break;
    case ERROR: operationS = "error"; break;
    case SPEED: operationS = "speed"; break;
    case MIN_TEMP: operationS = "minTemp"; break;
    case MAX_TEMP: operationS = "maxTemp"; break;
    case CURR_SPEED: operationS = "currSpeed"; break;
  }
  if (client.connected()) {
    client.println(operationS + ":" + str);
  }
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      client.stop();
      return;
    }
  }

  while (client.available()) {
    char ch = static_cast<char>(client.read());
    Serial.print(ch);
  }
}
//   ServerCon con = ServerCon();
//   con.sendData("Pierdol sie Kamil");
