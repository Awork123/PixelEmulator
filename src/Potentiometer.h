#ifndef E7954E57_9A81_4AAF_BD3B_2E57789F10F1
#define E7954E57_9A81_4AAF_BD3B_2E57789F10F1

#include <Arduino.h>
#include <MsgEmu.h>

class Potentiometer{
    public:
    MsgEmu *message;
    int potentiometerpin;

    Potentiometer(int potentiometerpin){
        this->potentiometerpin = potentiometerpin;
        pinMode(potentiometerpin, INPUT);
        }

        void increase() {
            message->MessageToPixel("move right");
        }

        void decrease() {
            message->MessageToPixel("move left");
    }

    void loop() {
        if (map(analogRead(potentiometerpin), 0, 4095, 0, 10) == 10){
            increase();
            delay(100);
        }
        else if (map(analogRead(potentiometerpin), 0, 4095, 0, 10) == 0) {
            decrease();
            delay(100);
        }
    }
}; 
 #endif /* E7954E57_9A81_4AAF_BD3B_2E57789F10F1 */