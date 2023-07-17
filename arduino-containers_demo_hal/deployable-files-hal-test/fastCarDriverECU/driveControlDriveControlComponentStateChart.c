

		#include "driveControlComponent_Interface.h"
		



		void initializeDriveControlDriveControlDriveControlPortRegion(
				DriveControlDriveControlComponentStateChart* stateChart) {
		
			stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
					STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING;
		
			stateChart->DriveControlDriveControlDriveControlPort_isExecutable = true;
		
		}
		void initializeDriveControlDriveControl_mainDrivingRegion(
				DriveControlDriveControlComponentStateChart* stateChart) {
		
			Clock_reset(
					stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANEDoClock);
			Clock_reset(
					stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLEDoClock);
			Clock_reset(
					stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKINGDoClock);
		
			stateChart->currentStateOfDriveControlDriveControl_mainDriving =
					STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE;
		
			stateChart->DriveControlDriveControl_mainDriving_isExecutable = true;
		
		}
		
		void DriveControlDriveControlComponentStateChart_initialize(
				DriveControlDriveControlComponentStateChart* stateChart) {
			//initialize clocks
		
			//initialize variables of the root statechart
			stateChart->distanceLimit = stateChart->distanceLimit = distanceLimit;
			;
		
			stateChart->desiredVelocity = stateChart->desiredVelocity = desiredVelocity;
			;
		
			stateChart->slowVelocity = stateChart->slowVelocity = slowVelocity;
			;
		
			stateChart->laneDistance = stateChart->laneDistance = laneDistance;
			;
		
			//initialize port variables of the root statechart
		
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

		//implementations for RTSC internal operations
		
		
		
		void DriveControlDriveControlDriveControlPortStateChart_processStep(
				DriveControlDriveControlComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfDriveControlDriveControlDriveControlPort) {
			case STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING:
				if (
		
				stateChart->frontDistance < stateChart->distanceLimit
		
				//
		
						) {
		
					// execute exit actions
					// nothing to do
		
					// Transition Effects (incl. clock resets)
		
					stateChart->velocity = stateChart->slowVelocity;
					;
		
					//create new Parameter struct for OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message
					OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesRequestPermission;
		
					//send Message
					MCC_DriveControlComponent_driveControl_send_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(
							&(stateChart->parentComponent->driveControlPort),
							&msg_OvertakingPermissionMessagesRequestPermission);
		#ifdef DEBUG
					printDebugInformation("DriveControl sent message of type OvertakingPermissionMessagesRequestPermission");
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
		
					//
				} else {
		
				}
				break;
			case STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION:
				if ((stateChart->DriveControlDriveControl_mainDriving_isExecutable)
						&& (stateChart->currentStateOfDriveControlDriveControl_mainDriving
								== STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE)) {
					if (1
		
							&& MCC_DriveControlComponent_driveControl_exists_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
									DriveControlComponent_getdriveControl(
											stateChart->parentComponent))
		
											) {
						OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesGrantPermission;
						MCC_DriveControlComponent_driveControl_recv_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
								DriveControlComponent_getdriveControl(
										stateChart->parentComponent),
								&msg_OvertakingPermissionMessagesGrantPermission);
		
		#ifdef DEBUG
						printDebugInformation("DriveControl received message of typeOvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						stateChart->velocity = stateChart->desiredVelocity;
						;
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
								STATE_DRIVECONTROLDRIVECONTROLOVERTAKING;
		#ifdef DEBUG
						printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLOVERTAKING" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
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
						Clock_reset(
								stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLEDoClock);
		
						// execute entry actions
						// nothing to do
		
						//
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
								false;
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
								false;
						//break;
					}
				} else if (0) {
					//dummy
				} else if (MCC_DriveControlComponent_driveControl_exists_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(
						DriveControlComponent_getdriveControl(
								stateChart->parentComponent))
		
								) {
					OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesDenyPermission;
					MCC_DriveControlComponent_driveControl_recv_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(
							DriveControlComponent_getdriveControl(
									stateChart->parentComponent),
							&msg_OvertakingPermissionMessagesDenyPermission);
		
		#ifdef DEBUG
					printDebugInformation("DriveControl received message of typeOvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message");
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
					stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
							STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING;
		#ifdef DEBUG
					printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING" );
		#endif		
		
					// execute entry actions
					// nothing to do
		
					//
				} else {
		
				}
				break;
			case STATE_DRIVECONTROLDRIVECONTROLOVERTAKING:
				if ((stateChart->DriveControlDriveControl_mainDriving_isExecutable)
						&& (stateChart->currentStateOfDriveControlDriveControl_mainDriving
								== STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKING)) {
					if (
		
					stateChart->rearDistance > 2 * stateChart->distanceLimit
		
					//
		
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
						Clock_reset(
								stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANEDoClock);
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesExecutedOvertaking;
		
						//send Message
						MCC_DriveControlComponent_driveControl_send_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->driveControlPort),
								&msg_OvertakingPermissionMessagesExecutedOvertaking);
		#ifdef DEBUG
						printDebugInformation("DriveControl sent message of type OvertakingPermissionMessagesExecutedOvertaking");
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
		
						//
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
								false;
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
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
			stateChart->DriveControlDriveControlDriveControlPort_isExecutable = false;
		}
		
		void DriveControlDriveControl_mainDrivingStateChart_processStep(
				DriveControlDriveControlComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfDriveControlDriveControl_mainDriving) {
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE:
				if ((stateChart->DriveControlDriveControlDriveControlPort_isExecutable)
						&& (stateChart->currentStateOfDriveControlDriveControlDriveControlPort
								== STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION)) {
					if (MCC_DriveControlComponent_driveControl_exists_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
							DriveControlComponent_getdriveControl(
									stateChart->parentComponent))
		
					&& 1
		
					) {
						OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesGrantPermission;
						MCC_DriveControlComponent_driveControl_recv_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(
								DriveControlComponent_getdriveControl(
										stateChart->parentComponent),
								&msg_OvertakingPermissionMessagesGrantPermission);
		
		#ifdef DEBUG
						printDebugInformation("DriveControl received message of typeOvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message");
		#endif
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
		
						stateChart->velocity = stateChart->desiredVelocity;
						;
		
						// nothing to do			
		
						//release all created received events
						//	free(mwMsg);
		
						//release all created sent events
						// change the state
						stateChart->currentStateOfDriveControlDriveControlDriveControlPort =
								STATE_DRIVECONTROLDRIVECONTROLOVERTAKING;
		#ifdef DEBUG
						printDebugInformation("currentStateOfDriveControlDriveControlDriveControlPort switched state to STATE_DRIVECONTROLDRIVECONTROLOVERTAKING" );
		#endif		
		
						// execute entry actions
						// nothing to do
		
						//
		
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
						Clock_reset(
								stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLEDoClock);
		
						// execute entry actions
						// nothing to do
		
						//
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
								false;
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
								false;
						//break;
					}
				} else if (0) {
					//dummy
				} else {
		
					//execute doEvent
					if (Clock_getTime(
							stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANEDoClock)
							>= 1 * 1.0) {
						//execute action followMainLane
						RobotCarPowerTrain_robotCarPowerTrainFollowLine(
								stateChart->desiredVelocity);
		
						Clock_reset(
								stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANEDoClock);
					}
		
				}
				break;
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE:
				if (
		
				stateChart->rearDistance < stateChart->laneDistance
		
				//
		
						) {
		
					// execute exit actions
					// nothing to do
		
					// Transition Effects (incl. clock resets)
					// nothing to do
		
					// nothing to do			
		
					//release all created received events
					//release all created sent events
					// change the state
					stateChart->currentStateOfDriveControlDriveControl_mainDriving =
							STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKING;
		#ifdef DEBUG
					printDebugInformation("currentStateOfDriveControlDriveControl_mainDriving switched state to STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKING" );
		#endif		
					Clock_reset(
							stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKINGDoClock);
		
					// execute entry actions
					// nothing to do
		
					//
				} else {
		
					//execute doEvent
					if (Clock_getTime(
							stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLEDoClock)
							>= 1 * 1.0) {
						//execute action followFastLane
						RobotCarPowerTrain_robotCarPowerTrainFollowLine(
								stateChart->desiredVelocity);
		
						Clock_reset(
								stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLEDoClock);
					}
		
				}
				break;
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKING:
				if ((stateChart->DriveControlDriveControlDriveControlPort_isExecutable)
						&& (stateChart->currentStateOfDriveControlDriveControlDriveControlPort
								== STATE_DRIVECONTROLDRIVECONTROLOVERTAKING)) {
					if (1
		
					&&
		
					stateChart->rearDistance > 2 * stateChart->distanceLimit
		
					//
		
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
						Clock_reset(
								stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANEDoClock);
		
						// execute entry actions
						// nothing to do
		
						//
		
						// execute exit actions
						// nothing to do
		
						// Transition Effects (incl. clock resets)
						// nothing to do
		
						//create new Parameter struct for OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message
						OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message msg_OvertakingPermissionMessagesExecutedOvertaking;
		
						//send Message
						MCC_DriveControlComponent_driveControl_send_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(
								&(stateChart->parentComponent->driveControlPort),
								&msg_OvertakingPermissionMessagesExecutedOvertaking);
		#ifdef DEBUG
						printDebugInformation("DriveControl sent message of type OvertakingPermissionMessagesExecutedOvertaking");
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
		
						//
						stateChart->DriveControlDriveControlDriveControlPort_isExecutable =
								false;
						stateChart->DriveControlDriveControl_mainDriving_isExecutable =
								false;
						//break;
					}
				} else if (0) {
					//dummy
				} else {
		
					//execute doEvent
					if (Clock_getTime(
							stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKINGDoClock)
							>= 1 * 1.0) {
						//execute action followFastLane
						RobotCarPowerTrain_robotCarPowerTrainFollowLine(
								stateChart->desiredVelocity);
		
						Clock_reset(
								stateChart->sTATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKINGDoClock);
					}
		
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
		
		
		void DriveControlDriveControl_mainDrivingStateChart_exit(
				DriveControlDriveControlComponentStateChart* stateChart) {
			switch (stateChart->currentStateOfDriveControlDriveControl_mainDriving) {
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE:
				// nothing to do
		
				break;
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE:
				// nothing to do
		
				break;
			case STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGCOMPLETEOVERTAKING:
				// nothing to do
		
				break;
			default:
				break;
			}
			stateChart->currentStateOfDriveControlDriveControl_mainDriving =
					DRIVECONTROLDRIVECONTROLCOMPONENT_INACTIVE;
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
				
			
		bool_t DriveControlDriveControlComponentStateChart_isInState(
				DriveControlDriveControlComponentStateChart* stateChart,
				DriveControlDriveControlComponentState state) {
			return (stateChart->currentStateOfDriveControlDriveControl_mainDriving
					== state
					|| stateChart->currentStateOfDriveControlDriveControlDriveControlPort
							== state);
		
		}
		

	
