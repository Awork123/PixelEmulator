#ifndef E4E0657A_5F9F_4931_8314_89A06BCA1AB3
#define E4E0657A_5F9F_4931_8314_89A06BCA1AB3
#include "WiFi.h"
#include <Arduino.h>
#include "AsyncUDP.h"

class MsgEmu {
    public:
    int port;
    int udpPort;
    AsyncUDP udp;
    
    MsgEmu(int port, int udpPort){
        this->port = port;
        this->udpPort = udpPort; 
    }

    void MessageToPixel (String msg) {
    udp.writeTo((const uint8_t*)msg.c_str(), msg.length(), IPAddress(192,168,0,20), port);
    Serial.println(msg);
    }  
};
#endif /* E4E0657A_5F9F_4931_8314_89A06BCA1AB3 */
