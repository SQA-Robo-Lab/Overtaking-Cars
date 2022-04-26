	#include "lib/Debug.h"
		#include "component_container/MCC_driveControlComponent.h"
		#include "component_container/MCC_powerTrainComponent.h"
		#include "component_container/MCC_distanceSensorComponent.h"


//variable for component Instances
			DriveControlComponent* atomic_c1;
			PowerTrainComponent* atomic_c2;
			DistanceSensorComponent* atomic_c3;
			DistanceSensorComponent* atomic_c4;
int main(){
			atomic_c1= MCC_create_DriveControlComponent(CI_DRIVECONTROLSDRIVECONTROL);

			atomic_c2= MCC_create_PowerTrainComponent(CI_POWERTRAINSPOWERTRAIN);

			atomic_c3= MCC_create_DistanceSensorComponent(CI_REARDISTANCESENSORSDISTANCESENSOR);

			atomic_c4= MCC_create_DistanceSensorComponent(CI_FRONTDISTANCESENSORSDISTANCESENSOR);

	#ifdef DEBUG
	printDebugInformation("Initialization done...start execution.\n");
	#endif
	while (1) {

			DriveControlComponent_processStep(atomic_c1);
			PowerTrainComponent_processStep(atomic_c2);
			DistanceSensorComponent_processStep(atomic_c3);
			DistanceSensorComponent_processStep(atomic_c4);
	}
}	



