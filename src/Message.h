#include "WiFi.h"
#include <Arduino.h>
#include "AsyncUDP.h"

class Message {
    public:
    int port;
    int udpPort;
    AsyncUDP udp;
    const char * ssid = "HakunaMatata";
    const char * password = "HoejWork";
    

    Message(int port, int udpPort){
        this->port = port;
        this->udpPort = udpPort; 
        

    }

    void sendMsgTopxlEmu (String msg) {
    udp.writeTo((const uint8_t*)msg.c_str(), msg.length(), IPAddress(192,168,0,13), port);
    Serial.println("Sending message");
    }  
};
