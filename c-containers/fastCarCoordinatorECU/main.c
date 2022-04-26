	#include "lib/Debug.h"
		#include "component_container/MCC_coordinatorComponent.h"


//variable for component Instances
			CoordinatorComponent* atomic_c1;
int main(){
			atomic_c1= MCC_create_CoordinatorComponent(CI_COMMUNICATORFCOORDINATOR);

	#ifdef DEBUG
	printDebugInformation("Initialization done...start execution.\n");
	#endif
	while (1) {

			CoordinatorComponent_processStep(atomic_c1);
	}
}	



