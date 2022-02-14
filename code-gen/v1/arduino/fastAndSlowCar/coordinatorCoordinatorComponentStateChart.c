
#include "coordinatorComponent_Interface.h"

void initializeCoordinatorCommunicatorCommunicatorPortRegion(
		CoordinatorCoordinatorComponentStateChart* stateChart) {

	stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
			STATE_COORDINATORCOMMUNICATORIDLE;

	stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable = true;

}
void initializeCoordinatorOvertakingInitiatorOvertakingInitiatorPortRegion(
		CoordinatorCoordinatorComponentStateChart* stateChart) {

	stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
			STATE_COORDINATOROVERTAKINGINITIATORIDLE;

	stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
	true;

}
void initializeCoordinatorOvertakingAffiliateOvertakingAffiliatePortRegion(
		CoordinatorCoordinatorComponentStateChart* stateChart) {

	stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort =
			STATE_COORDINATOROVERTAKINGAFFILIATEIDLE;

	stateChart->CoordinatorOvertakingAffiliateOvertakingAffiliatePort_isExecutable =
	true;

}

void CoordinatorCoordinatorComponentStateChart_initialize(
		CoordinatorCoordinatorComponentStateChart* stateChart) {
	//initialize clocks
	Clock_reset(
			stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock);

	//initialize hybrid ports

	//initialize variables of the root statechart
	stateChart->coordinationTimeout = stateChart->coordinationTimeout = 0;
	;

	stateChart->coordinatorIsBusy = false;

	//initialize init state
	stateChart->currentStateOfCoordinatorCoordinatorComponent =
			STATE_COORDINATORCOORDINATOR_MAIN;

	initializeCoordinatorCommunicatorCommunicatorPortRegion(stateChart);
	initializeCoordinatorOvertakingInitiatorOvertakingInitiatorPortRegion(
			stateChart);
	initializeCoordinatorOvertakingAffiliateOvertakingAffiliatePortRegion(
			stateChart);
}

CoordinatorCoordinatorComponentStateChart* CoordinatorCoordinatorComponentStateChart_create(
		CoordinatorComponent* parentComponent) {
	CoordinatorCoordinatorComponentStateChart* stateChart =
			(CoordinatorCoordinatorComponentStateChart*) malloc(
					sizeof(CoordinatorCoordinatorComponentStateChart));
	if (stateChart != NULL) {
		stateChart->parentComponent = parentComponent;
		if (stateChart->parentComponent != NULL) {
			CoordinatorCoordinatorComponentStateChart_initialize(stateChart);
		} else {

			CoordinatorCoordinatorComponentStateChart_destroy(stateChart);
			stateChart = NULL;
		}
	} else {

	}
	return stateChart;
}

void CoordinatorCoordinatorComponentStateChart_destroy(
		CoordinatorCoordinatorComponentStateChart* stateChart) {
	if (stateChart != NULL) {

		free(stateChart);
	}
}

