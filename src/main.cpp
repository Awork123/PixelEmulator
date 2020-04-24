/*We included the libraries wifi.h and asyncUDP.h. We also included our own classes*/ 
#include <MsgEmu.h>
#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <Potentiometer.h>
#include <Joystick.h>

/* As we were doing the Joystick, MesgEmu and Potentiometer in other classes, defined the pins, udpport and port
in our main.cpp, to make it easier to switch along the way */ 
Joystick joystick(39, 19);
MsgEmu message(4444, 7007);
Potentiometer potentiometer(34);

const char * ssid = "HakunaMatata";
const char * password = "HoejWork";

/* We start our program with connection to our wifi. If a connection is found it prints it is found and 
sends a message saying 'wifi conncected'. This is both for practical reasons, and for whiteboxtesting */ 

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

/* In our loop, we call for the loop in joystick and potentiomter, to make it easier to see whats happening */ 
void loop (){
  joystick.loop();
  potentiometer.loop();
}