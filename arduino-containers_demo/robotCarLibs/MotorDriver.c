/**
 * @file MotorDriver.c
 * @author david
 * @brief A library providing functions to control an arduino car using the motor controller L298N.
 */

#ifdef __cplusplus
  extern "C" {
#endif
#include "MotorDriver.h"


// The pins of an arduino (mega in this example) that are connected to the L298N motor controller.

// PMW pins
#define LEFT_ENGINE_SPEED_PIN 2 
#define RIGHT_ENGINE_SPEED_PIN 7 

// Digital IO pins
#define LEFT_ENGINE_FORWARD_PIN 4
#define LEFT_ENGINE_REVERSE_PIN 3
#define RIGHT_ENGINE_FORWARD_PIN 5
#define RIGHT_ENGINE_REVERSE_PIN 6

void initMotorDriver(){
    pinMode(LEFT_ENGINE_SPEED_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_SPEED_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_REVERSE_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_REVERSE_PIN, OUTPUT);
}

/**
 * @brief Sets the dc motor direction of the right motors to "forward".
 * 
 * If the motor direction is currently set to "reverse", this method changes the motor direction.
 * If the motor direction was already set to "forward", the method will not affect any change. 
 */
void rightForward(){
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, HIGH);
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, LOW);
}

/**
 * @brief Sets the dc motor direction of the right motors to "reverse".
 * 
 * If the motor direction is currently set to "forward", this method changes the motor direction.
 * If the motor direction was already set to "reverse", the method will not affect any change.
 */
void rightReverse(){
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, HIGH);
}

/**
 * @brief Sets the speed of the right motors to the desired value.
 * 
 * @param speed specify the motor speed between 60 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-59 is not recommended, because the motors to not get enough power to move the car.
 */
void rightSpeed(int speed){
    analogWrite(RIGHT_ENGINE_SPEED_PIN, speed);
}

/**
 * @brief Sets the dc motor direction of the left motors to "forward".
 * 
 * If the motor direction is currently set to "reverse", this method changes the motor direction.
 * If the motor direction was already set to "forward", the method will not affect any change.
 */
void leftForward(){
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, HIGH);
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, LOW);
}

/**
 * @brief Sets the dc motor direction of the left motors to "reverse".
 * 
 * If the motor direction is currently set to "forward", this method changes the motor direction.
 * If the motor direction was already set to "reverse", the method will not affect any change.
 */
void leftReverse(){
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, HIGH);
}

/**
 * @brief Sets the speed of the left motors to the desired value.
 * 
 * @param speed specify the motor speed between 60 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-59 is not recommended, because the motors to not get enough power to move the car.
 */
void leftSpeed(int speed){
    analogWrite(LEFT_ENGINE_SPEED_PIN, speed);
}

/**
 * @brief Sets the speed of all motors to the desired value.
 * 
 * @param speed specify the motor speed between 60 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-59 is not recommended, because the motors to not get enough power to move the car.
 */
void setSpeed(int speed){
    leftSpeed(speed);
    rightSpeed(speed);
}

void stop(){
    setSpeed(0);
}

/**
 * @brief Sets the movement direction of all motors to "forward".
 * 
 * If the motor direction is currently set to "reverse", this method changes the motor direction.
 * If the motor direction was already set to "forward", the method will not affect any change.
 */
void forward(){
    leftForward();
    rightForward();
}

void driveForward(int speed){
    setSpeed(speed);
    forward();
}

/**
 * @brief Sets the dc motor direction of all motors to "reverse".
 * 
 * If the motor direction is currently set to "forward", this method changes the motor direction.
 * If the motor direction was already set to "reverse", the method will not affect any change.
 */
void reverse(){
    leftReverse();
    rightReverse();
}

void driveReverse(int speed){
    setSpeed(speed);
    reverse();
}

/**
 * @brief Turns the car left if driving forward.
 * 
 * More specifically: the right motors are set to "forward" and the left motors to "reverse".
 */
void turnLeft(){
    rightForward();
    leftReverse();
}

void turnLeftForward(int speed){
    setSpeed(speed);
    turnLeft();
}

/**
 * @brief Turns the car right if driving forward.
 * 
 * More specifically: the right motors are set to "reverse" and the left motors to "forward".
 */
void turnRight(){
    leftForward();
    rightReverse();
}

void turnRightForward(int speed){
    setSpeed(speed);
    turnRight();
}

void steerLeftForward(int speed, double fraction){
    forward();
    leftSpeed(speed/fraction);
    rightSpeed(speed);
}

void steerRightForward(int speed, double fraction){
    forward();
    leftSpeed(speed);
    rightSpeed(speed/fraction);
}

#ifdef __cplusplus
}
#endif