void CoordinatorCommunicatorCommunicatorPortStateChart_processStep(
		CoordinatorCoordinatorComponentStateChart* stateChart) {
	switch (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort) {
	case STATE_COORDINATORCOMMUNICATORIDLE:
		if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
				&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
						== STATE_COORDINATOROVERTAKINGINITIATORIDLE)) {
			if (

			stateChart->coordinatorIsBusy == false

					&& Port_doesMessageExist(
							CoordinatorComponent_getcommunicator(
									stateChart->parentComponent),
							MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE)

							) {
				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getcommunicator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesRequestPermissionOvertakingPermissionMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
						STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				stateChart->coordinatorIsBusy = true;

				;

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->overtakingInitiatorPort->ID),
						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
						STATE_COORDINATOROVERTAKINGINITIATORINITIATING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORINITIATING" );

#endif

				// execute entry actions

				Clock_reset(
						stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock);

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
				false;
				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
				false;
				//break;
			}
		} else if (0) {
			//dummy
		} else {

		}
		break;
	case STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION:
		if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
				&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
						== STATE_COORDINATOROVERTAKINGINITIATORINITIATING)) {

			if (

			Clock_getTime(
					stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)
					> stateChart->coordinationTimeout * 1000.0

			&& 1

			) {

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->overtakingInitiatorPort->ID),
						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
						STATE_COORDINATOROVERTAKINGINITIATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORIDLE" );

#endif

				// execute entry actions

				stateChart->coordinatorIsBusy = false;

				;

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->communicatorPort->ID),
						MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
						STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
				false;

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
				false;

				//break;

			}

		}

		else

		if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
				&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
						== STATE_COORDINATOROVERTAKINGINITIATORINITIATING)) {

			if (Port_doesMessageExist(
					CoordinatorComponent_getovertakingInitiator(
							stateChart->parentComponent),
					MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE)

			&& 1

			) {

				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getovertakingInitiator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertakingOvertakingCoordinationMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
						STATE_COORDINATOROVERTAKINGINITIATORPASSING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->communicatorPort->ID),
						MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
						STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
				false;

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
				false;

				//break;

			}

		}

		else

		if (0) {

			//dummy

		} else if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
				&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
						== STATE_COORDINATOROVERTAKINGINITIATORINITIATING)) {

			if (

			Clock_getTime(
					stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)
					> stateChart->coordinationTimeout * 1000.0

			&& 1

			) {

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->overtakingInitiatorPort->ID),
						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
						STATE_COORDINATOROVERTAKINGINITIATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORIDLE" );

#endif

				// execute entry actions

				stateChart->coordinatorIsBusy = false;

				;

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->communicatorPort->ID),
						MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
						STATE_COORDINATORCOMMUNICATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
				false;

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
				false;

				//break;

			}

		}

		else

		if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
				&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
						== STATE_COORDINATOROVERTAKINGINITIATORINITIATING)) {

			if (Port_doesMessageExist(
					CoordinatorComponent_getovertakingInitiator(
							stateChart->parentComponent),
					MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE)

			&& 1

			) {

				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getovertakingInitiator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertakingOvertakingCoordinationMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
						STATE_COORDINATOROVERTAKINGINITIATORPASSING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->communicatorPort->ID),
						MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
						STATE_COORDINATORCOMMUNICATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
				false;

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
				false;

				//break;

			}

		}

		else

		if (0) {

			//dummy

		} else {

		}
		break;
	case STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING:
		if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
				&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
						== STATE_COORDINATOROVERTAKINGINITIATORPASSING)) {

			if (1

					&& Port_doesMessageExist(
							CoordinatorComponent_getcommunicator(
									stateChart->parentComponent),
							MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE)

							) {

				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getcommunicator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesExecutedOvertakingOvertakingPermissionMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
						STATE_COORDINATORCOMMUNICATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(
						MW_getTargetPortIDforIdentifier(
								stateChart->parentComponent->overtakingInitiatorPort->ID),
						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,
						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
						STATE_COORDINATOROVERTAKINGINITIATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORIDLE" );

#endif

				// execute entry actions

				stateChart->coordinatorIsBusy = false;

				;

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
				false;

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
				false;

				//break;

			}

		}

		else if (0) {

			//dummy

		} else {

		}
		break;
	default:
		break;
	}
	stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable = false;
}

void CoordinatorOvertakingInitiatorOvertakingInitiatorPortStateChart_processStep(

CoordinatorCoordinatorComponentStateChart* stateChart) {

	switch (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort) {

	case STATE_COORDINATOROVERTAKINGINITIATORIDLE:

		if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)

		&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort

		== STATE_COORDINATORCOMMUNICATORIDLE)) {

			if (Port_doesMessageExist(

			CoordinatorComponent_getcommunicator(

			stateChart->parentComponent),

					MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE)

			&&

			stateChart->coordinatorIsBusy == false

			) {

				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getcommunicator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesRequestPermissionOvertakingPermissionMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =

				STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				stateChart->coordinatorIsBusy = true;

				;

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->overtakingInitiatorPort->ID),

						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =

				STATE_COORDINATOROVERTAKINGINITIATORINITIATING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORINITIATING" );

#endif

				// execute entry actions

				Clock_reset(

						stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock);

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =

				false;

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =

				false;

				//break;

			}

		} else if (0) {

			//dummy

		} else {

		}

		break;

	case STATE_COORDINATOROVERTAKINGINITIATORINITIATING:

		if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)

		&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort

		== STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION)) {

			if (1

					&&

					Clock_getTime(

							stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)

					> stateChart->coordinationTimeout * 1000.0

					) {

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->overtakingInitiatorPort->ID),

						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =

				STATE_COORDINATOROVERTAKINGINITIATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORIDLE" );

#endif

				// execute entry actions

				stateChart->coordinatorIsBusy = false;

				;

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->communicatorPort->ID),

						MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =

				STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =

				false;

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =

				false;

				//break;

			}

		}

		else if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)

		&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort

		== STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION)) {

			if (1

					&&

					Clock_getTime(

							stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)

					> stateChart->coordinationTimeout * 1000.0

					) {

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->overtakingInitiatorPort->ID),

						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =

				STATE_COORDINATOROVERTAKINGINITIATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORIDLE" );

#endif

				// execute entry actions

				stateChart->coordinatorIsBusy = false;

				;

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->communicatorPort->ID),

						MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =

				STATE_COORDINATORCOMMUNICATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =

				false;

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =

				false;

				//break;

			}

		}

		else if (0) {

			//dummy

		} else if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)

		&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort

		== STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION)) {

			if (1

					&& Port_doesMessageExist(

					CoordinatorComponent_getovertakingInitiator(

					stateChart->parentComponent),

							MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE)

							) {

				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getovertakingInitiator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertakingOvertakingCoordinationMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =

				STATE_COORDINATOROVERTAKINGINITIATORPASSING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->communicatorPort->ID),

						MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =

				STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =

				false;

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =

				false;

				//break;

			}

		}

		else if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)

		&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort

		== STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION)) {

			if (1

					&& Port_doesMessageExist(

					CoordinatorComponent_getovertakingInitiator(

					stateChart->parentComponent),

							MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE)

							) {

				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getovertakingInitiator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertakingOvertakingCoordinationMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =

				STATE_COORDINATOROVERTAKINGINITIATORPASSING;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->communicatorPort->ID),

						MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =

				STATE_COORDINATORCOMMUNICATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );

