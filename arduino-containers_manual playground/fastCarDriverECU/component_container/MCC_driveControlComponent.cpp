		// Container HeaderFile
		#include "MCC_driveControlComponent.h"
		
		/**
		*  
		* @brief The options a port declares
		* @details These options are used in the struct driveControlComponent_Builder
		*/ 
		struct port_option {
			union {
				struct{
				uint16_T pubID;
				uint16_T subID;
				} local_option;
				struct {
					int domainID;
					int partition;
				} dds_option;
				struct {
					uint8_T ownAddress;
					uint8_T otherAddress;
				} i2c_option;
				struct {
					char* publishingTopic;
					char* subscriptionTopic;
				} mqtt_option;
			};
		};
		
		/**
		*  
		* @brief The builder struct for the Component Type: DriveControl
		* @details This is a realization of the builder pattern, the struct represents a Concrete Builder
		*/ 
		typedef struct driveControlComponent_Builder {
				uint8_T ID;
				//create Builder Functions for each Port
					PortStatus FRONTDISTANCE; /**< The status of port frontDistance */
					PortHandle* (*createFRONTDISTANCEHandle)(struct driveControlComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port frontDistance */
					struct port_option FRONTDISTANCE_op; /**< The port_option for the PortHandle of port frontDistance */
					PortStatus REARDISTANCE; /**< The status of port rearDistance */
					PortHandle* (*createREARDISTANCEHandle)(struct driveControlComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port rearDistance */
					struct port_option REARDISTANCE_op; /**< The port_option for the PortHandle of port rearDistance */
					PortStatus DRIVECONTROL; /**< The status of port driveControl */
					PortHandle* (*createDRIVECONTROLHandle)(struct driveControlComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port driveControl */
					struct port_option DRIVECONTROL_op; /**< The port_option for the PortHandle of port driveControl */
					PortStatus VELOCITY; /**< The status of port velocity */
					PortHandle* (*createVELOCITYHandle)(struct driveControlComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port velocity */
					struct port_option VELOCITY_op; /**< The port_option for the PortHandle of port velocity */
		}driveControlComponent_Builder;
		
		/**
		*
		*@brief A initializer for the struct driveControlComponent_Builder
		*@details Shall be used when creating a struct driveControlComponent_Builder manually
		*/
		static const driveControlComponent_Builder INIT_BUILDER = { 0,  PORT_DEACTIVATED, NULL, .FRONTDISTANCE_op.local_option={0,0}  , PORT_DEACTIVATED, NULL, .REARDISTANCE_op.local_option={0,0}  , PORT_DEACTIVATED, NULL, .DRIVECONTROL_op.local_option={0,0}  , PORT_DEACTIVATED, NULL, .VELOCITY_op.local_option={0,0}   };
		/**
		*
		*@brief The pool of component instance of Component Type DriveControl
		*@details The container manages the resource instances in this pool, and this pool allocates the memory for component instances statically
		*/
			static DriveControlComponent instancePool [1];
			static int pool_length = 0;
			static int pool_index = 0;

							/**
							*
							*@brief method to test if message exists for DirectedTypedPort frontDistance 
							*@details looksup if the  buffer contains a messages
							*
							*/
							bool_t MCC_DriveControlComponent_frontDistance_exists_value(Port* port){
										LocalHandle* localHandle;
										int i = 0;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_LOCAL:
										localHandle = (LocalHandle*) port->handle->concreteHandle;
										MessageBuffer* buf = NULL;
										//dont handle a pointer over the the buffer, because msg is already a pointer
										for (i = 0; i < localHandle->numOfSubs; i++) {
											if (localHandle->localSubscribers[i].msgID == 0) {
												buf = localHandle->localSubscribers[i].buffer;
												break;
											}
										}
										return MessageBuffer_doesMessageExists(buf);
										break;
								default:
									break;	
								}
								return false;
							}
							/**
							*
							*@brief The receive method for DirectedTypedPort frontDistance 
							*
							*/	
							bool_t MCC_DriveControlComponent_frontDistance_recv_value(Port* port, int32_T* msg){
										LocalHandle* localHandle;
										int i = 0;
								switch(port->handle->type) {
										case PORT_HANDLE_TYPE_LOCAL:
											localHandle = (LocalHandle*) port->handle->concreteHandle;
											//dont handle a pointer over the the buffer, because msg is already a pointer
											publishMessage(localHandle->pubID, 0, msg);
											break;
								default:
									break;
								}
								return false;
							}	
					
							/**
							*
							*@brief method to test if message exists for DirectedTypedPort rearDistance 
							*@details looksup if the  buffer contains a messages
							*
							*/
							bool_t MCC_DriveControlComponent_rearDistance_exists_value(Port* port){
										LocalHandle* localHandle;
										int i = 0;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_LOCAL:
										localHandle = (LocalHandle*) port->handle->concreteHandle;
										MessageBuffer* buf = NULL;
										//dont handle a pointer over the the buffer, because msg is already a pointer
										for (i = 0; i < localHandle->numOfSubs; i++) {
											if (localHandle->localSubscribers[i].msgID == 0) {
												buf = localHandle->localSubscribers[i].buffer;
												break;
											}
										}
										return MessageBuffer_doesMessageExists(buf);
										break;
								default:
									break;	
								}
								return false;
							}
							/**
							*
							*@brief The receive method for DirectedTypedPort rearDistance 
							*
							*/	
							bool_t MCC_DriveControlComponent_rearDistance_recv_value(Port* port, int32_T* msg){
										LocalHandle* localHandle;
										int i = 0;
								switch(port->handle->type) {
										case PORT_HANDLE_TYPE_LOCAL:
											localHandle = (LocalHandle*) port->handle->concreteHandle;
											//dont handle a pointer over the the buffer, because msg is already a pointer
											publishMessage(localHandle->pubID, 0, msg);
											break;
								default:
									break;
								}
								return false;
							}	
					
							/**
							*
							*@brief The Check method for DiscretePort driveControl  and message OvertakingPermissionMessagesGrantPermission 
							*@details Checks if  buffer contains a message of type OvertakingPermissionMessagesGrantPermission
							*
							*/	
							bool_t MCC_DriveControlComponent_driveControl_exists_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(Port* port){
								I2cHandle* i2cHandle;
								int i = 0;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_I2C:
										i2cHandle = (I2cHandle*) port->handle->concreteHandle;
										MessageBuffer* buffer = NULL;
										for (i = 0; i < i2cHandle->numOfReceivers; i++) {
											if (i2cHandle->receivers[i].messageId == MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE){
												buffer = i2cHandle->receivers[i].buffer;
												break;
											}
										}
										return MessageBuffer_doesMessageExists(buffer);
										break;
								default:
									break;	
								}
								return false;
							}
							/**
							*
							*@brief The receive method for DiscretePort driveControl and message OvertakingPermissionMessagesGrantPermission
							*@details Receives  a message of type OvertakingPermissionMessagesGrantPermission
							*
							*/
							bool_t MCC_DriveControlComponent_driveControl_recv_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message* msg){
								I2cHandle* i2cHandle;
								int i = 0;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_I2C:
										i2cHandle = (I2cHandle*) port->handle->concreteHandle;
										MessageBuffer* buffer = NULL;
										for (i = 0; i < i2cHandle->numOfReceivers; i++) {
											if (i2cHandle->receivers[i].messageId == MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE){
												buffer = i2cHandle->receivers[i].buffer;
												break;
											}
										}
										return MessageBuffer_dequeue(buffer, msg); 
										break;
								default:
									break;	
								}
								return false;
							}
							/**
							*
							*@brief The Check method for DiscretePort driveControl  and message OvertakingPermissionMessagesDenyPermission 
							*@details Checks if  buffer contains a message of type OvertakingPermissionMessagesDenyPermission
							*
							*/	
							bool_t MCC_DriveControlComponent_driveControl_exists_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(Port* port){
								I2cHandle* i2cHandle;
								int i = 0;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_I2C:
										i2cHandle = (I2cHandle*) port->handle->concreteHandle;
										MessageBuffer* buffer = NULL;
										for (i = 0; i < i2cHandle->numOfReceivers; i++) {
											if (i2cHandle->receivers[i].messageId == MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE){
												buffer = i2cHandle->receivers[i].buffer;
												break;
											}
										}
										return MessageBuffer_doesMessageExists(buffer);
										break;
								default:
									break;	
								}
								return false;
							}
							/**
							*
							*@brief The receive method for DiscretePort driveControl and message OvertakingPermissionMessagesDenyPermission
							*@details Receives  a message of type OvertakingPermissionMessagesDenyPermission
							*
							*/
							bool_t MCC_DriveControlComponent_driveControl_recv_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message* msg){
								I2cHandle* i2cHandle;
								int i = 0;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_I2C:
										i2cHandle = (I2cHandle*) port->handle->concreteHandle;
										MessageBuffer* buffer = NULL;
										for (i = 0; i < i2cHandle->numOfReceivers; i++) {
											if (i2cHandle->receivers[i].messageId == MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE){
												buffer = i2cHandle->receivers[i].buffer;
												break;
											}
										}
										return MessageBuffer_dequeue(buffer, msg); 
										break;
								default:
									break;	
								}
								return false;
							}
							/**
							*
							*@brief The send method for DiscretePort driveControl and message OvertakingPermissionMessagesRequestPermission
							*@details Send a message of type OvertakingPermissionMessagesRequestPermission  
							*
							*/	
							void MCC_DriveControlComponent_driveControl_send_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message* msg){
								I2cHandle* i2cHandle;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_I2C:
										i2cHandle = (I2cHandle*) port->handle->concreteHandle;
										sendI2cMessage(i2cHandle->otherI2cAddress, MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE, msg);
										break;
								default:
									break;	
								}
							}
							/**
							*
							*@brief The send method for DiscretePort driveControl and message OvertakingPermissionMessagesExecutedOvertaking
							*@details Send a message of type OvertakingPermissionMessagesExecutedOvertaking  
							*
							*/	
							void MCC_DriveControlComponent_driveControl_send_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message* msg){
								I2cHandle* i2cHandle;
								switch(port->handle->type) {
									case PORT_HANDLE_TYPE_I2C:
										i2cHandle = (I2cHandle*) port->handle->concreteHandle;
										sendI2cMessage(i2cHandle->otherI2cAddress, MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE, msg);
										break;
								default:
									break;	
								}
							}
							/**
							*
							*@brief The send method for DirectedTypedPort velocity 
							*
							*/	
							void MCC_DriveControlComponent_velocity_send_value(Port* port, int32_T* msg){
										LocalHandle* localHandle;
								switch(port->handle->type) {
										case PORT_HANDLE_TYPE_LOCAL:
											localHandle = (LocalHandle*) port->handle->concreteHandle;
											//dont handle a pointer over the the buffer, because msg is already a pointer
											publishMessage(localHandle->pubID, 0, msg);
											break;
								default:
									break;	
								}
							}
					
		 
		
		/**
		*
		*@brief The builder for component instance of Component Type DriveControl
		*@details This method creates and initializes a component instance properly by using the struct driveControlComponent_Builder
		*/
			static DriveControlComponent* MCC_DriveControlComponent_Builder(driveControlComponent_Builder* b){
				instancePool[pool_index].ID = b->ID;
				instancePool[pool_index].stateChart = DriveControlDriveControlComponentStateChart_create(
					&instancePool[pool_index]);
				//call init after RTSC was created
				DriveControlComponent_initialize(&instancePool[pool_index]);
				//For each port initialize it
					if(b->FRONTDISTANCE != PORT_DEACTIVATED) {
					instancePool[pool_index].frontDistancePort.status = b->FRONTDISTANCE;
					instancePool[pool_index].frontDistancePort.handle = (PortHandle*) malloc(sizeof(PortHandle));
		 			instancePool[pool_index].frontDistancePort.handle->port = &(instancePool[pool_index].frontDistancePort);
					b->createFRONTDISTANCEHandle(b, (instancePool[pool_index].frontDistancePort.handle));
					//instancePool[pool_index].frontDistancePort.handle->port = &(instancePool[pool_index].frontDistancePort);
				}
					if(b->REARDISTANCE != PORT_DEACTIVATED) {
					instancePool[pool_index].rearDistancePort.status = b->REARDISTANCE;
					instancePool[pool_index].rearDistancePort.handle = (PortHandle*) malloc(sizeof(PortHandle));
		 			instancePool[pool_index].rearDistancePort.handle->port = &(instancePool[pool_index].rearDistancePort);
					b->createREARDISTANCEHandle(b, (instancePool[pool_index].rearDistancePort.handle));
					//instancePool[pool_index].rearDistancePort.handle->port = &(instancePool[pool_index].rearDistancePort);
				}
					if(b->DRIVECONTROL != PORT_DEACTIVATED) {
					instancePool[pool_index].driveControlPort.status = b->DRIVECONTROL;
					instancePool[pool_index].driveControlPort.handle = (PortHandle*) malloc(sizeof(PortHandle));
		 			instancePool[pool_index].driveControlPort.handle->port = &(instancePool[pool_index].driveControlPort);
					b->createDRIVECONTROLHandle(b, (instancePool[pool_index].driveControlPort.handle));
					//instancePool[pool_index].driveControlPort.handle->port = &(instancePool[pool_index].driveControlPort);
				}
					if(b->VELOCITY != PORT_DEACTIVATED) {
					instancePool[pool_index].velocityPort.status = b->VELOCITY;
					instancePool[pool_index].velocityPort.handle = (PortHandle*) malloc(sizeof(PortHandle));
		 			instancePool[pool_index].velocityPort.handle->port = &(instancePool[pool_index].velocityPort);
					b->createVELOCITYHandle(b, (instancePool[pool_index].velocityPort.handle));
					//instancePool[pool_index].velocityPort.handle->port = &(instancePool[pool_index].velocityPort);
				}
			
				return &instancePool[pool_index++];
			}
		
		static PortHandle* create_FRONTDISTANCELocalHandle(driveControlComponent_Builder* b, PortHandle *ptr){
			ptr->type = PORT_HANDLE_TYPE_LOCAL;
			LocalHandle* hndl = malloc(sizeof(LocalHandle)+1*sizeof(LocalSubscriber));
			ptr->concreteHandle = hndl;
			hndl->pubID = b->FRONTDISTANCE_op.local_option.pubID;
			hndl->subID = b->FRONTDISTANCE_op.local_option.subID;
			//create space for Subscriber
			hndl->numOfSubs = 1;
			subscribeToMessage(&(hndl->localSubscribers[0] ),hndl->subID, 0, 1, sizeof(int32_T), true);
			return ptr;
		}
		static PortHandle* create_REARDISTANCELocalHandle(driveControlComponent_Builder* b, PortHandle *ptr){
			ptr->type = PORT_HANDLE_TYPE_LOCAL;
			LocalHandle* hndl = malloc(sizeof(LocalHandle)+1*sizeof(LocalSubscriber));
			ptr->concreteHandle = hndl;
			hndl->pubID = b->REARDISTANCE_op.local_option.pubID;
			hndl->subID = b->REARDISTANCE_op.local_option.subID;
			//create space for Subscriber
			hndl->numOfSubs = 1;
			subscribeToMessage(&(hndl->localSubscribers[0] ),hndl->subID, 0, 1, sizeof(int32_T), true);
			return ptr;
		}
		/**
		 * @brief The Builder for an I2cHandle for port driveControl
		 *
		 * @details creates a struct I2cHandle which encapsulates the logic for communication 
		 */
		static PortHandle* create_DRIVECONTROLI2cHandle(driveControlComponent_Builder* b, PortHandle *ptr){
			ptr->type = PORT_HANDLE_TYPE_I2C;
			//create the handle for the discrete port DRIVECONTROL with all its message types
			I2cHandle* handle = (I2cHandle*) malloc(sizeof(I2cHandle)+2*sizeof(I2cReceiver));
			handle->numOfReceivers = 2;
			//register a receiver for every message type of the port
			createAndRegisterI2cReceiver(&(handle->receivers[0]), 
										MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,
										5,
										sizeof(OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message),
										 false );
			createAndRegisterI2cReceiver(&(handle->receivers[0]), 
										MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE,
										5,
										sizeof(OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message),
										 false );
			handle->ownI2cAddress = b->DRIVECONTROL_op.i2c_option.ownAddress;
			handle->otherI2cAddress = b->DRIVECONTROL_op.i2c_option.otherAddress;
			ptr->concreteHandle = handle;
			
			return ptr;
		}
		static PortHandle* create_VELOCITYLocalHandle(driveControlComponent_Builder* b, PortHandle *ptr){
			ptr->type = PORT_HANDLE_TYPE_LOCAL;
			LocalHandle* hndl = malloc(sizeof(LocalHandle)+0*sizeof(LocalSubscriber));
			ptr->concreteHandle = hndl;
			hndl->pubID = b->VELOCITY_op.local_option.pubID;
			hndl->subID = b->VELOCITY_op.local_option.subID;
			return ptr;
		}
		
		
		/**
		 * @brief Create a component instance with the given id.
		 * 
		 * @details Creates a component instance using the builder and the configuration options, and also configures the port instances.
		 * 
		 * @param ID the identifier of the component instance
		 */
		DriveControlComponent* MCC_create_DriveControlComponent(uint8_T ID){
			struct driveControlComponent_Builder b = INIT_BUILDER;
			switch(ID){
				case CI_DRIVECONTROLFDRIVECONTROL:
					b.ID = ID;
							b.FRONTDISTANCE = PORT_ACTIVE;
							b.createFRONTDISTANCEHandle = &create_FRONTDISTANCELocalHandle;
							b.FRONTDISTANCE_op.local_option.pubID = -12409;
							b.FRONTDISTANCE_op.local_option.subID = -25176;
							b.VELOCITY = PORT_ACTIVE;
							b.createVELOCITYHandle = &create_VELOCITYLocalHandle;
							b.VELOCITY_op.local_option.pubID = -25132;
							b.VELOCITY_op.local_option.subID = -26371;
							b.REARDISTANCE = PORT_ACTIVE;
							b.createREARDISTANCEHandle = &create_REARDISTANCELocalHandle;
							b.REARDISTANCE_op.local_option.pubID = 2631;
							b.REARDISTANCE_op.local_option.subID = -9629;
							b.DRIVECONTROL = PORT_ACTIVE;
							b.createDRIVECONTROLHandle = &create_DRIVECONTROLI2cHandle;
							b.DRIVECONTROL_op.i2c_option.ownAddress = 9;
							b.DRIVECONTROL_op.i2c_option.otherAddress = 1;
				break;
			default:
				break;
			}
			return MCC_DriveControlComponent_Builder(&b);
		}
		
