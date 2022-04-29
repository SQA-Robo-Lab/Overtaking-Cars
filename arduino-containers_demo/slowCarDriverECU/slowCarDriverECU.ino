
#include "Debug.h"

#include "I2cCustomLib.hpp"


#include "MCC_driveControlComponent.h"
#include "MCC_distanceSensorComponent.h"
#include "MCC_powerTrainComponent.h"


//variable for component Instances
DistanceSensorComponent* atomic_c1;
PowerTrainComponent* atomic_c2;
DriveControlComponent* atomic_c3;
DistanceSensorComponent* atomic_c4;

void setup(){
	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization starting...");
	#endif
	atomic_c1= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORSDISTANCESENSOR);
	atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINSPOWERTRAIN);
	atomic_c3= MCC_create_DriveControlComponent(CI_DRIVECONTROLSDRIVECONTROL);
	atomic_c4= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORSDISTANCESENSOR);
	
	i2cCommunication_setup(10);


	#ifdef DEBUG
	Serial.println("Initialization done...start execution.");
	#endif
}

void loop(){

	DistanceSensorComponent_processStep(atomic_c1);
	PowerTrainComponent_processStep(atomic_c2);
	DriveControlComponent_processStep(atomic_c3);
	DistanceSensorComponent_processStep(atomic_c4);
}	



