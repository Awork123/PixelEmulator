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
    int sensitivity = 250;

    Potentiometer(int potentiometerpin){
        this->potentiometerpin = potentiometerpin;
        pinMode(potentiometerpin, INPUT);
        }
       
    void loop() {
        sensorvalue = analogRead(potentiometerpin);

        if (sensorvalue > preValuePotentio + sensitivity){
            message->MessageToPixel("Speed 9");
            preValuePotentio = sensorvalue;
        
        }else if (sensorvalue < preValuePotentio-sensitivity) {
            message->MessageToPixel("Speed 1");
            preValuePotentio = sensorvalue;
        } else {
            sensorvalue=preValuePotentio;
        }
    }
};
#endif /* E7954E57_9A81_4AAF_BD3B_2E57789F10F1 */
