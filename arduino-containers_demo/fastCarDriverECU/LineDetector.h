/**
 * @file LineDetector.h
 * @author david
 * @brief This library uses three infrared sensor to detect the car's position relative to a line.
 */
#ifndef LINE_DETECTOR_H
#define LINE_DETECTOR_H

#ifdef __cplusplus
  extern "C" {
#endif

#include "Arduino.h"

typedef enum {
    LEFT_OF_LINE,
    ON_LINE,
    RIGHT_OF_LINE,
} LinePosition;

/**
 * @brief Initializes the line detector by setting the pin modes for the arduino pins.
 * 
 * This method has to be called once for all other operations to work correctly!
 */
void initLineDetector();

/**
 * @brief Detecs the position of an arduino car w.r.t. a line on the ground.
 * 
 * @param previousPosition hand over the last detected position so it can be taken into account for calculating the new position.
 * @return LinePosition the position of the car relative to the line.
 */
LinePosition detectPosition(LinePosition previousPosition);

#ifdef __cplusplus
  }
#endif
#endif /* LINE_DETECTOR_H */