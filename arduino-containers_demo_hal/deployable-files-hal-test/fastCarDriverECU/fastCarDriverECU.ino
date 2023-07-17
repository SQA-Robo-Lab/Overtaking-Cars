
#include "Debug.h"

#include "I2cCustomLib.hpp"
#include <SimpleHardwareController.hpp>
#include "Config.hpp"
#include "Functions.h"

#include "MCC_distanceSensorComponent.h"
#include "MCC_powerTrainComponent.h"
#include "MCC_driveControlComponent.h"

// Start of user code DEVICEINITINCLUDES
// End of user code


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
	// Start of user code DEVICEINIT
	fastCarDriverController.initializeCar(config, lineConfig);
	// End of user code
	atomic_c1= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORFDISTANCESENSOR);
	atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINFPOWERTRAIN);
	atomic_c3= MCC_create_DriveControlComponent(CI_DRIVECONTROLFDRIVECONTROL);
	atomic_c4= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORFDISTANCESENSOR);
	
	i2cCommunication_setup(9);


	#ifdef DEBUG
	Serial.println("Initialization done...start execution.");
	#endif
}

void loop(){
	fastCarDriverController.loop();
	DistanceSensorComponent_processStep(atomic_c1);
	PowerTrainComponent_processStep(atomic_c2);
	DriveControlComponent_processStep(atomic_c3);
	DistanceSensorComponent_processStep(atomic_c4);
}	
