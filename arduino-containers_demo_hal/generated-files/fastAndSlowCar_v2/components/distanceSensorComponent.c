		// Standard library
		
		#include "../components/distanceSensorComponent_Interface.h"
		

		
	
		void DistanceSensorComponent_initialize(DistanceSensorComponent* component) {
		
			/*Initialize all DirectedTypedPorts*/
			Clock_reset(component->distancePortClock);
		}
		

		DistanceSensorComponent DistanceSensorComponent_create(void) {
		
			DistanceSensorComponent component;
		
			return component;
		}
		

		void DistanceSensorComponent_destroy(DistanceSensorComponent* component) {
			if (component != NULL) {
		
				//suicide
				free(component);
			}
		}
		
		
		void DistanceSensorComponent_processStep(DistanceSensorComponent* component) {
				
		
			/*Send Messages for Continuous Out Ports*/
				{
				/*FIXME Currently a Continuous Port has no update interval. We set a fixed interval of 1ms.  An interval has to be defined in the model in the future.*/ 
				int localTimeInterval = 1;
				if (Clock_getTime(component->distancePortClock) >= localTimeInterval * 1) //interval of continuous port
				{
					component->distancePortAccessFunction(&component->distance);
					setterOf_distance(&component->distancePort, &component->distance);
					Clock_reset(component->distancePortClock);
				}
				}
				
			
		}

		
		void setterOf_distance(Port* distancePort, int32_T* distance) {
				MCC_DistanceSensorComponent_distance_send_value(distancePort, distance);		
		}

		

