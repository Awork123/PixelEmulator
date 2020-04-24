#ifndef B7BE3D5E_576D_4583_B597_8983169B4E53
#define B7BE3D5E_576D_4583_B597_8983169B4E53

#include <MsgEmu.h>
#include <Arduino.h>

class Joystick{ 
    public:
    MsgEmu *message;
    int joyYAxis; 
    int buttonPress; 
    int tolerance = 100;
    int preValue;
    int ySensorValue;

    Joystick (int joyYAxis, int buttonPress){
        
        this->buttonPress = buttonPress;
        pinMode(buttonPress, INPUT_PULLUP);
        pinMode(joyYAxis, INPUT);
        this->joyYAxis = joyYAxis;
    }

    void increaseSpeed() { 
         message->MessageToPixel("speed up");
    }

    void decreaseSpeed() { 
        message->MessageToPixel("speed down");
    }

    void printXHigh (){
    preValue = ySensorValue;
    message->MessageToPixel("move up");
    }

    void printXLow(){
    preValue = ySensorValue;
    message->MessageToPixel("move down");
    }

void loop (){
  ySensorValue = analogRead(joyYAxis);

  /* If the joystick is pressed all the way down or up, it will constantly send the message to move up or down*/ 
  if (map(analogRead(joyYAxis), 0, 4095, 0, 10) == 10){
    printXHigh();
  }

  if (map(analogRead(joyYAxis), 0, 4095, 0, 10) == 0){
    printXLow();
  }
/* If the joystick is tilted upwards, it will send the message 'move up'. Furthermore, the joystick saves the 
analogRead value, and checks whether the new newly read analogRead is higher or lower, with a tolerance. 
If the joystick is tilted upwards, and the newly read analogRead is higher, it will send a 'speed up', corresponding with 
the joystick being tilted more than before. However, if the newly read analogRead is lower, 
and the joystick is tilted up, it will send 'speed down', corresponding with the joystick moving back to the middle*/ 
  if (map(analogRead(joyYAxis), 0, 4095, 0, 10) > 6){
    if (ySensorValue > (preValue + tolerance)) {
      increaseSpeed();
    }
    else if (ySensorValue < (preValue - tolerance)){
      decreaseSpeed();
    }
    printXHigh();
  }
 /* If the joystick is tilted downwards, it will send the message 'move down'. Using the same way of saving and 
 checking the new AnalogRead, we can send 'speed down', if the joystick is tilted downwards, and moving back towards the middle.
 In the same notion, it will send 'speed up', if the joystick is being tilted more than last*/  
  if (map(analogRead(joyYAxis), 0, 4095, 0, 10) < 4){
    if (ySensorValue > (preValue + tolerance)){
      decreaseSpeed();
    }
    else if (ySensorValue < (preValue - tolerance)) {
      increaseSpeed();
    }
    printXLow();
  }
  else {
    ySensorValue = preValue;
  }
/* If the button is clicked, it will send 'Launch' */ 
 if(digitalRead(buttonPress) == LOW){
   message->MessageToPixel("launch");
   delay(100);
    } 

    delay(100);
}
  
}; 
#endif /* B7BE3D5E_576D_4583_B597_8983169B4E53 */