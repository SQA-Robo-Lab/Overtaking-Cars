
#include "Debug.h"

#include "I2cCustomLib.hpp"


#include "MCC_powerTrainComponent.h"
#include "MCC_distanceSensorComponent.h"
#include "MCC_driveControlComponent.h"

// Start of user code DEVICEINITINCLUDES
/* TODO: if devices or libraries are used which need an initialization, include the headers here */
// End of user code


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
	// Start of user code DEVICEINIT
	/* TODO: if devices are used which need an initialization, call the functionse here */
	// End of user code
	atomic_c1= MCC_create_DriveControlComponent(CI_DRIVECONTROLSDRIVECONTROL);
	atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINSPOWERTRAIN);
	atomic_c3= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORSDISTANCESENSOR);
	atomic_c4= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORSDISTANCESENSOR);
	
	i2cCommunication_setup(10);


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



