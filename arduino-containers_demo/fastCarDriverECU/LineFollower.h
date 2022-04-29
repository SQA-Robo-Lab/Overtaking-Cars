/**
 * @file LineFollower.h
 * @author david
 * @brief A library to access the robot cars line following capabilities.
 */
#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "LineDetector.h"
#include "MotorDriver.h"

LinePosition globalCarPosition;

/**
 * @brief Initializes the motor driver and line detector that are required for the LineFollower.
 * 
 * This method has to be called once for all other operations to work correctly!
 */
void initLineFollower();

/**
 * @brief Makes the car follow a line with the given speed. MUST be called continuously in the loop method!
 * 
 * @param speed specify the motor speed between 60 (slowest moving speed) and 255 (full speed), or 0 to deactivate the motors.
 */
void followLine(int speed);

#ifdef __cplusplus
  }
#endif
#endif /* LINE_FOLLOWER_H */