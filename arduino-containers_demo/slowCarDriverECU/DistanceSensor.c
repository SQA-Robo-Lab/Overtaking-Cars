/**
 * @file DistanceSensor.c
 * @author david
 * @brief Encapsulates the functions to access two HC-SR04 ultrasonic distance sensors.
 */
#ifdef __cplusplus
  extern "C" {
#endif
#include "DistanceSensor.h"

// The digital pins used for the Arduino Car.
#define FRONT_TRIGGER_PIN 26
#define FRONT_ECHO_PIN 27
#define REAR_TRIGGER_PIN 24
#define REAR_ECHO_PIN 25


void initializeDistanceSensors(){
    pinMode(FRONT_TRIGGER_PIN, OUTPUT);
    pinMode(FRONT_ECHO_PIN, INPUT);
    pinMode(REAR_TRIGGER_PIN, OUTPUT);
    pinMode(REAR_ECHO_PIN, INPUT);
}

/**
 * @brief Calculates the distance in cm for a given echo duration in micro-senconds
 * 
 * The distance = time * speed
 * The time is duration/2 (as the signal travels there and back.)
 * The speed of sound at 20°C is roughly 0.0343 cm/micro-second
 * The distance will be returned in whole integers only.
 * 
 * @param duration: the duration the signal travels in micro-seconds
 */
int calculateDistanceInCm(long duration){
  return (duration / 2) * 0.0343;
}

int getFrontDistance(){
    //clear the trigger pin
    digitalWrite(FRONT_TRIGGER_PIN, LOW);
    delayMicroseconds(5);
    //issue the trigger
    digitalWrite(FRONT_TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    //stop the trigger
    digitalWrite(FRONT_TRIGGER_PIN, LOW);

    //measure the echo duration
    int duration = pulseIn(FRONT_ECHO_PIN, HIGH, 0);

    return calculateDistanceInCm(duration);
}

int getRearDistance(){
    //clear the trigger pin
    digitalWrite(REAR_TRIGGER_PIN, LOW);
    delayMicroseconds(5);
    //issue the trigger
    digitalWrite(REAR_TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    //stop the trigger
    digitalWrite(REAR_TRIGGER_PIN, LOW);

    //measure the echo duration
    int duration = pulseIn(REAR_ECHO_PIN, HIGH, 0);

    return calculateDistanceInCm(duration);
}

#ifdef __cplusplus
}
#endif