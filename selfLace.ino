#include <Stepper.h>

#include <Adafruit_MotorShield.h>
#include <Servo.h>
#include <Wire.h>
//#include "utility/Adafruit_PWMServoDriver.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_StepperMotor *motor1 = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *motor2 = AFMS.getStepper(200, 2);
int buttonPin1 = 7;
int buttonPin2 = 6;
void setup() {
  Serial.begin(19200);
  AFMS.begin();
  motor1->setSpeed(250);
   motor2->setSpeed(250);
  Serial.println("Startup");
   pinMode(buttonPin1, INPUT_PULLUP);
    pinMode(buttonPin2, INPUT_PULLUP);
}

void tight() {

  motor1->step(1000, FORWARD, DOUBLE);
  Serial.println("tightening");
}

void loose() {

  motor1->step(1000, BACKWARD, DOUBLE);

  Serial.println("loosening");
}

void stopr() {

  motor1->release();
  Serial.println("stopped");

}
void loop() {
   if (digitalRead(buttonPin1) == LOW) {
    Serial.println("Tight");
    motor1->step(600, FORWARD, SINGLE);
    Serial.println("b1");
   }
    if (digitalRead(buttonPin2) == LOW) {
    Serial.println("b2");
     Serial.println("Loose");
    motor1->step(600, BACKWARD, SINGLE);
   }
// motor2->step(5000, FORWARD, DOUBLE); 
  char c = Serial.read();
//  if (c == 't') {
//    Serial.println("Tight");
//    motor1->step(5, FORWARD, SINGLE);
//  }
//  if (c == 'l') {
//    Serial.println("Loose");
//    motor1->step(5, BACKWARD, SINGLE);
//  }
//  if (c == 'r') {
//    Serial.println("Release");
//    motor1->release();
//  }

if (c == 't') {
    Serial.println("Tight");
    motor2->step(5000, FORWARD, DOUBLE);
  }
  if (c == 'l') {
    Serial.println("Loose");
    motor2->step(500, BACKWARD, DOUBLE);
  }
  if (c == 'r') {
    Serial.println("Release");
    motor2->release();
  }

  Serial.println(millis());
  delay(250);
}