#endif

				// execute entry actions

				// nothing to do

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =

				false;

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =

				false;

				//break;

			}

		}

		else if (0) {

			//dummy

		} else {

		}

		break;

	case STATE_COORDINATOROVERTAKINGINITIATORPASSING:

		if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)

		&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort

		== STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING)) {

			if (Port_doesMessageExist(

			CoordinatorComponent_getcommunicator(

			stateChart->parentComponent),

					MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE)

			&& 1

			) {

				MiddlewareMessage* mwMsg =

						Port_receiveMessage(

						CoordinatorComponent_getcommunicator(

						stateChart->parentComponent),

								MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE);

#ifdef DEBUG

				printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesExecutedOvertakingOvertakingPermissionMessagesMessage");

#endif

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				// nothing to do

				//release all created received events

				free(mwMsg);

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =

				STATE_COORDINATORCOMMUNICATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );

#endif

				// execute entry actions

				// nothing to do

				// execute exit actions

				// nothing to do

				// Transition Effects (incl. clock resets)

				// nothing to do

				//send Message

				MW_sendMessage(

				MW_getTargetPortIDforIdentifier(

				stateChart->parentComponent->overtakingInitiatorPort->ID),

						MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,

						NULL);

#ifdef DEBUG

				printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

				//release all created received events

				//release all created sent events

				// change the state

				stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =

				STATE_COORDINATOROVERTAKINGINITIATORIDLE;

#ifdef DEBUG

				printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORIDLE" );

#endif

				// execute entry actions

				stateChart->coordinatorIsBusy = false;

				;

				stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =

				false;

				stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =

				false;

				//break;

			}

		}

		else

		if (0) {

			//dummy

		} else {

		}

		break;

	default:

		break;

	}

	stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =

	false;

}

void CoordinatorOvertakingAffiliateOvertakingAffiliatePortStateChart_processStep(

CoordinatorCoordinatorComponentStateChart* stateChart) {

	switch (stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort) {

	case STATE_COORDINATOROVERTAKINGAFFILIATEIDLE:

		if (Port_doesMessageExist(

		CoordinatorComponent_getovertakingAffiliate(

		stateChart->parentComponent),

				MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE)

		&& stateChart->coordinatorIsBusy == false

		) {

			MiddlewareMessage* mwMsg =

					Port_receiveMessage(

					CoordinatorComponent_getovertakingAffiliate(

					stateChart->parentComponent),

							MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE);

#ifdef DEBUG

			printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesRequestOvertakingOvertakingCoordinationMessagesMessage");

#endif

			// execute exit actions

			// nothing to do

			// Transition Effects (incl. clock resets)

			stateChart->coordinatorIsBusy = true;

			;

			// nothing to do

			//release all created received events

			free(mwMsg);

			//release all created sent events

			// change the state

			stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort =

			STATE_COORDINATOROVERTAKINGAFFILIATECOORDINATING;

#ifdef DEBUG

			printDebugInformation("currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort switched state to STATE_COORDINATOROVERTAKINGAFFILIATECOORDINATING" );

#endif

			// execute entry actions

			// nothing to do

		} else {

		}

		break;

	case STATE_COORDINATOROVERTAKINGAFFILIATECOORDINATING:

		if (1

		) {

			// execute exit actions

			// nothing to do

			// Transition Effects (incl. clock resets)

			// nothing to do

			//send Message

			MW_sendMessage(

			MW_getTargetPortIDforIdentifier(

			stateChart->parentComponent->overtakingAffiliatePort->ID),

					MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE,

					NULL);

#ifdef DEBUG

			printDebugInformation("Coordinator sent message of type MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE");

#endif

			//release all created received events

			//release all created sent events

			// change the state

			stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort =

			STATE_COORDINATOROVERTAKINGAFFILIATEGETTINGPASSED;

#ifdef DEBUG

			printDebugInformation("currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort switched state to STATE_COORDINATOROVERTAKINGAFFILIATEGETTINGPASSED" );

#endif

			// execute entry actions

			// nothing to do

		} else {

		}

		break;

	case STATE_COORDINATOROVERTAKINGAFFILIATEGETTINGPASSED:

		if (Port_doesMessageExist(

		CoordinatorComponent_getovertakingAffiliate(

		stateChart->parentComponent),

				MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE)

				) {

			MiddlewareMessage* mwMsg =

					Port_receiveMessage(

					CoordinatorComponent_getovertakingAffiliate(

					stateChart->parentComponent),

							MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE);

#ifdef DEBUG

			printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesFinishedOvertakingOvertakingCoordinationMessagesMessage");

#endif

			// execute exit actions

			// nothing to do

			// Transition Effects (incl. clock resets)

			// nothing to do

			// nothing to do

			//release all created received events

			free(mwMsg);

			//release all created sent events

			// change the state

			stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort =

			STATE_COORDINATOROVERTAKINGAFFILIATEIDLE;

#ifdef DEBUG

			printDebugInformation("currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort switched state to STATE_COORDINATOROVERTAKINGAFFILIATEIDLE" );

#endif

			// execute entry actions

			stateChart->coordinatorIsBusy = false;

			;

		} else {

		}

		break;

	default:

		break;

	}

	stateChart->CoordinatorOvertakingAffiliateOvertakingAffiliatePort_isExecutable =

	false;

}

