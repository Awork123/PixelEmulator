#ifndef E7954E57_9A81_4AAF_BD3B_2E57789F10F1
#define E7954E57_9A81_4AAF_BD3B_2E57789F10F1

#include <Arduino.h>
#include <MsgEmu.h>

class Potentiometer{
    public:
    MsgEmu *message;
    int potentiometerpin;
    int sensorvalue;
    int preValuePotentio;
    int sensitivity = 409;
    int speedStage = 1;

    Potentiometer(int potentiometerpin){
        this->potentiometerpin = potentiometerpin;
        pinMode(potentiometerpin, INPUT);
        }

        void increase() {
            if (speedStage < 9) {
                speedStage = speedStage +1;
                message->MessageToPixel("Speed " + speedStage);
            }
            else {

            }
            preValuePotentio = sensorvalue;
            // Serial.println(speedStage);
        }

        void decrease() {
            if (speedStage > 1) {
                speedStage = speedStage - 1;
                message->MessageToPixel("Speed " + speedStage);
            }
            else {

            }
            preValuePotentio = sensorvalue;
            // Serial.println(speedStage);
    }

    void loop() {
        sensorvalue = analogRead(potentiometerpin);

        if (sensorvalue > preValuePotentio + sensitivity){
            increase();
        }
        else if (sensorvalue < preValuePotentio-sensitivity) {
            decrease();
        }
        else {
            sensorvalue=preValuePotentio;
        }
    }
};
 #endif /* E7954E57_9A81_4AAF_BD3B_2E57789F10F1 */