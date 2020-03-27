/*#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
 // ssid = navnet på routeren
const char * ssid = "HakunaMatata";
// password = passwordet til wifiet
const char * password = "HoejWork";
 
 // er en class der bruges til at finde en udp (kan kaldes en funktion)
AsyncUDP udp;
 
 // hvilken port packet sender sender den til
int port = 7000;
// hvilken port packet sender skal sende fra
int udpPort = 7007;
 
 // x aksen er 35
int xaxis =35;
 // y aksen er 32
int yaxis =32;
  
int click =33;
 
int potentiometer = 34;
int sensorvalue;
bool preValue;
// hvor meget inputen skal ændres før den registrere
int trollerance = 100;
 
 // alt der kun køre 1 gang
void setup()
{
 
 // sætter de forskellige pinModes til hvad der skal ske og at der forventes et input fra DOIT32 microcontroller
pinMode(potentiometer, INPUT);
pinMode(xaxis, INPUT);
pinMode(yaxis, INPUT);
pinMode(click, INPUT_PULLUP);
 
 // Serial.begin(9600); skal skrives for at starte microcontrolleren, og 9600 er baud rate på esp32 devkit v1 (Doit32)
Serial.begin(9600);
 
    // starter wifi mode
    WiFi.mode(WIFI_STA);
    // connecter til wifi (wifi navn, password)
    WiFi.begin(ssid, password);
    // hvis wifi ikke connecter, print "wifi failed"
    // hvis dette sker, så delay 1 sekund, før den prøver igen
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
}
 
 
void sendMsgTopxlEmu (String msg) {
udp.writeTo((const uint8_t*)msg.c_str(), msg.length(), IPAddress(192,168,0,13), port);
Serial.println(msg);
}
 
 // alt inden i loop bliver ved med at kører rundt, indtil den bliver stoppet af en command
void loop()
{  
  
  //fordi microcontrolleren er analog, skal sensorens sættes til analog læsning af potentiometeret
  sensorvalue=analogRead(potentiometer);
  // hvis sensorværdien er større end den seneste værdig + tollerancen eller sensorværdien er mindre en den tidligere værdi - tollerancen, så skal sensorværdigen printes ud
  // og sensorværdien bliver den nye tidligere værdi
  // Hvis dette ikke bliver opfyldt bliver sensorværdien overskrevet af den tidligere værdi
  if(sensorvalue > preValue +trollerance || sensorvalue < preValue-trollerance){
    Serial.println(sensorvalue); // Test print
    preValue= sensorvalue;
  } else {
    sensorvalue =preValue;
    }
 
 // hvis værdien af den analoge værdi af x aksen er mindre end 10, bliver der sendt en besked til packet sender om at "move up"
 // eller hvis den analoge værdi af x aksen er større end 4090, bliver der sendt en besked til packet sender om at "move down"
 // eller hvis den analoge værdi af y aksen er større end 4090, bliver der sendt en besked til packet sender om at "move left"
 // eller hvis den analoge værdi af y aksen er mindre end 10, bliver der sendt en besked til packet sender om at "move right"
 // eller hvis der bliver klikket på tasten bliver der sendt en besked til packet sender om at starte med kordinaterne 10,10
 // ellers send en besked til packet sender om at stoppe
if(analogRead(xaxis) < 10 ) sendMsgTopxlEmu("moveup");
  else if(analogRead(xaxis) > 4090) sendMsgTopxlEmu("movedown");
  else if(analogRead(yaxis) > 4090) sendMsgTopxlEmu("moveleft");
  else if(analogRead(yaxis) < 10) sendMsgTopxlEmu("moveright");
  else if(digitalRead(click) < 1) sendMsgTopxlEmu("init 10 10");
    else sendMsgTopxlEmu("stop");
 
switch (map(analogRead(potentiometer),0,4095, 1, 10))
{
case 1:
  sendMsgTopxlEmu("speed 1");
    break;
case 2:
  sendMsgTopxlEmu("speed 2");
    break;
case 3:
  sendMsgTopxlEmu("speed 3");
    break;
case 4:
  sendMsgTopxlEmu("speed 4");
    break;
case 5:
  sendMsgTopxlEmu("speed 5");
    break;
case 6:
  sendMsgTopxlEmu("speed 6");
    break;
case 7:
  sendMsgTopxlEmu("speed 7");
    break;
case 8:
  sendMsgTopxlEmu("speed 8");
    break;
case 9:
  sendMsgTopxlEmu("speed 9");
    break;
default: 
  sendMsgTopxlEmu("speed 10");
    break;
}
 
// Test Print
Serial.print("click");
Serial.println(digitalRead(click));
Serial.print("X: ");
Serial.println(analogRead(xaxis));
Serial.print("Y: ");
Serial.println(analogRead(yaxis));
Serial.print("\n\n");
 
delay(500);
}
*/