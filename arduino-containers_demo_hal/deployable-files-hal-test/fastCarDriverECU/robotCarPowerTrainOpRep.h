#ifndef ROBOTCARPOWERTRAIN_H_
#define ROBOTCARPOWERTRAIN_H_
#include "Functions.h"
#ifdef __cplusplus
  extern "C" {
#endif

	#include "standardTypes.h"
	#include "customTypes.h"


			
		/**
		 * @brief Implementation stub of operation changeLaneLeft
 		 * @details This function shall contain the implementation of the operation changeLaneLeft.
		 * @param velocity 
		 */
		void RobotCarPowerTrain_robotCarPowerTrainChangeLaneLeft(int32_T velocity);
		/**
		 * @brief Implementation stub of operation changeLaneRight
 		 * @details This function shall contain the implementation of the operation changeLaneRight.
		 * @param velocity 
		 */
		void RobotCarPowerTrain_robotCarPowerTrainChangeLaneRight(int32_T velocity);
		/**
		 * @brief Implementation stub of operation followLine
 		 * @details This function shall contain the implementation of the operation followLine.
		 * @param velocity 
		 */
		void RobotCarPowerTrain_robotCarPowerTrainFollowLine(int32_T velocity);


#ifdef __cplusplus
  }
#endif
#endif /*ROBOTCARPOWERTRAIN_H_ */
