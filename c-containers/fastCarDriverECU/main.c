	#include "lib/Debug.h"
		#include "component_container/MCC_driveControlComponent.h"
		#include "component_container/MCC_distanceSensorComponent.h"
		#include "component_container/MCC_powerTrainComponent.h"


//variable for component Instances
			DistanceSensorComponent* atomic_c1;
			DriveControlComponent* atomic_c2;
			PowerTrainComponent* atomic_c3;
			DistanceSensorComponent* atomic_c4;
int main(){
			atomic_c1= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORFDISTANCESENSOR);

			atomic_c2= MCC_create_DriveControlComponent(CI_DRIVECONTROLFDRIVECONTROL);

			atomic_c3= MCC_create_PowerTrainComponent(CI_POWERTRAINFPOWERTRAIN);

			atomic_c4= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORFDISTANCESENSOR);

	#ifdef DEBUG
	printDebugInformation("Initialization done...start execution.\n");
	#endif
	while (1) {

			DistanceSensorComponent_processStep(atomic_c1);
			DriveControlComponent_processStep(atomic_c2);
			PowerTrainComponent_processStep(atomic_c3);
			DistanceSensorComponent_processStep(atomic_c4);
	}
}	



