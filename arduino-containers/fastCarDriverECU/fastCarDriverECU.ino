#include "lib/Debug.h"

#include "container_lib/I2cCustomLib.h"


#include "component_container/MCC_driveControlComponent.h"
#include "component_container/MCC_powerTrainComponent.h"
#include "component_container/MCC_distanceSensorComponent.h"


//variable for component Instances
DriveControlComponent* atomic_c1;
PowerTrainComponent* atomic_c2;
DistanceSensorComponent* atomic_c3;
DistanceSensorComponent* atomic_c4;

int setup(){
	atomic_c1= MCC_create_DriveControlComponent(CI_DRIVECONTROLFDRIVECONTROL);
	atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINFPOWERTRAIN);
	atomic_c3= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORFDISTANCESENSOR);
	atomic_c4= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORFDISTANCESENSOR);
	
	I2cCommunication_setup(9);


	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization done...start execution.\n");
	#endif
}

void loop(){

	DriveControlComponent_processStep(atomic_c1);
	PowerTrainComponent_processStep(atomic_c2);
	DistanceSensorComponent_processStep(atomic_c3);
	DistanceSensorComponent_processStep(atomic_c4);
}	



