#include <MsgEmu.h>
#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <Potentiometer.h>
#include <Joystick.h>

Joystick joystick(39, 35, 19);
MsgEmu message(7000, 7007);
Potentiometer potentiometer(34);

const char * ssid = "HakunaMatata";
const char * password = "HoejWork";

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
  }
}

void loop (){
  joystick.loop();
  potentiometer.loop();
}