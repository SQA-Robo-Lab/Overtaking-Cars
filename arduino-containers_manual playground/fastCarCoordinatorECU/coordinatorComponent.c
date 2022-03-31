		// Standard library
		
		#include "coordinatorComponent_Interface.h"
		

		
	
		void CoordinatorComponent_initialize(CoordinatorComponent* component) {
		
			CoordinatorCoordinatorComponentStateChart_initialize(component->stateChart);
			/*Initialize all DirectedTypedPorts*/
		}
		

		CoordinatorComponent CoordinatorComponent_create(void) {
		
			CoordinatorComponent component;
		
			component.stateChart = NULL;
		
			return component;
		}
		

		void CoordinatorComponent_destroy(CoordinatorComponent* component) {
			if (component != NULL) {
				CoordinatorCoordinatorComponentStateChart_destroy(
						component->stateChart);
		
				//temporarly deactivated
				//	Port_destroy(component->communicatorPort);
				//temporarly deactivated
				//	Port_destroy(component->overtakingInitiatorPort);
				//temporarly deactivated
				//	Port_destroy(component->overtakingAffiliatePort);
		
				//suicide
				free(component);
			}
		}
		
		
		void CoordinatorComponent_processStep(CoordinatorComponent* component) {
				
		
					component->stateChart->CoordinatorCoordinatorComponent_isExecutable = true;
					component->stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable = true;
					component->stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable = true;
					component->stateChart->CoordinatorOvertakingAffiliateOvertakingAffiliatePort_isExecutable = true;
				CoordinatorCoordinatorComponentStateChart_processStep(component->stateChart);
					
				
			
		}

		
		CoordinatorCoordinatorComponentStateChart* CoordinatorComponent_getStateMachine(CoordinatorComponent* component) {
					return component->stateChart;
				} 
			Port* CoordinatorComponent_getcommunicator(CoordinatorComponent* component) {
			return &(component->communicatorPort);
		}
			Port* CoordinatorComponent_getovertakingInitiator(CoordinatorComponent* component) {
			return &(component->overtakingInitiatorPort);
		}
			Port* CoordinatorComponent_getovertakingAffiliate(CoordinatorComponent* component) {
			return &(component->overtakingAffiliatePort);
		}

		

