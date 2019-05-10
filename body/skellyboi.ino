#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"
#include <Servo.h>

Servo face;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *rightArm = AFMS.getMotor(3);
Adafruit_DCMotor *leftArm = AFMS.getMotor(1);
Adafruit_DCMotor *rightLeg = AFMS.getMotor(4);
Adafruit_DCMotor *leftLeg = AFMS.getMotor(2);
void setup() {
  // put your setup code here, to run once:
  AFMS.begin();
  face.attach(9);
  face.write(180);
}

void raiseAppendage(Adafruit_DCMotor *motor, int movingSpeed, int lowerSpeed) {
  motor->setSpeed(movingSpeed);
  motor->run(FORWARD);
  delay(1000);
  motor->setSpeed(lowerSpeed);
  delay(1000);
  motor->run(RELEASE);
}

void bothUp(Adafruit_DCMotor *app1, Adafruit_DCMotor *app2, int upSpeed, int downSpeed) {
  app1->setSpeed(upSpeed);
  app2->setSpeed(upSpeed);
  app1->run(FORWARD);
  app2->run(FORWARD);
  delay(1000);
  app1->setSpeed(downSpeed);
  app2->setSpeed(downSpeed);
  delay(500);
  app1->run(RELEASE);
  app2->run(RELEASE);
}

void crossBody(Adafruit_DCMotor *arm, Adafruit_DCMotor *leg, int upSpeedArm, int upSpeedLeg, int downSpeedArm, int downSpeedLeg) {
  arm->setSpeed(upSpeedArm);
  leg->setSpeed(upSpeedLeg);
  arm->run(FORWARD);
  leg->run(FORWARD);
  delay(1000);
  arm->setSpeed(downSpeedArm);
  leg->setSpeed(downSpeedLeg);
  delay(500);
  arm->run(RELEASE);
  arm->run(RELEASE);
}

void chatter(Servo s) {
  for(int i = 0; i < 10; i++){
    s.write(0);
    delay(200);
    s.write(90);
    delay(200);
  }
}

void loop() {
  chatter(face);
  raiseAppendage(rightArm, 40, 5);
  raiseAppendage(leftArm, 40, 5);
  bothUp(rightArm, leftArm, 40, 5);
  bothUp(rightLeg, leftLeg, 100, 60);
  crossBody(rightArm, leftLeg, 40, 100, 5, 40);
  crossBody(leftArm, rightLeg, 40, 100, 5, 40);
}
