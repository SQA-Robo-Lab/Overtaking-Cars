#define C99

#include "lib/Debug.h"

#include "container_lib/I2cCustomLib.h"


#include "component_container/MCC_distanceSensorComponent.h"
#include "component_container/MCC_powerTrainComponent.h"
#include "component_container/MCC_driveControlComponent.h"


//variable for component Instances
DistanceSensorComponent* atomic_c1;
DistanceSensorComponent* atomic_c2;
DriveControlComponent* atomic_c3;
PowerTrainComponent* atomic_c4;

void setup(){
	atomic_c1= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORFDISTANCESENSOR);
	atomic_c2= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORFDISTANCESENSOR);
	atomic_c3= MCC_create_DriveControlComponent(CI_DRIVECONTROLFDRIVECONTROL);
	atomic_c4= MCC_create_PowerTrainComponent(CI_POWERTRAINFPOWERTRAIN);
	
	I2cCommunication_setup(9);


	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization done...start execution.\n");
	#endif
}

void loop(){

	DistanceSensorComponent_processStep(atomic_c1);
	DistanceSensorComponent_processStep(atomic_c2);
	DriveControlComponent_processStep(atomic_c3);
	PowerTrainComponent_processStep(atomic_c4);
}	



