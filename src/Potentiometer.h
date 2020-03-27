/*#include <Arduino.h>
#include <Message.h>

class Potentiometer{
    public:
    int potentiometer;
    int sensorvalue;
    int preRead;
    int sensitivity = 100;
    Message *messageP;

         Potentiometer(int potentiometer){
            
            this->potentiometer = potentiometer;
            pinMode(potentiometer, INPUT);
        }
       
        
        void loop() {
        sensorvalue = analogRead(potentiometer);

        Serial.println(sensorvalue);
        Serial.println("Reading potentiometer"); //Test
        delay(500);

        if (sensorvalue > preRead + sensitivity){
            messageP->sendMsgTopxlEmu("Speed 3");
            preRead = sensorvalue;
            }
        else {
            sensorvalue=preRead;
            }

        if (sensorvalue < preRead-sensitivity) {
            messageP->sendMsgTopxlEmu("Speed 1");
            preRead = sensorvalue;
        }
        else {
            sensorvalue=preRead;
        }

        }
};
*/