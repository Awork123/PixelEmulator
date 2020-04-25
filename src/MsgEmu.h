/*We had to used the ifndef and define, to check whether the included classes were defined.
Due to difficulties doing it ourselves, we had to use a extension called "C/C++ Include Guard" */ 

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

    /*This is the functions that sends our message. We do this by using the udp.writeto
    We also print the message, for some whitebox testing*/ 
    void MessageToPixel (String msg) {
    udp.writeTo((const uint8_t*)msg.c_str(), msg.length(), IPAddress(YOUR IP!), port);
    Serial.println(msg);
    }  
};
#endif /* E4E0657A_5F9F_4931_8314_89A06BCA1AB3 */
