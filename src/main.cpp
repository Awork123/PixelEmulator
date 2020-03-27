#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <Potentiometer.h>
#include <Joystick.h>

Joystick Joystick(39, 35, 19);
//Potentiometer Potentiometer(34);
const char * ssid = "HakunaMatata";
const char * password = "HoejWork";

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFI failed");
    while(1) {
    }
  }
}


void loop (){
  Joystick.loop();
  //Potentiometer.loop();
}

