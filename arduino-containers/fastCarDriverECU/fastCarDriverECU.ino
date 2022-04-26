#define C99

#include "Debug.h"

#include "I2cCustomLib.hpp"


#include "MCC_powerTrainComponent.h"
#include "MCC_driveControlComponent.h"
#include "MCC_distanceSensorComponent.h"


//variable for component Instances
DistanceSensorComponent* atomic_c1;
PowerTrainComponent* atomic_c2;
DistanceSensorComponent* atomic_c3;
DriveControlComponent* atomic_c4;

void setup(){
	atomic_c1= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORFDISTANCESENSOR);
	atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINFPOWERTRAIN);
	atomic_c3= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORFDISTANCESENSOR);
	atomic_c4= MCC_create_DriveControlComponent(CI_DRIVECONTROLFDRIVECONTROL);
	
	I2cCommunication_setup(9);


	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization done...start execution.\n");
	#endif
}

void loop(){

	DistanceSensorComponent_processStep(atomic_c1);
	PowerTrainComponent_processStep(atomic_c2);
	DistanceSensorComponent_processStep(atomic_c3);
	DriveControlComponent_processStep(atomic_c4);
}	



