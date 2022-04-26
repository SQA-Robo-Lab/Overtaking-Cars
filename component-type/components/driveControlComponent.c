		// Standard library
		
		#include "../components/driveControlComponent_Interface.h"
		

		
	
		void DriveControlComponent_initialize(DriveControlComponent* component) {
		
			DriveControlDriveControlComponentStateChart_initialize(
					component->stateChart);
			/*Initialize all DirectedTypedPorts*/
			Clock_reset(component->frontDistancePortClock);
			Clock_reset(component->rearDistancePortClock);
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
				if (Clock_getTime(component->frontDistancePortClock) >= 30 * 1.0) //interval of hybrid port
				{
					bool_T changed = false;
					changed = getterOf_frontDistance(&component->frontDistancePort, &component->stateChart->frontDistance);
					Clock_reset(component->frontDistancePortClock);
				}
				if (Clock_getTime(component->rearDistancePortClock) >= 30 * 1.0) //interval of hybrid port
				{
					bool_T changed = false;
					changed = getterOf_rearDistance(&component->rearDistancePort, &component->stateChart->rearDistance);
					Clock_reset(component->rearDistancePortClock);
				}
			
		}

		
		DriveControlDriveControlComponentStateChart* DriveControlComponent_getStateMachine(DriveControlComponent* component) {
					return component->stateChart;
				} 
			Port* DriveControlComponent_getdriveControl(DriveControlComponent* component) {
			return &(component->driveControlPort);
		}
		
			void setterOf_velocity(Port* velocityPort, int32_T* velocity) {
				MCC_DriveControlComponent_velocity_send_value(velocityPort, velocity);		
		}
			
			bool_T getterOf_frontDistance(Port* frontDistancePort, int32_T* frontDistance) {
			if(MCC_DriveControlComponent_frontDistance_exists_value(frontDistancePort)){
				MCC_DriveControlComponent_frontDistance_recv_value(frontDistancePort, frontDistance);
			return true;
			}
			else return false;
		}
			
			bool_T getterOf_rearDistance(Port* rearDistancePort, int32_T* rearDistance) {
			if(MCC_DriveControlComponent_rearDistance_exists_value(rearDistancePort)){
				MCC_DriveControlComponent_rearDistance_recv_value(rearDistancePort, rearDistance);
			return true;
			}
			else return false;
		}

		

