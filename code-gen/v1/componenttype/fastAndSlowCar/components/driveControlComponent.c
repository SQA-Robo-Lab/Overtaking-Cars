		// Standard library
		
		#include "../components/driveControlComponent_Interface.h"
		

		
	
		void DriveControlComponent_initialize(DriveControlComponent* component) {
		
			DriveControlDriveControlComponentStateChart_initialize(
					component->stateChart);
			/*Initialize all DirectedTypedPorts*/
			Clock_reset(component->distancePortClock);
			Clock_reset(component->velocityPortClock);
		}
		

		DriveControlComponent DriveControlComponent_create(void) {
		
			DriveControlComponent component;
		
			component.stateChart = NULL;
		
			return component;
		}
		

		void DriveControlComponent_destroy(DriveControlComponent* component) {
			if (component != NULL) {
				DriveControlDriveControlComponentStateChart_destroy(
						component->stateChart);
		
				//temporarly deactivated
				//	Port_destroy(component->driveControlPort);
		
				//suicide
				free(component);
			}
		}
		
		
		void DriveControlComponent_processStep(DriveControlComponent* component) {
				
		
					component->stateChart->DriveControlDriveControlComponent_isExecutable = true;
					component->stateChart->DriveControlDriveControlDriveControlPort_isExecutable = true;
					component->stateChart->DriveControlDriveControl_mainDriving_isExecutable = true;
				DriveControlDriveControlComponentStateChart_processStep(component->stateChart);
				/*Send Messages for Hybrid Out Ports*/	
				if (Clock_getTime(component->velocityPortClock) >= 30 * 1.0) //interval of hybrid port
				{
					setterOf_velocity(&component->velocityPort, &component->stateChart->velocity);
					Clock_reset(component->velocityPortClock);
				}
				/*Receive Messages for Hybrid In Ports*/
				if (Clock_getTime(component->distancePortClock) >= 30 * 1.0) //interval of hybrid port
				{
					bool_T changed = false;
					changed = getterOf_distance(&component->distancePort, &component->stateChart->distance);
					Clock_reset(component->distancePortClock);
				}
			
		}

		
		DriveControlDriveControlComponentStateChart* DriveControlComponent_getStateMachine(DriveControlComponent* component) {
					return component->stateChart;
				} 
			Port* DriveControlComponent_getdriveControl(DriveControlComponent* component) {
			return &(component->driveControlPort);
		}
		
			void setterOf_velocity(Port* velocityPort, double_T* velocity) {
				MCC_DriveControlComponent_velocity_send_value(velocityPort, velocity);		
		}
			
			bool_T getterOf_distance(Port* distancePort, double_T* distance) {
			if(MCC_DriveControlComponent_distance_exists_value(distancePort)){
				MCC_DriveControlComponent_distance_recv_value(distancePort, distance);
			return true;
			}
			else return false;
		}

		

