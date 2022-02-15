	/**
 * @file 
 * @author generated by Fraunhofer IEM
 * @brief Specification of Component of Type: DriveControl
 * @details This files contains a description of the DriveControl in form of the DriveControlComponent
 * 			and all methods which can be executed on an Instance of this Component
 */
		#ifndef DRIVECONTROLCOMPONENT_Interface_H_
		#define DRIVECONTROLCOMPONENT_Interface_H_

#ifdef __cplusplus
  extern "C" {
#endif		// Library
	#include "../types/standardTypes.h"
	#include "../types/customTypes.h"
	#include "../lib/port.h"
		#include "../messages/messages_types.h"
	#include "../lib/clock.h"
	#include "../lib/Debug.h"


		

	//include Operation Repositories
			#include "../operations/robotCarPowerTrainOpRep.h"




		//#include "../continuousComponents/contImplementations.h"	

		//#include "../RTSCs/driveControlDriveControlComponentStateChart.h"
			/*****
 			 *
 			 *  Forward Delcaration of Container Functions
 			 *
 			 */		
					void MCC_DriveControlComponent_driveControl_send_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(Port* p, OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message* msg);
					void MCC_DriveControlComponent_driveControl_send_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(Port* p, OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message* msg);
					bool_T MCC_DriveControlComponent_driveControl_recv_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(Port* p, OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message* msg);
					bool_T MCC_DriveControlComponent_driveControl_exists_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(Port* p);
					bool_T MCC_DriveControlComponent_driveControl_recv_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(Port* p, OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message* msg);
					bool_T MCC_DriveControlComponent_driveControl_exists_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(Port* p);
			
					bool_T MCC_DriveControlComponent_distance_recv_value(Port* p, double_T* value);
					bool_T MCC_DriveControlComponent_distance_exists_value(Port* p);
						void MCC_DriveControlComponent_velocity_send_value(Port* p, double_T* value);
			
			
	
			/*****
 			 *
 			 *  Component Functions
 			 *
 			 */
			/**
			 * @file 
			 * @author generated by Fraunhofer IEM 
			 * @brief Specification of Component of Type: DriveControl
			 * @details This files contains a description of the DriveControl in form of the DriveControlComponent
			 * 			and all methods which can be executed on an Instance of this Component
			 */
				
						/**
						 * @brief Forward Declaration of the struct DriveControlDriveControlComponentStateChart which describes the behavior of DriveControlComponent
						 * 
						 */
						 typedef struct DriveControlDriveControlComponentStateChart DriveControlDriveControlComponentStateChart;
						/**
						 * @brief Forward Declaration of the struct DriveControlComponent
						 */
							typedef struct DriveControlComponent DriveControlComponent;
						
						/**
						*  
						* @brief Description for a ComponentInstance of Type: DriveControl
						* @details This struct describes a specific Component Instances which is typed over the Component: DriveControl
						*/
						struct DriveControlComponent {
						
								uint8_T ID;	
						
						
									DriveControlDriveControlComponentStateChart* stateChart;	/**< The DriveControlDriveControlComponentStateChart of the Component DriveControl */
							
										Port distancePort; /**< A  Component's Port: distance */
										Port driveControlPort; /**< A  Component's Port: driveControl */
										Port velocityPort; /**< A  Component's Port: velocity */
										Clock distancePortClock; /**< A  Hybrid/ Continuous Port's Clock: distancePortClock */
										Clock velocityPortClock; /**< A  Hybrid/ Continuous Port's Clock: velocityPortClock */
								
						
								
								
						
								DriveControlComponent * next;/**< A Pointer to the next component part, if this component ist part of a multipart in the CIC */
								
							};
					
						/**
						* @brief This Methodes intializes the Component: DriveControl
						* @details All struct members of the struct DriveControlComponent are initialized
						* 
						* @param component The DriveControlComponent to be initialized
						*/	
							void DriveControlComponent_initialize(DriveControlComponent* component);
				
						/**
						* @brief Creates a Instance of the Component: DriveControl
						* @details Allocates Memory for the struct DriveControlComponent
						* @return A Pointer to the new created DriveControlComponent
						*/
							DriveControlComponent DriveControlComponent_create();
				
						/**
						 * @brief Destroys a Component: DriveControl
						 * @details Frees the Memory for the struct DriveControlComponent
						 * 
						* @param component The specific DriveControlComponent to be destroyed
						 */
							void DriveControlComponent_destroy(DriveControlComponent* component);
						
						/**
						* @brief Executes the next Step of the behavior an Instance of the Component: DriveControl
						* @details The behavior of the Component:  DriveControl is executed.
						*			
						* @param component The DriveControlComponent whose behavior shall be checked
						*/
							void DriveControlComponent_processStep(DriveControlComponent* component);
				
			
			
			
			
						/*Getter and Setter for Sending Values of Hybrid/Continuous ports*/
								bool_T getterOf_distance(Port* distancePort, double_T* distance);/**< A Pointer to the getter function of the port: distance */
									void setterOf_velocity(Port* velocityPort, double_T* velocity);/**< A Pointer to the setter function of the port: velocity */
								DriveControlDriveControlComponentStateChart* DriveControlComponent_getStateMachine(DriveControlComponent* component);
						
						/**
								 * @brief Get the Port: driveControl of an Instance of the Component: DriveControl
								 * @details The Pointer DriveControlComponent::driveControlPort is returned
								 * 
								 * @param component The specific Instance DriveControlComponent  of the Component: DriveControl whose Port shall be returned
								 * @return A Pointer to the Port driveControl of the struct DriveControlComponent
								 */
								Port* DriveControlComponent_getdriveControl(DriveControlComponent* component);
					
						
		

	
	
			/*****
 			 *
 			 *  RealtimeStatechart Functions
 			 *
 			 */
			/**
			 * @file 
			 * @author generated by Fraunhofer IEM
			 * @brief Specification of Realtime-StateChart: DriveControlDriveControlComponent
			 * @details This files contains the description of the Realtime-StateChart: DriveControlDriveControlComponent and its behavior which is executed
			 */
			
			//ENUM
				/** 
				 * @brief This enum represents the States of the Realtime-StateChart: DriveControlDriveControlComponent
				 */
					typedef enum {
						DRIVECONTROLDRIVECONTROLCOMPONENT_INACTIVE,
						STATE_DRIVECONTROLDRIVECONTROL_MAIN /**< Represents the State: STATE_DRIVECONTROLDRIVECONTROL_MAIN of the Realtime-StateChart: DriveControlDriveControlComponent */
						,
								STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING /**< Represents the State: STATE_DRIVECONTROLDRIVECONTROLAUTONOMOUSDRIVING of the Realtime-StateChart: DriveControlDriveControlDriveControlPort */
						,		STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION /**< Represents the State: STATE_DRIVECONTROLDRIVECONTROLWAITFORPERMISSION of the Realtime-StateChart: DriveControlDriveControlDriveControlPort */
						,		STATE_DRIVECONTROLDRIVECONTROLOVERTAKING /**< Represents the State: STATE_DRIVECONTROLDRIVECONTROLOVERTAKING of the Realtime-StateChart: DriveControlDriveControlDriveControlPort */
						,		STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE /**< Represents the State: STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGFOLLOWMAINLANE of the Realtime-StateChart: DriveControlDriveControl_mainDriving */
						,		STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE /**< Represents the State: STATE_DRIVECONTROLDRIVECONTROL_MAINDRIVINGPASSSLOWERVEHICLE of the Realtime-StateChart: DriveControlDriveControl_mainDriving */	
					}DriveControlDriveControlComponentState;
				
				
					/**
					 * 
					 * @brief Description of the Realtime-StateChart: DriveControlDriveControlComponent
					 * @details This struct represents the  Realtime-StateChart: DriveControlDriveControlComponent and its States
					 */
				struct DriveControlDriveControlComponentStateChart {	
						DriveControlComponent * parentComponent;/**< A pointer to the parent ComponentInstance of Type: DriveControlComponent , which has this Realtime-StateChart as its behavior */			
				
				
									DriveControlDriveControlComponentState currentStateOfDriveControlDriveControlComponent;/**< The current State of the Realtime-StateChart: DriveControlDriveControlComponent */
				
							DriveControlDriveControlComponentState currentStateOfDriveControlDriveControlDriveControlPort;/**< Represents the state of region: DriveControlDriveControlDriveControlPort */
							DriveControlDriveControlComponentState currentStateOfDriveControlDriveControl_mainDriving;/**< Represents the state of region: DriveControlDriveControl_mainDriving */
				
						bool_t DriveControlDriveControlComponent_isExecutable;/**< Execution Verifier of RTSC: DriveControlDriveControlComponent. This variable is used to ensure that a RTSC is executed only once per execution cycle */
							bool_t DriveControlDriveControlDriveControlPort_isExecutable;/**< Execution Verifier of RTSC: DriveControlDriveControlDriveControlPort. This variable is used to ensure that a RTSC is executed only once per execution cycle */
							bool_t DriveControlDriveControl_mainDriving_isExecutable;/**< Execution Verifier of RTSC: DriveControlDriveControl_mainDriving. This variable is used to ensure that a RTSC is executed only once per execution cycle */
					
				
				
					
				
							int32_T distanceLimit; /**< The Realtime-StateChart Variable: distanceLimit of Type: int32; */
							int32_T desiredVelocity; /**< The Realtime-StateChart Variable: desiredVelocity of Type: int32; */
							double_T slowVelocity; /**< The Realtime-StateChart Variable: slowVelocity of Type: double; */
				
								double_T distance;
								double_T velocity;
				
				
						
				
					} ;
			
			//METHOD STUBS
				/**
				 * @brief Creates an Instance of the Realtime-StateChart: DriveControlDriveControlComponent
				 * @details Allocates Memory for the struct DriveControlDriveControlComponentStateChart
				 * 
				 * @param parentComponent An Instance of the Component: DriveControlComponent which behavior is described via this Realtime-StateChart
				 * @return A Pointer to the new created DriveControlDriveControlComponentStateChart
				 */
					DriveControlDriveControlComponentStateChart* DriveControlDriveControlComponentStateChart_create(DriveControlComponent* parentComponent);
				/**
				 * @brief Initializes an Instance of the Realtime-StateChart: DriveControlDriveControlComponent
				 * @details All struct members of the struct DriveControlDriveControlComponentStateChart are initialized,
				 *			and all Regions of the Realtime-StateChart are initialized, too.
				 * 
				 * @param rtsc The specific DriveControlDriveControlComponentStateChart to be initialized
				 */
					void DriveControlDriveControlComponentStateChart_initialize(DriveControlDriveControlComponentStateChart* rtsc);
				/**
				 * @brief Initializes the Region: DriveControlDriveControlDriveControlPort of the Realtime-StateChart: DriveControlDriveControlComponent
				 * @details The Member DriveControlDriveControlComponentStateChart::currentStateOfDriveControlDriveControlDriveControlPort is initialized
				 * 
				 * @param stateChart The specific DriveControlDriveControlComponentStateChart whose Region shall be initialized
				 */
				
					void initializeDriveControlDriveControlDriveControlPortRegion(DriveControlDriveControlComponentStateChart* stateChart);
				/**
				 * @brief Initializes the Region: DriveControlDriveControl_mainDriving of the Realtime-StateChart: DriveControlDriveControlComponent
				 * @details The Member DriveControlDriveControlComponentStateChart::currentStateOfDriveControlDriveControl_mainDriving is initialized
				 * 
				 * @param stateChart The specific DriveControlDriveControlComponentStateChart whose Region shall be initialized
				 */
				
					void initializeDriveControlDriveControl_mainDrivingRegion(DriveControlDriveControlComponentStateChart* stateChart);
				/**
				 * @brief Destroys the Realtime-StateChart: DriveControlDriveControlComponent
				 * @details Frees the Memory for the struct DriveControlDriveControlComponentStateChart
				 * 
				 * @param rtsc The specific DriveControlDriveControlComponentStateChart to be destroyed
				 */	
					void DriveControlDriveControlComponentStateChart_destroy(DriveControlDriveControlComponentStateChart* rtsc);		
				/**
				 * @brief Executes the next Step of the Realtime-StateChart: DriveControlDriveControlComponent
				 * 
				 * @param rtsc The specific DriveControlDriveControlComponentStateChart to be executed
				 */	
					void DriveControlDriveControlComponentStateChart_processStep(DriveControlDriveControlComponentStateChart* rtsc);
			
				/**
				 * @brief Leaves the Region: driving of the Realtime-StateChart: DriveControlDriveControlComponent
				 * @details This method is called, whenever a the Region: driving is left.
				 * 			The correct State is set and all Exit-Events are executed.
				 *
				 * @param rtsc The specific DriveControlDriveControlComponentStateChart whose Region: driving shall be exit
				 */
					void DriveControlDriveControl_mainDrivingStateChart_exit(DriveControlDriveControlComponentStateChart* rtsc);
				/**
				 * @brief Leaves the Region: driveControlPort of the Realtime-StateChart: DriveControlDriveControlComponent
				 * @details This method is called, whenever a the Region: driveControlPort is left.
				 * 			The correct State is set and all Exit-Events are executed.
				 *
				 * @param rtsc The specific DriveControlDriveControlComponentStateChart whose Region: driveControlPort shall be exit
				 */
					void DriveControlDriveControlDriveControlPortStateChart_exit(DriveControlDriveControlComponentStateChart* rtsc);
						
				/**
				 * @brief Returns wether the Realtime-StateChart: DriveControlDriveControlComponent is in a specific State
				 * 
				 * @param rtsc The specific Realtime-StateChart: DriveControlDriveControlComponentStateChart
				 * @param state One of the States of the Enum: DriveControlDriveControlComponentState
				 * 
				 * @return True, If the Realtime-StateChart is in the specific State, otherwise False
				 */	
					bool_t DriveControlDriveControlComponentStateChart_isInState(DriveControlDriveControlComponentStateChart* rtsc, DriveControlDriveControlComponentState state);





#ifdef __cplusplus
  }
#endif
		#endif /* DRIVECONTROLCOMPONENT_Interface_H_ */
