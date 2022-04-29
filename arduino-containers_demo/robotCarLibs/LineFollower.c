#ifdef __cplusplus
  extern "C" {
#endif

#include "LineFollower.h"

void initLineFollower(){
    initMotorDriver();
    
    initLineDetector();
    globalCarPosition = detectPosition(ON_LINE);
}

void followLine(int speed){
    globalCarPosition = detectPosition(globalCarPosition);
    if (globalCarPosition == ON_LINE){
        // Serial.println("On line!");
        driveForward(speed);
    } else if (globalCarPosition == LEFT_OF_LINE){
        // Serial.println("LEFT of line!");
        turnRightForward(speed*1.5);
    } else if (globalCarPosition == RIGHT_OF_LINE){
        // Serial.println("RIGHT of line");
        turnLeftForward(speed*1.5);
    } else {
        // Serial.println("This is strange...");
        stop();
    }
}

#ifdef __cplusplus
}
#endif