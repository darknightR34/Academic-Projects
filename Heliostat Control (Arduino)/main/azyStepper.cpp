#include "azyStepper.h"

azyStepper::azyStepper(int _PULSE,int _DIR, int _LIM_SW){
  stepper = AccelStepper(1, _PULSE, _DIR);
  LIM_SW = _LIM_SW;
}

bool azyStepper::homingSeq(unsigned long timeToWait){
  unsigned long startTime = millis();
  unsigned long waitedTime;

  while(digitalRead(LIM_SW) == false ){
    stepper.setAcceleration(100);
    stepper.setMaxSpeed(30 * convFactor);
    stepper.setSpeed(-30*convFactor);
    stepper.runSpeed();
    waitedTime = (millis() - startTime);

    if (waitedTime >= timeToWait){
      //Serial.println("Timed Out!");
      return false;
      break;
    }
  }
  
  delay(1000);
  stepper.moveTo((stepper.currentPosition())+10);
  stepper.runToPosition();
  delay(1000);
  
  stepper.setSpeed(-5 * convFactor);
  while(digitalRead(LIM_SW) == false ){
    stepper.runSpeed();
       
  }

  stepper.setCurrentPosition(0);
  homePos = stepper.currentPosition();
  currentPos = homePos;
  //Serial.println("Homed!");
  stepper.setSpeed(20 * convFactor);
  return true;
}

void azyStepper::moveMotor(float stepRotate, float rpm){
  const double maxRot = 1595;
  double lowerLim = homePos;
  double upperLim = homePos + maxRot;
  double boundCheck = currentPos + stepRotate;

  if (boundCheck >= lowerLim && boundCheck <= upperLim){
    stepper.setSpeed(rpm * convFactor);
    stepper.moveTo(stepRotate + stepper.currentPosition());
    stepper.runToPosition();
    currentPos += stepRotate;
    Serial.println("Current Pos");
    Serial.println(currentPos);
    Serial.println("Home Pos");
    Serial.println(homePos);
  }

  else {
    Serial.println("Out of Bounds");
  }
}