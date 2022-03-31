#define C99

#include "lib/Debug.h"

#include "container_lib/I2cCustomLib.h"


#include "component_container/MCC_powerTrainComponent.h"
#include "component_container/MCC_driveControlComponent.h"
#include "component_container/MCC_distanceSensorComponent.h"


//variable for component Instances
PowerTrainComponent* atomic_c1;
DriveControlComponent* atomic_c2;
DistanceSensorComponent* atomic_c3;
DistanceSensorComponent* atomic_c4;

void setup(){
	atomic_c1= MCC_create_PowerTrainComponent(CI_POWERTRAINSPOWERTRAIN);
	atomic_c2= MCC_create_DriveControlComponent(CI_DRIVECONTROLSDRIVECONTROL);
	atomic_c3= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORSDISTANCESENSOR);
	atomic_c4= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORSDISTANCESENSOR);
	
	I2cCommunication_setup(10);


	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization done...start execution.\n");
	#endif
}

void loop(){

	PowerTrainComponent_processStep(atomic_c1);
	DriveControlComponent_processStep(atomic_c2);
	DistanceSensorComponent_processStep(atomic_c3);
	DistanceSensorComponent_processStep(atomic_c4);
}	



