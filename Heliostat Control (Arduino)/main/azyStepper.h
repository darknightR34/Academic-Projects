#ifndef azyStepper_h
#define azyStepper_h

#include <Arduino.h>
#include <AccelStepper.h>

class azyStepper{
  private:
    AccelStepper stepper = AccelStepper();
    int LIM_SW;
    long homePos;
    double currentPos;
    bool homeCheck;
    bool powerState = true;
    int msValue = 2; // half step
    float convFactor = (200*msValue)/60.0;
  public:
    azyStepper(int _PULSE,int _DIR, int _LIM_SW);

    bool homingSeq(unsigned long timeToWait);
    
    void moveMotor(float stepRotate, float rpm);
};

#endif