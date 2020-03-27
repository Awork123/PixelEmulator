#include <Arduino.h>
#include <Message.h>

Message Message(7000, 7007); 
class JoystickX{   
    public:
    int joyXAxis; 
    int buttonPressX; 
    int tolerance = 250;
    int preValue1;
  //  int preValue2;
    int xSensorValue;
   

    Joystick (int joyXAxis, int buttonPress){
        
        this->buttonPress = buttonPress;
        pinMode(buttonPressX, INPUT_PULLUP);
        pinMode(joyXAxis, INPUT);
        this->joyXAxis = joyXAxis;
    }

    void printXHigh (){
    Serial.printf("X_AXIS IS HIGHER AND IS: ");
    Serial.println(xSensorValue);
    preValue1 = xSensorValue;
    }
    void printXLow(){
    Serial.printf("X_AXIS IS LOWER AND IS: ");
    Serial.println(xSensorValue);
    preValue1 = xSensorValue;
    }
    
    void printYHigh(){
    Serial.printf("Y_AXIS IS HIGHER AND IS: ");
    Serial.println(ySensorValue);
    preValue2 = ySensorValue;
    }
    void printYLow(){
    Serial.printf("Y_AXIS IS LOWER AND IS: ");
    Serial.println(ySensorValue);
    preValue2 = ySensorValue;

    }

void loop (){
  /*
delay(1000);
  if(abs(analogRead(joyXAxis)-preValue1 > tolerance || abs(analogRead(joyYAxis)-preValue2) > tolerance)) {
    Serial.println(map(analogRead(joyXAxis), 0, 4095, -100, 100));
    Serial.println(map(analogRead(joyYAxis) ,0, 4095, -100, 100));
  }
  */

/
 // ySensorValue = analogRead(joyYAxis);
  xSensorValue = analogRead(joyXAxis);
  if (xSensorValue > (preValue1 + tolerance)) {
    printXHigh();
  } else if (xSensorValue < (preValue1 - tolerance)) {
    printXLow();
  } 
  /* else {
    xSensorValue = preValue1;
  }
  if (ySensorValue > (preValue2 + tolerance)) {
    printYHigh();
    
  } else if (ySensorValue < (preValue2 - tolerance)) {
    printYLow();
  }
  else {
    ySensorValue = preValue2;
  } 
/


/* 
    int preValue1 = analogRead(joyYAxis);
    int preValue2 = analogRead(joyXAxis);
    delay(3000);
    Serial.println(preValue1);
    Serial.println(preValue2);
  if (abs(analogRead(joyYAxis)-preValue1) > tolerance){
    if (preValue1 < 500) {
      Serial.println(map(analogRead(joyYAxis), 0, 4095, -100, 100));
      preValue1 = analogRead(joyYAxis);
      Message.sendMsgTopxlEmu("moveleft");
      
  }
  else if (preValue1 > 3500) {
    Message.sendMsgTopxlEmu("moveright");
  }

Ø
    if(abs(analogRead(joyXAxis)-preValue2) > tolerance){
    // Serial.println(map(analogRead(joyXAxis), 0, 4095, -100, 100));
    preValue2 = analogRead(joyXAxis); 
    Message.sendMsgTopxlEmu("moveup");
  }

 if(digitalRead(buttonPress) == LOW){
   Message.sendMsgTopxlEmu("init 10 10");
    }
    */
}
  
}; 