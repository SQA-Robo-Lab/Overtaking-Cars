
#include "Debug.h"

#include "I2cCustomLib.hpp"


#include "MCC_distanceSensorComponent.h"
#include "MCC_powerTrainComponent.h"
#include "MCC_driveControlComponent.h"


//variable for component Instances
DistanceSensorComponent* atomic_c1;
DistanceSensorComponent* atomic_c2;
DriveControlComponent* atomic_c3;
PowerTrainComponent* atomic_c4;

void setup(){
	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization starting...");
	#endif
	atomic_c1= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORFDISTANCESENSOR);
	atomic_c2= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORFDISTANCESENSOR);
	atomic_c3= MCC_create_DriveControlComponent(CI_DRIVECONTROLFDRIVECONTROL);
	atomic_c4= MCC_create_PowerTrainComponent(CI_POWERTRAINFPOWERTRAIN);
	
	i2cCommunication_setup(9);


	#ifdef DEBUG
	Serial.println("Initialization done...start execution.");
	#endif
}

void loop(){

	DistanceSensorComponent_processStep(atomic_c1);
	DistanceSensorComponent_processStep(atomic_c2);
	DriveControlComponent_processStep(atomic_c3);
	PowerTrainComponent_processStep(atomic_c4);
}	



