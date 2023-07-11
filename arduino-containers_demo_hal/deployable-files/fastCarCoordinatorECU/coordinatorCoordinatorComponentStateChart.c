

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
		
			//initialize variables of the root statechart
			stateChart->coordinationTimeout = stateChart->coordinationTimeout = 0;
			;
		
			stateChart->coordinatorIsBusy = false;
		
			//initialize port variables of the root statechart
		
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
		

			void CoordinatorCoordinatorComponentStateChart_destroy(CoordinatorCoordinatorComponentStateChart* stateChart) {
				if(stateChart != NULL) {
		
		
					free(stateChart);
				}
			}

		//implementations for RTSC internal operations
		
		
		
		void CoordinatorCommunicatorCommunicatorPortStateChart_processStep(
				CoordinatorCoordinatorComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort) {
			case STATE_COORDINATORCOMMUNICATORIDLE:
				if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
								== STATE_COORDINATOROVERTAKINGINITIATORIDLE)) {
					if (
		
					stateChart->coordinatorIsBusy == false
		
					//
		
							&& MCC_CoordinatorComponent_communicator_exists_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(
									CoordinatorComponent_getcommunicator(
											stateChart->parentComponent))
		
											) {
						OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesRequestPermission;
						MCC_CoordinatorComponent_communicator_recv_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(
								CoordinatorComponent_getcommunicator(
										stateChart->parentComponent),
								&msg_OvertakingPermissionMessagesRequestPermission);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
								STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						stateChart->coordinatorIsBusy = true;
						;
		
						//create new Parameter struct for OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesRequestOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesRequestOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesRequestOvertaking");
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
		
						//
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
					if (Clock_getTime(
							stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)
							> stateChart->coordinationTimeout * 1000.0
		
					&& 1
		
					) {
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesFinishedOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesFinishedOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesFinishedOvertaking");
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
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesGrantPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesGrantPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesGrantPermission");
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
		
						//
						stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
								false;
						stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
								false;
						//break;
					}
				} else if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
								== STATE_COORDINATOROVERTAKINGINITIATORINITIATING)) {
					if (MCC_CoordinatorComponent_overtakingInitiator_exists_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
							CoordinatorComponent_getovertakingInitiator(
									stateChart->parentComponent))
		
					&& 1
		
					) {
						OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesAcceptOvertaking;
						MCC_CoordinatorComponent_overtakingInitiator_recv_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
								CoordinatorComponent_getovertakingInitiator(
										stateChart->parentComponent),
								&msg_OvertakingCoordinationMessagesAcceptOvertaking);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
								STATE_COORDINATOROVERTAKINGINITIATORPASSING;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesGrantPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesGrantPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesGrantPermission");
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
		
						//
						stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
								false;
						stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
								false;
						//break;
					}
				} else if (0) {
					//dummy
				} else if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
								== STATE_COORDINATOROVERTAKINGINITIATORINITIATING)) {
					if (Clock_getTime(
							stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)
							> stateChart->coordinationTimeout * 1000.0
		
					&& 1
		
					) {
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesFinishedOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesFinishedOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesFinishedOvertaking");
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
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesDenyPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesDenyPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesDenyPermission");
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
		
						//
						stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
								false;
						stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
								false;
						//break;
					}
				} else if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
								== STATE_COORDINATOROVERTAKINGINITIATORINITIATING)) {
					if (MCC_CoordinatorComponent_overtakingInitiator_exists_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
							CoordinatorComponent_getovertakingInitiator(
									stateChart->parentComponent))
		
					&& 1
		
					) {
						OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesAcceptOvertaking;
						MCC_CoordinatorComponent_overtakingInitiator_recv_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
								CoordinatorComponent_getovertakingInitiator(
										stateChart->parentComponent),
								&msg_OvertakingCoordinationMessagesAcceptOvertaking);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
								STATE_COORDINATOROVERTAKINGINITIATORPASSING;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesDenyPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesDenyPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesDenyPermission");
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
		
						//
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
			case STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING:
				if ((stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
								== STATE_COORDINATOROVERTAKINGINITIATORPASSING)) {
					if (1
		
							&& MCC_CoordinatorComponent_communicator_exists_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(
									CoordinatorComponent_getcommunicator(
											stateChart->parentComponent))
		
											) {
						OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesExecutedOvertaking;
						MCC_CoordinatorComponent_communicator_recv_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(
								CoordinatorComponent_getcommunicator(
										stateChart->parentComponent),
								&msg_OvertakingPermissionMessagesExecutedOvertaking);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
								STATE_COORDINATORCOMMUNICATORIDLE;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesFinishedOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesFinishedOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesFinishedOvertaking");
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
		
						//
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
					if (MCC_CoordinatorComponent_communicator_exists_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(
							CoordinatorComponent_getcommunicator(
									stateChart->parentComponent))
		
					&&
		
					stateChart->coordinatorIsBusy == false
		
					//
		
							) {
						OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesRequestPermission;
						MCC_CoordinatorComponent_communicator_recv_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(
								CoordinatorComponent_getcommunicator(
										stateChart->parentComponent),
								&msg_OvertakingPermissionMessagesRequestPermission);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
								STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						stateChart->coordinatorIsBusy = true;
						;
		
						//create new Parameter struct for OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesRequestOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesRequestOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesRequestOvertaking");
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
		
						//
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
		
							&& Clock_getTime(
									stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)
									> stateChart->coordinationTimeout * 1000.0
		
									) {
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesFinishedOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesFinishedOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesFinishedOvertaking");
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
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesGrantPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesGrantPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesGrantPermission");
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
		
						//
						stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
								false;
						stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
								false;
						//break;
					}
				} else if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort
								== STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION)) {
					if (1
		
							&& Clock_getTime(
									stateChart->coordinatorCoordinationTimeCoordinatorCoordinatorComponentClock)
									> stateChart->coordinationTimeout * 1000.0
		
									) {
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesFinishedOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesFinishedOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesFinishedOvertaking");
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
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesDenyPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesDenyPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesDenyPermission");
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
		
						//
						stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
								false;
						stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
								false;
						//break;
					}
				} else if (0) {
					//dummy
				} else if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort
								== STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION)) {
					if (1
		
							&& MCC_CoordinatorComponent_overtakingInitiator_exists_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
									CoordinatorComponent_getovertakingInitiator(
											stateChart->parentComponent))
		
											) {
						OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesAcceptOvertaking;
						MCC_CoordinatorComponent_overtakingInitiator_recv_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
								CoordinatorComponent_getovertakingInitiator(
										stateChart->parentComponent),
								&msg_OvertakingCoordinationMessagesAcceptOvertaking);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
								STATE_COORDINATOROVERTAKINGINITIATORPASSING;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesGrantPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesGrantPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesGrantPermission");
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
		
						//
						stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable =
								false;
						stateChart->CoordinatorOvertakingInitiatorOvertakingInitiatorPort_isExecutable =
								false;
						//break;
					}
				} else if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort
								== STATE_COORDINATORCOMMUNICATORWAITFORCOORDINATION)) {
					if (1
		
							&& MCC_CoordinatorComponent_overtakingInitiator_exists_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
									CoordinatorComponent_getovertakingInitiator(
											stateChart->parentComponent))
		
											) {
						OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesAcceptOvertaking;
						MCC_CoordinatorComponent_overtakingInitiator_recv_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
								CoordinatorComponent_getovertakingInitiator(
										stateChart->parentComponent),
								&msg_OvertakingCoordinationMessagesAcceptOvertaking);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort =
								STATE_COORDINATOROVERTAKINGINITIATORPASSING;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort switched state to STATE_COORDINATOROVERTAKINGINITIATORPASSING" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesDenyPermission;
		
						//send Message
						MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->communicatorPort),
								&msg_OvertakingPermissionMessagesDenyPermission);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingPermissionMessagesDenyPermission");
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
		
						//
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
			case STATE_COORDINATOROVERTAKINGINITIATORPASSING:
				if ((stateChart->CoordinatorCommunicatorCommunicatorPort_isExecutable)
						&& (stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort
								== STATE_COORDINATORCOMMUNICATORWAITFOROVERTAKING)) {
					if (MCC_CoordinatorComponent_communicator_exists_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(
							CoordinatorComponent_getcommunicator(
									stateChart->parentComponent))
		
					&& 1
		
					) {
						OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesExecutedOvertaking;
						MCC_CoordinatorComponent_communicator_recv_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(
								CoordinatorComponent_getcommunicator(
										stateChart->parentComponent),
								&msg_OvertakingPermissionMessagesExecutedOvertaking);
		
		#ifdef DEBUG
						printDebugInformation("Coordinator received message of typeOvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort =
								STATE_COORDINATORCOMMUNICATORIDLE;
		#ifdef DEBUG
						printDebugInformation("currentStateOfCoordinatorCommunicatorCommunicatorPort switched state to STATE_COORDINATORCOMMUNICATORIDLE" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message
						OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesFinishedOvertaking;
		
						//send Message
						MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
								&(stateChart->parentComponent->overtakingInitiatorPort),
								&msg_OvertakingCoordinationMessagesFinishedOvertaking);
		#ifdef DEBUG
						printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesFinishedOvertaking");
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
		
						//
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
				if (MCC_CoordinatorComponent_overtakingAffiliate_exists_OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message(
						CoordinatorComponent_getovertakingAffiliate(
								stateChart->parentComponent))
		
				&& stateChart->coordinatorIsBusy == false
		
				//
		
						) {
					OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesRequestOvertaking;
					MCC_CoordinatorComponent_overtakingAffiliate_recv_OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message(
							CoordinatorComponent_getovertakingAffiliate(
									stateChart->parentComponent),
							&msg_OvertakingCoordinationMessagesRequestOvertaking);
		
		#ifdef DEBUG
					printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message");
		#endif
		
					// execute exit actions
					// nothing to do
		
					// Transition Effects (incl. clock resets)
		
					stateChart->coordinatorIsBusy = true;
					;
		
					// nothing to do			
		
					//release all created received events
					//	free(mwMsg);
		
					//release all created sent events
					// change the state
					stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort =
							STATE_COORDINATOROVERTAKINGAFFILIATECOORDINATING;
		#ifdef DEBUG
					printDebugInformation("currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort switched state to STATE_COORDINATOROVERTAKINGAFFILIATECOORDINATING" );
		#endif		
		
					// execute entry actions
					// nothing to do
		
					//
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
		
					//create new Parameter struct for OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message
					OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesAcceptOvertaking;
		
					//send Message
					MCC_CoordinatorComponent_overtakingAffiliate_send_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(
							&(stateChart->parentComponent->overtakingAffiliatePort),
							&msg_OvertakingCoordinationMessagesAcceptOvertaking);
		#ifdef DEBUG
					printDebugInformation("Coordinator sent message of type OvertakingCoordinationMessagesAcceptOvertaking");
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
		
					//
				} else {
		
				}
				break;
			case STATE_COORDINATOROVERTAKINGAFFILIATEGETTINGPASSED:
				if (MCC_CoordinatorComponent_overtakingAffiliate_exists_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
						CoordinatorComponent_getovertakingAffiliate(
								stateChart->parentComponent))
		
								) {
					OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message msg_OvertakingCoordinationMessagesFinishedOvertaking;
					MCC_CoordinatorComponent_overtakingAffiliate_recv_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(
							CoordinatorComponent_getovertakingAffiliate(
									stateChart->parentComponent),
							&msg_OvertakingCoordinationMessagesFinishedOvertaking);
		
		#ifdef DEBUG
					printDebugInformation("Coordinator received message of typeOvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message");
		#endif
		
					// execute exit actions
					// nothing to do
		
					// Transition Effects (incl. clock resets)
					// nothing to do
		
					// nothing to do			
		
					//release all created received events
					//	free(mwMsg);
		
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
		
					//
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
				
			
		bool_t CoordinatorCoordinatorComponentStateChart_isInState(
				CoordinatorCoordinatorComponentStateChart* stateChart,
				CoordinatorCoordinatorComponentState state) {
			return (stateChart->currentStateOfCoordinatorOvertakingInitiatorOvertakingInitiatorPort
					== state
					|| stateChart->currentStateOfCoordinatorOvertakingAffiliateOvertakingAffiliatePort
							== state
					|| stateChart->currentStateOfCoordinatorCommunicatorCommunicatorPort
							== state);
		
		}
		

	

