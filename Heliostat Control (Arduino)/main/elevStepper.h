#ifndef elevStepper_h
#define elevStepper_h

#include <Arduino.h>
#include  "A4988.h"



class elevStepper{
  private:
    A4988 stepper = A4988(200,8,9,10);
    int LIM_SW;
    long homePos;
    //long stepToDeg = 360/(MOTOR_STEPS*2);
    double currentPos;
    bool homeCheck;
    bool powerState = true;

  public:
    elevStepper(int _MOTOR_STEPS, int _DIR, int _STEP, int _MS1, int _LIM_SW);
    bool homingSeq(unsigned long timeToWait);
    void moveMotor(float stepRotate, float rpm);
    void dangerSeq(float rpm);
    void setElevation(float stepRotate, float rpm);
};

#endif