void CoordinatorCoordinatorComponentStateChart_processStep(
		CoordinatorCoordinatorComponentStateChart* stateChart) {
	switch (stateChart->currentStateOfCoordinatorCoordinatorComponent) {
	case STATE_COORDINATORCOORDINATOR_MAIN:

		if (stateChart->CoordinatorOvertakingAffiliateOvertakingAffiliatePort_isExecutable)
			CoordinatorOvertakingAffiliateOvertakingAffiliatePortStateChart_processStep(
					stateChart);
		if (stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
			CoordinatorOvertakingInitiatorOvertakingInitiatorPortStateChart_processStep(
					stateChart);
		if (stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)
			CoordinatorCommunicatorCommunicatorPortStateChart_processStep(
					stateChart);

		break;
	default:
		break;
	}
	stateChart->CoordinatorCoordinatorComponent_isExecutable = false;
}

void CoordinatorCommunicatorCommunicatorPortStateChart_exit(
		CoordinatorCoordinatorComponentStateChart* stateChart) {
	switch (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort) {
	case STATE_COORDINATORCOMMUNICATORIDLE:
		// nothing to do

		break;
	case STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION:
		// nothing to do

		break;
	case STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING:
		// nothing to do

		break;
	default:
		break;
	}
	stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
			COORDINATORCOORDINATORCOMPONENT_INACTIVE;
}
void CoordinatorOvertakingInitiatorOvertakingInitiatorPortStateChart_exit(
		CoordinatorCoordinatorComponentStateChart* stateChart) {
	switch (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort) {
	case STATE_COORDINATOROVERTAKINGINITIATORIDLE:
		// nothing to do

		break;
	case STATE_COORDINATOROVERTAKINGINITIATORINITIATING:
		// nothing to do

		break;
	case STATE_COORDINATOROVERTAKINGINITIATORPASSING:
		// nothing to do

		break;
	default:
		break;
	}
	stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
			COORDINATORCOORDINATORCOMPONENT_INACTIVE;
}
void CoordinatorOvertakingAffiliateOvertakingAffiliatePortStateChart_exit(
		CoordinatorCoordinatorComponentStateChart* stateChart) {
	switch (stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort) {
	case STATE_COORDINATOROVERTAKINGAFFILIATEIDLE:
		// nothing to do

		break;
	case STATE_COORDINATOROVERTAKINGAFFILIATECOORDINATING:
		// nothing to do

		break;
	case STATE_COORDINATOROVERTAKINGAFFILIATEGETTINGPASSED:
		// nothing to do

		break;
	default:
		break;
	}
	stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort =
			COORDINATORCOORDINATORCOMPONENT_INACTIVE;
}

bool_t CoordinatorCoordinatorComponentStateChart_isInState(
		CoordinatorCoordinatorComponentStateChart* stateChart,
		CoordinatorCoordinatorComponentState state) {
	return (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort
			== state
			|| stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
					== state
			|| stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort
					== state);

}

//implementations for RTSC internal operations

