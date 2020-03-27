#ifndef B7BE3D5E_576D_4583_B597_8983169B4E53
#define B7BE3D5E_576D_4583_B597_8983169B4E53

#include <MsgEmu.h>
#include <Arduino.h>

class Joystick{   
    public:
    MsgEmu *message;
    int joyXAxis; 
    int joyYAxis; 
    int buttonPress; 
    int tolerance = 250;
    int preValue1;
    int preValue2;
    int xSensorValue;
    int ySensorValue;

    Joystick (int joyXAxis, int joyYaxis, int buttonPress){
        
        this->buttonPress = buttonPress;
        pinMode(buttonPress, INPUT_PULLUP);
        pinMode(joyXAxis, INPUT);
        pinMode(joyYAxis, INPUT);
        this->joyXAxis = joyXAxis;
        this->joyYAxis = joyYAxis;  
        
    }
    void printXHigh (){
    Serial.printf("X_AXIS IS HIGHER AND IS: ");
    Serial.println(xSensorValue);
    preValue1 = xSensorValue;
    message->MessageToPixel("moveup");
    }
    void printXLow(){
    Serial.printf("X_AXIS IS LOWER AND IS: ");
    Serial.println(xSensorValue);
    preValue1 = xSensorValue;
    message->MessageToPixel("movedown");
    }
    void printYHigh(){
    Serial.printf("Y_AXIS IS HIGHER AND IS: ");
    Serial.println(ySensorValue);
    preValue2 = ySensorValue;
    message->MessageToPixel("moveright");
    }
    void printYLow(){
    Serial.printf("Y_AXIS IS LOWER AND IS: ");
    Serial.println(ySensorValue);
    preValue2 = ySensorValue;
    message->MessageToPixel("moveleft");
    }

void loop (){

  ySensorValue = analogRead(joyYAxis);
  xSensorValue = analogRead(joyXAxis);
  
  if (xSensorValue > (preValue1 + tolerance)) {
    printXHigh();
  } else if (xSensorValue < (preValue1 - tolerance)) {
    printXLow();
  } else {
    xSensorValue = preValue1;
  }

  if (ySensorValue > (preValue2 + tolerance)) {
    printYHigh(); 
  } else if (ySensorValue < (preValue2 - tolerance)) {
    printYLow();
  } else {
    ySensorValue = preValue2;
  } 

 if(digitalRead(buttonPress) == LOW){
   message->MessageToPixel("init 10 10");
    } 
}
  
}; 
#endif /* B7BE3D5E_576D_4583_B597_8983169B4E53 */
