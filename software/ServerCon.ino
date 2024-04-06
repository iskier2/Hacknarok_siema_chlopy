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

void ServerCon::sendData(String str) {

  if (client.connected()) {
    client.println(str);
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

// void setup() {
//   Serial.begin(115200);
//   ServerCon con = ServerCon();
//   con.sendData("Pierdol sie Kamil");
// }

// void loop() {
// }
