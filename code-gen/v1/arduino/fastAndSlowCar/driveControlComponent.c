		#include "driveControlComponent_Interface.h"
		

		
	
		void DriveControlComponent_initialize(DriveControlComponent* component) {
		
			DriveControlDriveControlComponentStateChart_initialize(
					component->stateChart);
		
			component->driveControlPort = NULL;
		}
		

		DriveControlComponent* DriveControlComponent_create(void) {
		
			DriveControlComponent* component = (DriveControlComponent*) malloc(
					sizeof(DriveControlComponent));
		
			if (component != NULL) {
		
				component->driveControlPort = NULL;
		
				component->stateChart = NULL;
		
			} else {
		
			}
		
			return component;
		}
		

		void DriveControlComponent_destroy(DriveControlComponent* component) {
			if (component != NULL) {
		
				Port_destroy(component->driveControlPort);
		
				//suicide
				free(component);
			}
		}
		
		
		void DriveControlComponent_processStep(DriveControlComponent* component) {
				
		
					component->stateChart->distance = component->getterOf_distance();
		
					component->stateChart->DriveControlDriveControlComponent_isExecutable = true;
					component->stateChart->DriveControlDriveControlDriveControlPort_isExecutable = true;
					component->stateChart->DriveControlDriveControl_mainDriving_isExecutable = true;
				DriveControlDriveControlComponentStateChart_processStep(component->stateChart);
					component->setterOf_velocity(component->stateChart->velocity);
		}
	
		DriveControlDriveControlComponentStateChart* DriveControlComponent_getStateMachine(DriveControlComponent* component) {
					return component->stateChart;
				} 
		
				Port* DriveControlComponent_getdriveControl(DriveControlComponent* component) {
					return component->driveControlPort;
				}

		

