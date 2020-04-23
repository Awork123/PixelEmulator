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
         message->MessageToPixel("speed up");
    }

    void decreaseSpeed() { 
        message->MessageToPixel("speed down");
    }

    /* In our methods for controlling the movement, we send our string to the messageToPixel class, where it's send to the UDP
    We also set the prevalue1 (1 being the synonym for x, in this case) equal to the current xsensorvalue.*/ 
    void printXHigh (){
    preValue1 = xSensorValue;
    message->MessageToPixel("move up");
    }

    void printXLow(){
    preValue1 = xSensorValue;
    message->MessageToPixel("move down");
    
    }


void loop (){

  ySensorValue = analogRead(joyYAxis);
  xSensorValue = analogRead(joyXAxis);

  if (map(analogRead(joyXAxis), 0, 4095, -100, 100) == 100){
    printXHigh();
    delay(200);
  }

  if (map(analogRead(joyXAxis), 0, 4095, -100, 100) == -100){
    printXLow();
    delay(200);
  }
  if (xSensorValue > (preValue1 + tolerance)) {
    if (map(analogRead(joyXAxis), 0, 4095, 0, 10) > 7) {
      printXHigh();
      increaseSpeed();
    }
    else if (map(analogRead(joyXAxis), 0, 4095, 0, 10) < 3) {
      decreaseSpeed();
    }
  } 
  else if (xSensorValue < (preValue1 - tolerance)) {
    if (map(analogRead(joyXAxis), 0, 4095, 0, 10) < 3 ) {
      printXLow();
      increaseSpeed();
    }
    else if (map(analogRead(joyXAxis), 0, 4095, 0, 10) > 7 ) {
      decreaseSpeed();
    }
  } 
  else {
    xSensorValue = preValue1;
  }

 if(digitalRead(buttonPress) == LOW){
   message->MessageToPixel("launch");
   delay(100);
    } 
}
  
}; 
#endif /* B7BE3D5E_576D_4583_B597_8983169B4E53 */