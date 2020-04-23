#ifndef B7BE3D5E_576D_4583_B597_8983169B4E53
#define B7BE3D5E_576D_4583_B597_8983169B4E53

#include <MsgEmu.h>
#include <Arduino.h>


class Joystick{   
    public:
    MsgEmu *message;
    int joyXAxis; 
    int buttonPress; 
    int tolerance = 300;
    int preValue;
    int xSensorValue;

    Joystick (int joyXAxis, int buttonPress){
        
        this->buttonPress = buttonPress;
        pinMode(buttonPress, INPUT_PULLUP);
        pinMode(joyXAxis, INPUT);
        this->joyXAxis = joyXAxis;
    }

    void increaseSpeed() { 
         message->MessageToPixel("speed up");
    }

    void decreaseSpeed() { 
        message->MessageToPixel("speed down");
    }

    void printXHigh (){
    preValue = xSensorValue;
    message->MessageToPixel("move up");
    }

    void printXLow(){
    preValue = xSensorValue;
    message->MessageToPixel("move down");
    }

void loop (){
  xSensorValue = analogRead(joyXAxis);

  if (map(analogRead(joyXAxis), 0, 4095, 0, 10) == 10){
    printXHigh();
    delay(200);
  }

  if (map(analogRead(joyXAxis), 0, 4095, 0, 10) == 0){
    printXLow();
    delay(200);
  }
  if (xSensorValue > (preValue + tolerance)) {
    if (map(analogRead(joyXAxis), 0, 4095, 0, 10) > 7) {
      printXHigh();
      increaseSpeed();
    }
    else if (map(analogRead(joyXAxis), 0, 4095, 0, 10) < 3) {
      decreaseSpeed();
    }
  } 

  else if (xSensorValue < (preValue - tolerance)) {
    if (map(analogRead(joyXAxis), 0, 4095, 0, 10) < 3 ) {
      printXLow();
      increaseSpeed();
    }
    else if (map(analogRead(joyXAxis), 0, 4095, 0, 10) > 7 ) {
      decreaseSpeed();
    }
  } 

  else {
    xSensorValue = preValue;
  }

 if(digitalRead(buttonPress) == LOW){
   message->MessageToPixel("launch");
   delay(100);
    } 
}
  
}; 
#endif /* B7BE3D5E_576D_4583_B597_8983169B4E53 */