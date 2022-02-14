#include "coordinatorComponent_Interface.h"

void CoordinatorComponent_initialize(CoordinatorComponent* component) {

	CoordinatorCoordinatorComponentStateChart_initialize(component->stateChart);

	component->communicatorPort = NULL;
	component->overtakingInitiatorPort = NULL;
	component->overtakingAffiliatePort = NULL;
}

CoordinatorComponent* CoordinatorComponent_create(void) {

	CoordinatorComponent* component = (CoordinatorComponent*) malloc(
			sizeof(CoordinatorComponent));

	if (component != NULL) {

		component->communicatorPort = NULL;
		component->overtakingInitiatorPort = NULL;
		component->overtakingAffiliatePort = NULL;

		component->stateChart = NULL;

	} else {

	}

	return component;
}

void CoordinatorComponent_destroy(CoordinatorComponent* component) {
	if (component != NULL) {

		Port_destroy(component->communicatorPort);
		Port_destroy(component->overtakingInitiatorPort);
		Port_destroy(component->overtakingAffiliatePort);

		//suicide
		free(component);
	}
}

void CoordinatorComponent_processStep(CoordinatorComponent* component) {

	component->stateChart->CoordinatorCoordinatorComponent_isExecutable = true;
	component->stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
			true;
	component->stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
			true;
	component->stateChart->CoordinatorOvertakingAffiliateOvertakingAffiliatePort_isExecutable =
			true;
	CoordinatorCoordinatorComponentStateChart_processStep(
			component->stateChart);
}

CoordinatorCoordinatorComponentStateChart* CoordinatorComponent_getStateMachine(
		CoordinatorComponent* component) {
	return component->stateChart;
}

Port* CoordinatorComponent_getcommunicator(CoordinatorComponent* component) {
	return component->communicatorPort;
}
Port* CoordinatorComponent_getovertakingInitiator(
		CoordinatorComponent* component) {
	return component->overtakingInitiatorPort;
}
Port* CoordinatorComponent_getovertakingAffiliate(
		CoordinatorComponent* component) {
	return component->overtakingAffiliatePort;
}

