/**
 * @file
 * @author Fraunhofer IPT-EM
 * @brief This file specifies the MessageBuffer, which are contained at the Components
 * @details  The MessageBuffer are used at the Components to store  MiddlewareMessage%s
 */
#ifndef CLOCK_H_
#define CLOCK_H_
//#include "../Middleware/OS.h"



#include <Arduino.h>
#include <stdint.h>
typedef uint64_t Clock;
static inline Clock Clock_getTime2(const Clock aClock) {
	unsigned long time = millis();
	return time - aClock;
}
static inline void Clock_reset2(Clock* const clock) { *clock = Clock_getTime2(0); }


#define Clock_getTime(aClock) Clock_getTime2(aClock)
#define Clock_reset(aClock) Clock_reset2(&aClock)



#endif /* CLOCK_H_ */
