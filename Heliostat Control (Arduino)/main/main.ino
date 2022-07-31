#include <Arduino.h>
#include "elevStepper.h"
#include "azyStepper.h"

// Elevation motor 1
#define MOTOR_STEPS 200
#define DIR1 14 //13
#define STEP1 12 //12
#define MS11 13 //14
const int LIM_SW1  = 33; //23;

// Elevation motor 2
#define DIR2 25 //26
#define STEP2 26 //25
#define MS12 27 //27
const int LIM_SW2 = 32; //18;

// Elevation motor 3
#define DIR3 16 //32
#define STEP3 17 //19
#define MS13 5 //33
const int LIM_SW3 = 35; //35;

// Elevation motor 4
#define DIR4 15 //15
#define STEP4 2 //2
#define MS14 4 //4
const int LIM_SW4 = 34; //34;

// Azymuth motor
#define DIR5 22 //22
#define PULSE5 21 //21
const int LIM_SW5 = 39; //39;

elevStepper stepper1(MOTOR_STEPS,DIR1,STEP1,MS11,LIM_SW1);
elevStepper stepper2(MOTOR_STEPS,DIR2,STEP2,MS12,LIM_SW2);
elevStepper stepper3(MOTOR_STEPS,DIR3,STEP3,MS13,LIM_SW3);
elevStepper stepper4(MOTOR_STEPS,DIR4,STEP4,MS14,LIM_SW4);
azyStepper stepper5(PULSE5, DIR5,LIM_SW5);

bool homeTest[5];

void setup(){
  //E1
  pinMode(DIR1, OUTPUT);
  pinMode(STEP1, OUTPUT);
  pinMode(MS11, OUTPUT);
  pinMode(LIM_SW1,INPUT);
  //E2
  pinMode(DIR2, OUTPUT);
  pinMode(STEP2, OUTPUT);
  pinMode(MS12, OUTPUT);
  pinMode(LIM_SW2,INPUT);
  //E3
  pinMode(DIR3, OUTPUT);
  pinMode(STEP3, OUTPUT);
  pinMode(MS13, OUTPUT);
  pinMode(LIM_SW3,INPUT);
  //E4
  pinMode(DIR4, OUTPUT);
  pinMode(STEP4, OUTPUT);
  pinMode(MS14, OUTPUT);
  pinMode(LIM_SW4,INPUT);
  //A1
  pinMode(DIR5, OUTPUT);
  pinMode(PULSE5, OUTPUT);
  pinMode(LIM_SW5, INPUT);

  Serial.begin(9600);
  Serial.println("Beginning...");

  homing(5000);
  delay(1000);
  //testRun();
}

void loop(){
  if (Serial.available() != 0 && Serial.available() != 1){
    char command = Serial.read();
    Serial.println("You entered command: ");
    Serial.println(command);

    if (command == 'h' || command == 'H'){
      float timeInMS = Serial.parseInt();
      homing(timeInMS);
    }
    else if (command == 'e'|| command == 'E'){
      float stepsToMove = Serial.parseInt();
      float rpm = Serial.parseInt();
      moveAllElev(stepsToMove, rpm);
      delay(1000);
    }
    else if(command == 'a'|| command == 'A'){
      float stepsToMove = Serial.parseInt();
      float rpm = Serial.parseInt();
      moveAzy(stepsToMove, rpm);
    }
  }
}

void homing(float timeInMS){
  homeTest[0] = stepper1.homingSeq(timeInMS);
  if(homeTest[0] == true){
   Serial.println("Elevation Motor (1) Homed!");
  }
  else{
    Serial.println("Elevation Motor (1) Timed Out!");
  }
  delay(1000);

  homeTest[1] = stepper2.homingSeq(timeInMS);
  if(homeTest[1] == true){
   Serial.println("Elevation Motor (2) Homed!");
  }
  else{
    Serial.println("Elevation Motor (2) Timed Out!");
  }
  delay(1000);

  homeTest[2] = stepper3.homingSeq(timeInMS);
  if(homeTest[2] == true){
   Serial.println("Elevation Motor (3) Homed!");
  }
  else{
    Serial.println("Elevation Motor (3) Timed Out!");
  }
  delay(1000);

  homeTest[3] = stepper4.homingSeq(timeInMS);
  if(homeTest[3] == true){
   Serial.println("Elevation Motor (4) Homed!");
  }
  else{
    Serial.println("Elevation Motor (4) Timed Out!");
  }
  delay(1000);

  homeTest[4] = stepper5.homingSeq(timeInMS);
  if(homeTest[4] == true){
   Serial.println("Azymuth Motor (5) Homed!");
  }
  else{
    Serial.println("Azymuth Motor (5) Timed Out!");
  }
  delay(1000);
}

void moveAllElev(float stepsToMove, float rpm){
  stepper1.moveMotor(stepsToMove, rpm);
  delay(1000);
  stepper2.moveMotor(stepsToMove, rpm);
  delay(1000);
  stepper3.moveMotor(stepsToMove, rpm);
  delay(1000);
  stepper4.moveMotor(stepsToMove, rpm);
  delay(1000);
}

void moveAzy(float stepsToMove, float rpm){
  stepper5.moveMotor(stepsToMove, rpm);
  delay(1000);
}

void testRun(){
  moveAllElev(100, 5);
  moveAzy(100,5);
  moveAllElev(-50,3);
  moveAzy(-50,3);
}
