/**
 * @file LineDetector.c
 * @author david
 * @brief A library providing operations to use three KY-033 line detection sensors to detect the position of an arduino car with respect to a line on the ground.
 */
#ifdef __cplusplus
  extern "C" {
#endif
#include "LineDetector.h"


//define your pins connected to OUT/SIGNAL (ditial IO pins)
#define IR_SIGNAL_PIN_LEFT 30
#define IR_SIGNAL_PIN_CENTER 32
#define IR_SIGNAL_PIN_RIGHT 34

void initLineDetector(){
    pinMode(IR_SIGNAL_PIN_LEFT, INPUT);
    pinMode(IR_SIGNAL_PIN_CENTER, INPUT);
    pinMode(IR_SIGNAL_PIN_RIGHT, INPUT);
}

/**
 * @brief read the values of the line detection sensors.
 * 
 * @param signals an int buffer of size 3 to write the signals to as return values.
 * 
 * signals[0] will hold the value of the LEFT sensor
 * signals[1] will hold the value of the CENTER sensor
 * signals[2] will hold the value of the RIGHT sensor
 */
void readSensorSignals(int signals[]){
    signals[0] = digitalRead(IR_SIGNAL_PIN_LEFT);
    signals[1] = digitalRead(IR_SIGNAL_PIN_CENTER);
    signals[2] = digitalRead(IR_SIGNAL_PIN_RIGHT);
}

LinePosition detectPosition(LinePosition previousPosition){
    int signals[3];
    readSensorSignals(signals);
    if (signals[0] == 1 && signals[1] == 0 && signals[2] == 0){
        return RIGHT_OF_LINE;
    } else if (signals[0] == 0 && signals[1] == 1 && signals[2] == 0){
        return ON_LINE;
    } else if (signals[0] == 0 && signals[1] == 0 && signals[2] == 1){
        return LEFT_OF_LINE;
    } else { // if the sensor reading is unclear (e.g. because left and center detect the line at the same time), do not change the position
        return previousPosition;
    }
}

#ifdef __cplusplus
}
#endif