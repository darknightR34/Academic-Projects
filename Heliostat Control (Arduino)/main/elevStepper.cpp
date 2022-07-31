#include "elevStepper.h"

elevStepper::elevStepper(int _MOTOR_STEPS, int _DIR, int _STEP, int _MS1, int 
_LIM_SW){
  stepper = A4988(_MOTOR_STEPS, _DIR, _STEP, _MS1);
  LIM_SW = _LIM_SW;
}

bool elevStepper::homingSeq(unsigned long timeToWait){
  stepper.begin(30,1);
  unsigned long startTime = millis();
  unsigned long waitedTime;
  stepper.setRPM(30);
  while(digitalRead(LIM_SW) == false){
    stepper.move(-1);
    delay(10);

    waitedTime = (millis() - startTime);

    if (waitedTime >= timeToWait){
      //Serial.println("Timed Out!");
      return false;
      break;
    }
  }
  
  delay(1000);

  stepper.setRPM(30);
  stepper.move(10);
  delay(1000);
  
  stepper.setRPM(5);
  while(digitalRead(LIM_SW) == false){
    stepper.move(-1);
     delay(60);
  }

  homePos = stepper.getStepsCompleted();
  homePos = homePos;
  currentPos = homePos;
  //Serial.println("Homed!");
  stepper.setRPM(20);
  return true;
}

void elevStepper::moveMotor(float stepRotate, float rpm){
  double desiredPos = stepRotate;
  const double maxRot = 400;
  double lowerLim = homePos;
  double upperLim = homePos + maxRot;
  double boundCheck = currentPos + desiredPos;

  stepper.setRPM(rpm);
  if (boundCheck >= lowerLim && boundCheck <= upperLim){
    stepper.move(desiredPos);
    currentPos += desiredPos;
    Serial.println("Current Pos");
    Serial.println(currentPos);
    Serial.println("Home Pos");
    Serial.println(homePos);
  }
  else {
    Serial.println("Out of Bounds");
  }
}

void elevStepper::dangerSeq(float rpm){
  long stepperOffset = 81;
  Serial.println("Attempting to move to safe position...");

  if (homeCheck == true){
    Serial.println("Moving to safe position...");
    moveMotor(((homePos - currentPos) + stepperOffset), rpm);
    Serial.println("Safe position reached");
  }
  else {
    Serial.println("Please make sure the motor is homed first");
  }
}

void elevStepper::setElevation(float stepRotate, float rpm){
  Serial.println("Attempting to change elevation angle...");
  if (homeCheck == true){
    Serial.println("Moving...");
    moveMotor(stepRotate, rpm);
    Serial.println("New elevation angle reached...");

  }
  else {
    Serial.println("Please make sure the motor is homed first");
  }
}