#include "lib/Debug.h"

#include "container_lib/I2cCustomLib.h"


#include "component_container/MCC_distanceSensorComponent.h"
#include "component_container/MCC_driveControlComponent.h"
#include "component_container/MCC_powerTrainComponent.h"


//variable for component Instances
DistanceSensorComponent* atomic_c1;
PowerTrainComponent* atomic_c2;
DistanceSensorComponent* atomic_c3;
DriveControlComponent* atomic_c4;

int setup(){
	atomic_c1= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORSDISTANCESENSOR);
	atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINSPOWERTRAIN);
	atomic_c3= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORSDISTANCESENSOR);
	atomic_c4= MCC_create_DriveControlComponent(CI_DRIVECONTROLSDRIVECONTROL);
	
	I2cCommunication_setup(10);


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



