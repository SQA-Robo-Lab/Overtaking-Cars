#define C99

#include "Debug.h"

#include "I2cCustomLib.hpp"


#include "MCC_distanceSensorComponent.h"
#include "MCC_driveControlComponent.h"
#include "MCC_powerTrainComponent.h"


//variable for component Instances
PowerTrainComponent* atomic_c1;
DistanceSensorComponent* atomic_c2;
DistanceSensorComponent* atomic_c3;
DriveControlComponent* atomic_c4;

void setup(){
	atomic_c1= MCC_create_PowerTrainComponent(CI_POWERTRAINSPOWERTRAIN);
	atomic_c2= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORSDISTANCESENSOR);
	atomic_c3= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORSDISTANCESENSOR);
	atomic_c4= MCC_create_DriveControlComponent(CI_DRIVECONTROLSDRIVECONTROL);
	
	I2cCommunication_setup(10);


	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization done...start execution.\n");
	#endif
}

void loop(){

	PowerTrainComponent_processStep(atomic_c1);
	DistanceSensorComponent_processStep(atomic_c2);
	DistanceSensorComponent_processStep(atomic_c3);
	DriveControlComponent_processStep(atomic_c4);
}	



