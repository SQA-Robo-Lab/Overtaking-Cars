/**
 * @file MotorDriver.h
 * @author david
 * @brief A library providing functions to control the robot car using the motor controller L298N.
 */
#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "Arduino.h"

/**
 * @brief Initializes the motor driver by setting the pin modes for the arduino pins.
 * 
 * This method has to be called once for all other operations to work correctly!
 */
void initMotorDriver();

/**
 * @brief Sets the speed of all motors to the desired value without changing directions etc.
 * 
 * @param speed specify the motor speed between 50 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * Suggested fast speed value where turns are possible: 80
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-49 is not recommended, because the motors do not get enough power to move the car around tight turns.
 */
void setSpeed(int speed);

/**
 * @brief Sets the movement direction of all motors to "forward" AND sets the motor speed.
 * 
 * If the motor direction is currently set to "reverse", this method changes the motor direction.
 * If the motor direction was already set to "forward", the method will not affect any change.
 * 
 * @param speed specify the motor speed between 50 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * Suggested fast speed value where turns are possible: 80
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-49 is not recommended, because the motors do not getenough power to move the car.
 */
void driveForward(int speed);

/**
 * @brief Sets the movement direction of all motors to "reverse" AND sets the motor speed.
 * 
 * If the motor direction is currently set to "forward", this method changes the motor direction.
 * If the motor direction was already set to "reverse", the method will not affect any change.
 * 
 * @param speed specify the motor speed between 50 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * Suggested fast speed value where turns are possible: 80
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-49 is not recommended, because the motors do not getenough power to move the car.
 */
void driveReverse(int speed);

/**
 * @brief Turns the car left with the desired speed.
 * 
 * @param speed specify the motor speed between 50 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * Suggested fast speed value where turns are possible: 80
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-49 is not recommended, because the motors do not getenough power to move the car.
 */
void turnLeftForward(int speed);

/**
 * @brief Turns the car right with the desired speed.
 * 
 * @param speed specify the motor speed between 50 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 * Suggested fast speed value where turns are possible: 80
 * 
 * The operation controls the motors my sending PMW signals to the L298N motor controller. 
 * A value between 0-49 is not recommended, because the motors do not get enough power to move the car around tight turns.
 */
void turnRightForward(int speed);

/**
 * @brief Makes the car stop by deactivating all motors.
 * 
 */
void stop();

#ifdef __cplusplus
  }
#endif
#endif /* MOTOR_DRIVER_H */