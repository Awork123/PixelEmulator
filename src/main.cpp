#include <MsgEmu.h>
#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <Potentiometer.h>
#include <Joystick.h>

Joystick joystick(39, 19);
MsgEmu message(4444, 7007);
Potentiometer potentiometer(34);

const char * ssid = "HakunaMatata";
const char * password = "HoejWork";

/* We start our program with connection to our wifi. If a connection is found it prints it is found and 
sends a message saying 'wifi conncected'*/ 
void setup() {
  Serial.begin(9600);
  joystick.message = &message;
  potentiometer.message = &message;
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFI failed");
    while(1) {
    }
  } 

  if (WiFi.isConnected()) {
    Serial.println("WiFi connected");
    message.MessageToPixel("Wifi is conncted");
   
  }
}

void loop (){
  joystick.loop();
  potentiometer.loop();
}