

		#include "driveControlComponent_Interface.h"
		



		void initializeDriveControlDriveControlDriveControlPortRegion(
				DriveControlDriveControlComponentStateChart* stateChart) {
		
			stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
					STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING;
		
			stateChart->DriveControlDriveControlDriveControlPort_isExecutable = true;
		
		}
		void initializeDriveControlDriveControl_mainDrivingRegion(
				DriveControlDriveControlComponentStateChart* stateChart) {
		
			stateChart->currentStateOfDriveControlDriveControl_mainDriving =
					STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE;
		
			stateChart->DriveControlDriveControl_mainDriving_isExecutable = true;
		
		}
		
		void DriveControlDriveControlComponentStateChart_initialize(
				DriveControlDriveControlComponentStateChart* stateChart) {
			//initialize clocks
		
			//initialize hybrid ports
		
			//initialize variables of the root statechart
			stateChart->distanceLimit = stateChart->distanceLimit = 0;
			;
		
			stateChart->desiredVelocity = stateChart->desiredVelocity = 0;
			;
		
			stateChart->slowVelocity = stateChart->slowVelocity = 0;
			;
		
			//initialize init state
			stateChart->currentStateOfDriveControlDriveControlComponent =
					STATE_DRIVECONTROLDRIVECONTROL_MAIN;
		
			initializeDriveControlDriveControlDriveControlPortRegion(stateChart);
			initializeDriveControlDriveControl_mainDrivingRegion(stateChart);
		}
		
		

		DriveControlDriveControlComponentStateChart* DriveControlDriveControlComponentStateChart_create(
				DriveControlComponent* parentComponent) {
			DriveControlDriveControlComponentStateChart* stateChart =
					(DriveControlDriveControlComponentStateChart*) malloc(
							sizeof(DriveControlDriveControlComponentStateChart));
			if (stateChart != NULL) {
				stateChart->parentComponent = parentComponent;
				if (stateChart->parentComponent != NULL) {
					DriveControlDriveControlComponentStateChart_initialize(stateChart);
				} else {
		
					DriveControlDriveControlComponentStateChart_destroy(stateChart);
					stateChart = NULL;
				}
			} else {
		
			}
			return stateChart;
		}
		

			void DriveControlDriveControlComponentStateChart_destroy(DriveControlDriveControlComponentStateChart* stateChart) {
				if(stateChart != NULL) {
		
		
					free(stateChart);
				}
			}


		
		void DriveControlDriveControlDriveControlPortStateChart_processStep(
				DriveControlDriveControlComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfDriveControlDriveControlDriveControlPort) {
			case STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING:
				if (
		
				stateChart->distance < stateChart->distanceLimit
		
				) {
		
					// execute exit actions
		
					// nothing to do
		
					// Transition Effects (incl. clock resets)
		
					stateChart->velocity = stateChart->slowVelocity;
		
					;
		
					//send Message
		
					MW_sendMessage(
							MW_getTargetPortIDforIdentifier(
									stateChart->parentComponent->driveControlPort->ID),
							MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,
							NULL);
		
		#ifdef DEBUG
		
					printDebugInformation("DriveControl sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE");
		
		#endif		
		
					//release all created received events
		
					//release all created sent events
		
					// change the state
		
					stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
							STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION;
		
		#ifdef DEBUG
		
					printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION" );
		
		#endif		
		
					// execute entry actions
		
					// nothing to do
		
				} else {
		
				}
				break;
			case STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION:
				if ((stateChart->DriveControlDriveControl_mainDriving_isExecutable)
						&& (stateChart->currentStateOfDriveControlDriveControl_mainDriving
								== STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE)) {
		
					if (1
		
							&& Port_doesMessageExist(
									DriveControlComponent_getdriveControl(
											stateChart->parentComponent),
									MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE)
		
									) {
		
						MiddlewareMessage* mwMsg =
		
								Port_receiveMessage(
		
								DriveControlComponent_getdriveControl(
		
								stateChart->parentComponent),
		
										MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE);
		
		#ifdef DEBUG
		
						printDebugInformation("DriveControl received message of typeOvertakingPermissionMessagesGrantPermissionOvertakingPermissionMessagesMessage");
		
		#endif
		
						// execute exit actions
		
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						stateChart->velocity = stateChart->desiredVelocity;
		
						;
		
						// nothing to do			
		
						//release all created received events
		
						free(mwMsg);
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
								STATE_DRIVECONTROLDRIVECONTROLOVERTAKING;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLOVERTAKING" );
		
		#endif		
		
						// execute entry actions
		
						// nothing to do
		
						// execute exit actions
		
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						RobotCarPowerTrain_robotCarPowerTrainChangeLaneLeft(
								stateChart->desiredVelocity);
		
						;
		
						// nothing to do			
		
						//release all created received events
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControl_mainDriving =
								STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControl_mainDriving switched state to STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE" );
		
		#endif		
		
						// execute entry actions
		
						// nothing to do
		
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
								false;
		
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
								false;
		
						//break;
		
					}
		
				}
		
				else if (0) {
		
					//dummy
		
				} else if (Port_doesMessageExist(
						DriveControlComponent_getdriveControl(
								stateChart->parentComponent),
						MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE)
		
						) {
					MiddlewareMessage* mwMsg =
		
							Port_receiveMessage(
		
							DriveControlComponent_getdriveControl(
		
							stateChart->parentComponent),
		
									MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE);
		
		#ifdef DEBUG
		
					printDebugInformation("DriveControl received message of typeOvertakingPermissionMessagesDenyPermissionOvertakingPermissionMessagesMessage");
		
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
		
					stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
							STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING;
		
		#ifdef DEBUG
		
					printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING" );
		
		#endif		
		
					// execute entry actions
		
					// nothing to do
		
				} else {
		
				}
				break;
			case STATE_DRIVECONTROLDRIVECONTROLOVERTAKING:
				if ((stateChart->DriveControlDriveControl_mainDriving_isExecutable)
						&& (stateChart->currentStateOfDriveControlDriveControl_mainDriving
								== STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE)) {
		
					if (
		
					stateChart->distance > stateChart->distanceLimit
		
					&& 1
		
					) {
		
						// execute exit actions
		
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						RobotCarPowerTrain_robotCarPowerTrainChangeLaneRight(
								stateChart->desiredVelocity);
		
						;
		
						// nothing to do			
		
						//release all created received events
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControl_mainDriving =
								STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControl_mainDriving switched state to STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE" );
		
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
										stateChart->parentComponent->driveControlPort->ID),
								MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE,
								NULL);
		
		#ifdef DEBUG
		
						printDebugInformation("DriveControl sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE");
		
		#endif		
		
						//release all created received events
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
								STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING" );
		
		#endif		
		
						// execute entry actions
		
						// nothing to do
		
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
								false;
		
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
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
			stateChart->DriveControlDriveControlDriveControlPort_isExecutable = false;
		}
		
		void DriveControlDriveControl_mainDrivingStateChart_processStep(
		
		DriveControlDriveControlComponentStateChart* stateChart) {
		
			switch (stateChart->currentStateOfDriveControlDriveControl_mainDriving) {
		
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE:
		
				if ((stateChart->DriveControlDriveControlDriveControlPort_isExecutable)
		
				&& (stateChart->currentStateOfDriveControlDriveControlDriveControlPort
		
				== STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION)) {
		
					if (Port_doesMessageExist(
		
					DriveControlComponent_getdriveControl(
		
					stateChart->parentComponent),
		
							MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE)
		
					&& 1
		
					) {
		
						MiddlewareMessage* mwMsg =
		
								Port_receiveMessage(
		
								DriveControlComponent_getdriveControl(
		
								stateChart->parentComponent),
		
										MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE);
		
		#ifdef DEBUG
		
						printDebugInformation("DriveControl received message of typeOvertakingPermissionMessagesGrantPermissionOvertakingPermissionMessagesMessage");
		
		#endif
		
						// execute exit actions
		
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						stateChart->velocity = stateChart->desiredVelocity;
		
						;
		
						// nothing to do			
		
						//release all created received events
		
						free(mwMsg);
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
		
						STATE_DRIVECONTROLDRIVECONTROLOVERTAKING;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLOVERTAKING" );
		
		#endif		
		
						// execute entry actions
		
						// nothing to do
		
						// execute exit actions
		
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						RobotCarPowerTrain_robotCarPowerTrainChangeLaneLeft(
		
						stateChart->desiredVelocity);
		
						;
		
						// nothing to do			
		
						//release all created received events
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControl_mainDriving =
		
						STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControl_mainDriving switched state to STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE" );
		
		#endif		
		
						// execute entry actions
		
						// nothing to do
		
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
		
						false;
		
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
		
						false;
		
						//break;
		
					}
		
				} else if (0) {
		
					//dummy
		
				} else {
		
				}
		
				break;
		
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE:
		
				if ((stateChart->DriveControlDriveControlDriveControlPort_isExecutable)
		
				&& (stateChart->currentStateOfDriveControlDriveControlDriveControlPort
		
				== STATE_DRIVECONTROLDRIVECONTROLOVERTAKING)) {
		
					if (1
		
					&&
		
					stateChart->distance > stateChart->distanceLimit
		
					) {
		
						// execute exit actions
		
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						RobotCarPowerTrain_robotCarPowerTrainChangeLaneRight(
		
						stateChart->desiredVelocity);
		
						;
		
						// nothing to do			
		
						//release all created received events
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControl_mainDriving =
		
						STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControl_mainDriving switched state to STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE" );
		
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
		
						stateChart->parentComponent->driveControlPort->ID),
		
								MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE,
		
								NULL);
		
		#ifdef DEBUG
		
						printDebugInformation("DriveControl sent message of type MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE");
		
		#endif		
		
						//release all created received events
		
						//release all created sent events
		
						// change the state
		
						stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
		
						STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING;
		
		#ifdef DEBUG
		
						printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING" );
		
		#endif		
		
						// execute entry actions
		
						// nothing to do
		
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
		
						false;
		
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
		
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
		
			stateChart->DriveControlDriveControl_mainDriving_isExecutable = false;
		
		}
		
		void DriveControlDriveControlComponentStateChart_processStep(
				DriveControlDriveControlComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfDriveControlDriveControlComponent) {
			case STATE_DRIVECONTROLDRIVECONTROL_MAIN:
		
				if (stateChart->DriveControlDriveControl_mainDriving_isExecutable)
					DriveControlDriveControl_mainDrivingStateChart_processStep(
							stateChart);
				if (stateChart->DriveControlDriveControlDriveControlPort_isExecutable)
					DriveControlDriveControlDriveControlPortStateChart_processStep(
							stateChart);
		
				break;
			default:
				break;
			}
			stateChart->DriveControlDriveControlComponent_isExecutable = false;
		}
		
		
		void DriveControlDriveControlDriveControlPortStateChart_exit(
				DriveControlDriveControlComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfDriveControlDriveControlDriveControlPort) {
			case STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING:
				// nothing to do
		
				break;
			case STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION:
				// nothing to do
		
				break;
			case STATE_DRIVECONTROLDRIVECONTROLOVERTAKING:
				// nothing to do
		
				break;
			default:
				break;
			}
			stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
					DRIVECONTROLDRIVECONTROLCOMPONENT_INACTIVE;
		}
		void DriveControlDriveControl_mainDrivingStateChart_exit(
				DriveControlDriveControlComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfDriveControlDriveControl_mainDriving) {
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE:
				// nothing to do
		
				break;
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE:
				// nothing to do
		
				break;
			default:
				break;
			}
			stateChart->currentStateOfDriveControlDriveControl_mainDriving =
					DRIVECONTROLDRIVECONTROLCOMPONENT_INACTIVE;
		}
				
			
		bool_t DriveControlDriveControlComponentStateChart_isInState(
				DriveControlDriveControlComponentStateChart* stateChart,
				DriveControlDriveControlComponentState state) {
			return (stateChart->currentStateOfDriveControlDriveControlDriveControlPort
					== state
					|| stateChart->currentStateOfDriveControlDriveControl_mainDriving
							== state);
		
		}
		

		//implementations for RTSC internal operations
		
		

