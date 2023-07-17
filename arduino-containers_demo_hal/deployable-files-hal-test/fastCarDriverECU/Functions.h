#ifndef SIMPLE_HARDWARE_COINTROLLER_EXAMPLE_FUNCTIONS_HPP
#define SIMPLE_HARDWARE_COINTROLLER_EXAMPLE_FUNCTIONS_HPP

#include <Arduino.h>


#ifdef __cpluplus
extern "C" 
#endif
int16_t getCurrentSpeed();

extern uint8_t distanceLimit;
extern uint8_t desiredVelocity;
extern uint8_t slowVelocity;
extern uint8_t laneDistance;

#endif