
#include "Debug.h"

#include "I2cCustomLib.hpp"


#include "MCC_powerTrainComponent.h"
#include "MCC_driveControlComponent.h"
#include "MCC_distanceSensorComponent.h"


//variable for component Instances
DriveControlComponent* atomic_c1;
PowerTrainComponent* atomic_c2;
DistanceSensorComponent* atomic_c3;
DistanceSensorComponent* atomic_c4;

void setup(){
	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization starting...");
	#endif
	atomic_c1= MCC_create_DriveControlComponent(CI_DRIVECONTROLFDRIVECONTROL);
	atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINFPOWERTRAIN);
	atomic_c3= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORFDISTANCESENSOR);
	atomic_c4= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORFDISTANCESENSOR);
	
	i2cCommunication_setup(9);


	#ifdef DEBUG
	Serial.println("Initialization done...start execution.");
	#endif
}

void loop(){

	DriveControlComponent_processStep(atomic_c1);
	PowerTrainComponent_processStep(atomic_c2);
	DistanceSensorComponent_processStep(atomic_c3);
	DistanceSensorComponent_processStep(atomic_c4);
}	



