#ifndef B7BE3D5E_576D_4583_B597_8983169B4E53
#define B7BE3D5E_576D_4583_B597_8983169B4E53

#include <MsgEmu.h>
#include <Arduino.h>

class Joystick{   
    public:
    int joyXAxis; 
    int joyYAxis; 
    int buttonPress; 
    int tolerance = 400;
    int preValue1;
    int preValue2;
    int xSensorValue;
    int ySensorValue;
    int speedStage = 1;

    Joystick (int joyXAxis, int joyYaxis, int buttonPress){
        
        this->buttonPress = buttonPress;
        pinMode(buttonPress, INPUT_PULLUP);
        pinMode(joyXAxis, INPUT);
        pinMode(joyYAxis, INPUT);
        this->joyXAxis = joyXAxis;
        this->joyYAxis = joyYAxis;    
    }

    /* To increase the speed, we use a method, that adds 1 to an int called Speedstage, if the value is less than 9.
    To decrease the speed, we subtracts 1 from the same Speedstage int, if the value is greater than 1.
    This will be elaborated later, by the loop method.
    We choose 9 and 1, as it was the highest and lowest the pixel server would go.*/
    void increaseSpeed() {
      if (speedStage < 9) {
                speedStage = speedStage +1;
            }
            else {
            }
          message.MessageToPixel("speed " + speedStage);
    }

    void decreaseSpeed() {
      if (speedStage > 1) {
                speedStage = speedStage - 1;
            }
            else {
            }
          message.MessageToPixel("speed " + speedStage);
    }

    /* In our methods for controlling the movement, we send our string to the messageToPixel class, where it's send to the UDP
    We also set the prevalue1 (1 being the synonym for x, in this case) equal to the current xsensorvalue.*/ 
    void printXHigh (){
    preValue1 = xSensorValue;
    message.MessageToPixel("move up");
    }

    void printXLow(){
    preValue1 = xSensorValue;
    Serial.println("down!");
    message.MessageToPixel("move down");
    
    }

    /*Sadly, our yaxis on the joystick wasn't functioning correctly, and we therefore commentared it out.
    /* 

    /* void printYHigh(){
    preValue2 = ySensorValue;
    Serial.println("Right!");
    }
    void printYLow(){
    preValue2 = ySensorValue;
    Serial.println("left!!");
    } */ 


void loop (){

  ySensorValue = analogRead(joyYAxis);
  xSensorValue = analogRead(joyXAxis);
  
  if (xSensorValue > (preValue1 + tolerance)) {
    if (map(analogRead(joyXAxis), 0, 4095, -100, 100) > 0) {
      printXHigh();
      increaseSpeed();
    }
    else if (map(analogRead(joyXAxis), 0, 4095, -100, 100) < 0) {
      decreaseSpeed();
    }
  } 
  else if (xSensorValue < (preValue1 - tolerance)) {
    if (map(analogRead(joyXAxis), 0, 4095, -100, 100) < 0 ) {
      printXLow();
      increaseSpeed();
    }
    else if (map(analogRead(joyXAxis), 0, 4095, -100, 100) > -20 ) {
      decreaseSpeed();
    }
  } 
  else {
    xSensorValue = preValue1;
  }

  /* if (ySensorValue > (preValue2 + tolerance) && map(analogRead(joyYAxis), 0, 4095, -100, 100) > 0) {
    printYHigh(); 
  } else if (ySensorValue < (preValue2 - tolerance) && map(analogRead(joyYAxis), 0, 4095, -100, 100) < 0) {
    printYLow();
  } 
  else {
    ySensorValue = preValue2;
  } */ 

  /* wewe
  */ 
 
 if(digitalRead(buttonPress) == LOW){
   Serial.println("Slam!!");
    } 
}
  
}; 
#endif /* B7BE3D5E_576D_4583_B597_8983169B4E53 */