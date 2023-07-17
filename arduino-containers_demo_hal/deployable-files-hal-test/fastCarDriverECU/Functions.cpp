#include "Functions.h"
#include "Config.hpp"

uint8_t distanceLimit = 150;
uint8_t desiredVelocity = 60;
uint8_t slowVelocity = 50;
uint8_t laneDistance = 100;



extern "C" int16_t getCurrentSpeed()
{
    return fastCarDriverController.getDriveController()->getSpeed();
}