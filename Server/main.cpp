#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "Socket.cpp"
#include "DataBase.cpp"

#define ADDRESS "172.98.3.8"
#define PORT 4242




int main() {
    SocketCon socket(PORT);
    DB db = DB();
    db.query("DROP TABLE IF EXISTS main;");
    db.query("CREATE TABLE main("
             "ID INTEGER PRIMARY KEY,"
             "lightness FLOAT NOT NULL,"
             "temperature FLOAT NOT NULL,"
             "people_count INT NOT NULL,"
             "error CHAR(256) NOT NULL,"
             "lift_speed FLOAT NOT NULL,"
             "temp_min FLOAT NOT NULL,"
             "temp_max FLOAT NOT NULL);");
    db.query("INSERT INTO main (lightness, temperature, people_count, error, lift_speed, temp_min, temp_max) VALUES (1, 16, 30, '', 1, 10, 19);");
//    std::vector<std::vector<std::string>> data = db.selectQuery("SELECT * FROM main;");
//    for (int i = 0; i < data[0].size(); ++i) {
//        std::cout << data[0][i];
//    }
    int i=0;
    while (true) {
        // get new data
        if(i%100==0){
            socket.getData();
//            std::vector<std::string> data = {};
//            std::string text = "";
//            while(*res++){
//                if(*res==';'){
//                    data.push_back(text);
//                    text="";
//                }
//                else{
//                    text+=*res;
//                }
//            }

        }

        i++;

//        std::cout<<(data[0]);
//        for (int i = 0; i < data.size(); ++i) {
//            if (data[i])
//        }

//        std::string value1;
//        std::string value2;
//        std::string value3;
//        db.query("UPDATE main "
//                 "SET lightness = "+value1+", people_count = "+ value2+", lift_speed = "+ value3 + "WHERE id=1;");

    }
    db.close();
    socket.closeSocket();
    return 0;
}
