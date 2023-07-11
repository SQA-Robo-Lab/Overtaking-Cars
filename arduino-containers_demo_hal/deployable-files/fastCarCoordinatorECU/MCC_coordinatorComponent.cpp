// Container HeaderFile
#include "MCC_coordinatorComponent.h"

/**
*  
* @brief The options a port declares
* @details These options are used in the struct coordinatorComponent_Builder
*/ 
struct port_option {
	union {
		struct{
		uint16_T pubID;
		uint16_T subID;
		} local_option;
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
* @brief The builder struct for the Component Type: Coordinator
* @details This is a realization of the builder pattern, the struct represents a Concrete Builder
*/ 
typedef struct coordinatorComponent_Builder {
		uint8_T ID;
		//create Builder Functions for each Port
			PortStatus COMMUNICATOR; /**< The status of port communicator */
			PortHandle* (*createCOMMUNICATORHandle)(struct coordinatorComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port communicator */
			struct port_option COMMUNICATOR_op; /**< The port_option for the PortHandle of port communicator */
			PortStatus OVERTAKINGINITIATOR; /**< The status of port overtakingInitiator */
			PortHandle* (*createOVERTAKINGINITIATORHandle)(struct coordinatorComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port overtakingInitiator */
			struct port_option OVERTAKINGINITIATOR_op; /**< The port_option for the PortHandle of port overtakingInitiator */
			PortStatus OVERTAKINGAFFILIATE; /**< The status of port overtakingAffiliate */
			PortHandle* (*createOVERTAKINGAFFILIATEHandle)(struct coordinatorComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port overtakingAffiliate */
			struct port_option OVERTAKINGAFFILIATE_op; /**< The port_option for the PortHandle of port overtakingAffiliate */
}coordinatorComponent_Builder;

/**
*
*@brief A initializer for the struct coordinatorComponent_Builder
*@details Shall be used when creating a struct coordinatorComponent_Builder manually
*/
static const coordinatorComponent_Builder INIT_BUILDER = { 
	0, 
	PORT_DEACTIVATED, 
	NULL, 
	{0,0}
,	PORT_DEACTIVATED, 
	NULL, 
	{0,0}
,	PORT_DEACTIVATED, 
	NULL, 
	{0,0}
};

/**
*
*@brief The pool of component instance of Component Type Coordinator
*@details The container manages the resource instances in this pool, and this pool allocates the memory for component instances statically
*/
	static CoordinatorComponent instancePool [1];
	static int pool_length = 0;
	static int pool_index = 0;

/**
*
*@brief The Check method for DiscretePort communicator  and message OvertakingPermissionMessagesRequestPermission 
*@details Checks if  buffer contains a message of type OvertakingPermissionMessagesRequestPermission
*
*/	
bool_t MCC_CoordinatorComponent_communicator_exists_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(Port* port){
	I2cHandle* i2cHandle;
	int i = 0;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_I2C:
			i2cHandle = (I2cHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < i2cHandle->numOfReceivers; i++) {
				if (strcmp(i2cHandle->receivers[i].messageTypeName, "OvertakingPermissionMessagesRequestPermission") == 0){
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
*@brief The receive method for DiscretePort communicator and message OvertakingPermissionMessagesRequestPermission
*@details Receives  a message of type OvertakingPermissionMessagesRequestPermission
*
*/
bool_t MCC_CoordinatorComponent_communicator_recv_OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message* msg){
	I2cHandle* i2cHandle;
	int i = 0;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_I2C:
			i2cHandle = (I2cHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < i2cHandle->numOfReceivers; i++) {
				if (strcmp(i2cHandle->receivers[i].messageTypeName, "OvertakingPermissionMessagesRequestPermission") == 0){
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
*@brief The Check method for DiscretePort communicator  and message OvertakingPermissionMessagesExecutedOvertaking 
*@details Checks if  buffer contains a message of type OvertakingPermissionMessagesExecutedOvertaking
*
*/	
bool_t MCC_CoordinatorComponent_communicator_exists_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(Port* port){
	I2cHandle* i2cHandle;
	int i = 0;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_I2C:
			i2cHandle = (I2cHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < i2cHandle->numOfReceivers; i++) {
				if (strcmp(i2cHandle->receivers[i].messageTypeName, "OvertakingPermissionMessagesExecutedOvertaking") == 0){
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
*@brief The receive method for DiscretePort communicator and message OvertakingPermissionMessagesExecutedOvertaking
*@details Receives  a message of type OvertakingPermissionMessagesExecutedOvertaking
*
*/
bool_t MCC_CoordinatorComponent_communicator_recv_OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message* msg){
	I2cHandle* i2cHandle;
	int i = 0;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_I2C:
			i2cHandle = (I2cHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < i2cHandle->numOfReceivers; i++) {
				if (strcmp(i2cHandle->receivers[i].messageTypeName, "OvertakingPermissionMessagesExecutedOvertaking") == 0){
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
*@brief The send method for DiscretePort communicator and message OvertakingPermissionMessagesGrantPermission
*@details Send a message of type OvertakingPermissionMessagesGrantPermission  
*
*/	
void MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message* msg){
	I2cHandle* i2cHandle;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_I2C:
			i2cHandle = (I2cHandle*) port->handle->concreteHandle;
			sendI2cMessage(i2cHandle->otherI2cAddress, "OvertakingPermissionMessagesGrantPermission", (byte *) msg, sizeof(OvertakingPermissionMessagesGrantPermission_OvertakingPermissionMessages_Message)); 
			break;
	default:
		break;	
	}
}
/**
*
*@brief The send method for DiscretePort communicator and message OvertakingPermissionMessagesDenyPermission
*@details Send a message of type OvertakingPermissionMessagesDenyPermission  
*
*/	
void MCC_CoordinatorComponent_communicator_send_OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message(Port* port, OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message* msg){
	I2cHandle* i2cHandle;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_I2C:
			i2cHandle = (I2cHandle*) port->handle->concreteHandle;
			sendI2cMessage(i2cHandle->otherI2cAddress, "OvertakingPermissionMessagesDenyPermission", (byte *) msg, sizeof(OvertakingPermissionMessagesDenyPermission_OvertakingPermissionMessages_Message)); 
			break;
	default:
		break;	
	}
}
/**
*
*@brief The Check method for DiscretePort overtakingInitiator  and message OvertakingCoordinationMessagesAcceptOvertaking 
*@details Checks if  buffer contains a message of type OvertakingCoordinationMessagesAcceptOvertaking
*
*/	
bool_t MCC_CoordinatorComponent_overtakingInitiator_exists_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(Port* port){
	MqttHandle* mqttHandle;
	int i;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < mqttHandle->numOfSubs; i++){
				if (strcmp(mqttHandle->subscribers[i].messageTypeName, "OvertakingCoordinationMessagesAcceptOvertaking") == 0){
					buffer = mqttHandle->subscribers[i].buffer;
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
*@brief The receive method for DiscretePort overtakingInitiator and message OvertakingCoordinationMessagesAcceptOvertaking
*@details Receives  a message of type OvertakingCoordinationMessagesAcceptOvertaking
*
*/
bool_t MCC_CoordinatorComponent_overtakingInitiator_recv_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(Port* port, OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message* msg){
	MqttHandle* mqttHandle;
	int i;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < mqttHandle->numOfSubs; i++){
				if (strcmp(mqttHandle->subscribers[i].messageTypeName, "OvertakingCoordinationMessagesAcceptOvertaking") == 0){
					buffer = mqttHandle->subscribers[i].buffer;
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
*@brief The send method for DiscretePort overtakingInitiator and message OvertakingCoordinationMessagesRequestOvertaking
*@details Send a message of type OvertakingCoordinationMessagesRequestOvertaking  
*
*/	
void MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message(Port* port, OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message* msg){
	MqttHandle* mqttHandle;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			sendMqttMessage(mqttHandle->publishingTopic, "OvertakingCoordinationMessagesRequestOvertaking", (byte*) msg, sizeof(OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message)); 
			break;
	default:
		break;	
	}
}
/**
*
*@brief The send method for DiscretePort overtakingInitiator and message OvertakingCoordinationMessagesFinishedOvertaking
*@details Send a message of type OvertakingCoordinationMessagesFinishedOvertaking  
*
*/	
void MCC_CoordinatorComponent_overtakingInitiator_send_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(Port* port, OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message* msg){
	MqttHandle* mqttHandle;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			sendMqttMessage(mqttHandle->publishingTopic, "OvertakingCoordinationMessagesFinishedOvertaking", (byte*) msg, sizeof(OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message)); 
			break;
	default:
		break;	
	}
}
/**
*
*@brief The Check method for DiscretePort overtakingAffiliate  and message OvertakingCoordinationMessagesRequestOvertaking 
*@details Checks if  buffer contains a message of type OvertakingCoordinationMessagesRequestOvertaking
*
*/	
bool_t MCC_CoordinatorComponent_overtakingAffiliate_exists_OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message(Port* port){
	MqttHandle* mqttHandle;
	int i;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < mqttHandle->numOfSubs; i++){
				if (strcmp(mqttHandle->subscribers[i].messageTypeName, "OvertakingCoordinationMessagesRequestOvertaking") == 0){
					buffer = mqttHandle->subscribers[i].buffer;
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
*@brief The receive method for DiscretePort overtakingAffiliate and message OvertakingCoordinationMessagesRequestOvertaking
*@details Receives  a message of type OvertakingCoordinationMessagesRequestOvertaking
*
*/
bool_t MCC_CoordinatorComponent_overtakingAffiliate_recv_OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message(Port* port, OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message* msg){
	MqttHandle* mqttHandle;
	int i;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < mqttHandle->numOfSubs; i++){
				if (strcmp(mqttHandle->subscribers[i].messageTypeName, "OvertakingCoordinationMessagesRequestOvertaking") == 0){
					buffer = mqttHandle->subscribers[i].buffer;
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
*@brief The Check method for DiscretePort overtakingAffiliate  and message OvertakingCoordinationMessagesFinishedOvertaking 
*@details Checks if  buffer contains a message of type OvertakingCoordinationMessagesFinishedOvertaking
*
*/	
bool_t MCC_CoordinatorComponent_overtakingAffiliate_exists_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(Port* port){
	MqttHandle* mqttHandle;
	int i;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < mqttHandle->numOfSubs; i++){
				if (strcmp(mqttHandle->subscribers[i].messageTypeName, "OvertakingCoordinationMessagesFinishedOvertaking") == 0){
					buffer = mqttHandle->subscribers[i].buffer;
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
*@brief The receive method for DiscretePort overtakingAffiliate and message OvertakingCoordinationMessagesFinishedOvertaking
*@details Receives  a message of type OvertakingCoordinationMessagesFinishedOvertaking
*
*/
bool_t MCC_CoordinatorComponent_overtakingAffiliate_recv_OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message(Port* port, OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message* msg){
	MqttHandle* mqttHandle;
	int i;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			MessageBuffer* buffer = NULL;
			for (i = 0; i < mqttHandle->numOfSubs; i++){
				if (strcmp(mqttHandle->subscribers[i].messageTypeName, "OvertakingCoordinationMessagesFinishedOvertaking") == 0){
					buffer = mqttHandle->subscribers[i].buffer;
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
*@brief The send method for DiscretePort overtakingAffiliate and message OvertakingCoordinationMessagesAcceptOvertaking
*@details Send a message of type OvertakingCoordinationMessagesAcceptOvertaking  
*
*/	
void MCC_CoordinatorComponent_overtakingAffiliate_send_OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message(Port* port, OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message* msg){
	MqttHandle* mqttHandle;
	switch(port->handle->type) {
		case PORT_HANDLE_TYPE_MQTT:
			mqttHandle = (MqttHandle*) port->handle->concreteHandle;
			sendMqttMessage(mqttHandle->publishingTopic, "OvertakingCoordinationMessagesAcceptOvertaking", (byte*) msg, sizeof(OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message)); 
			break;
	default:
		break;	
	}
}
 

/**
*
*@brief The builder for component instance of Component Type Coordinator
*@details This method creates and initializes a component instance properly by using the struct coordinatorComponent_Builder
*/
	static CoordinatorComponent* MCC_CoordinatorComponent_Builder(coordinatorComponent_Builder* b){
		instancePool[pool_index].ID = b->ID;
		instancePool[pool_index].stateChart = CoordinatorCoordinatorComponentStateChart_create(
			&instancePool[pool_index]);
		//call init after RTSC was created
		CoordinatorComponent_initialize(&instancePool[pool_index]);
		//For each port initialize it
		if(b->COMMUNICATOR != PORT_DEACTIVATED) {
			instancePool[pool_index].communicatorPort.status = b->COMMUNICATOR;
			instancePool[pool_index].communicatorPort.handle = (PortHandle*) malloc(sizeof(PortHandle));
 			instancePool[pool_index].communicatorPort.handle->port = &(instancePool[pool_index].communicatorPort);
			b->createCOMMUNICATORHandle(b, (instancePool[pool_index].communicatorPort.handle));
			//instancePool[pool_index].communicatorPort.handle->port = &(instancePool[pool_index].communicatorPort);
		}
		if(b->OVERTAKINGINITIATOR != PORT_DEACTIVATED) {
			instancePool[pool_index].overtakingInitiatorPort.status = b->OVERTAKINGINITIATOR;
			instancePool[pool_index].overtakingInitiatorPort.handle = (PortHandle*) malloc(sizeof(PortHandle));
 			instancePool[pool_index].overtakingInitiatorPort.handle->port = &(instancePool[pool_index].overtakingInitiatorPort);
			b->createOVERTAKINGINITIATORHandle(b, (instancePool[pool_index].overtakingInitiatorPort.handle));
			//instancePool[pool_index].overtakingInitiatorPort.handle->port = &(instancePool[pool_index].overtakingInitiatorPort);
		}
		if(b->OVERTAKINGAFFILIATE != PORT_DEACTIVATED) {
			instancePool[pool_index].overtakingAffiliatePort.status = b->OVERTAKINGAFFILIATE;
			instancePool[pool_index].overtakingAffiliatePort.handle = (PortHandle*) malloc(sizeof(PortHandle));
 			instancePool[pool_index].overtakingAffiliatePort.handle->port = &(instancePool[pool_index].overtakingAffiliatePort);
			b->createOVERTAKINGAFFILIATEHandle(b, (instancePool[pool_index].overtakingAffiliatePort.handle));
			//instancePool[pool_index].overtakingAffiliatePort.handle->port = &(instancePool[pool_index].overtakingAffiliatePort);
		}
	
		return &instancePool[pool_index++];
	}

/**
 * @brief The Builder for an I2cHandle for port communicator
 *
 * @details creates a struct I2cHandle which encapsulates the logic for communication 
 */
static PortHandle* create_COMMUNICATORI2cHandle(coordinatorComponent_Builder* b, PortHandle *ptr){
	ptr->type = PORT_HANDLE_TYPE_I2C;
	//create the handle for the discrete port COMMUNICATOR with all its message types
	I2cHandle* handle = (I2cHandle*) malloc(sizeof(I2cHandle)+2*sizeof(I2cReceiver));
	handle->numOfReceivers = 2;
	//register a receiver for every message type of the port
	initAndRegisterI2cReceiver(&(handle->receivers[0]), 
								"OvertakingPermissionMessagesRequestPermission",
								5,
								sizeof(OvertakingPermissionMessagesRequestPermission_OvertakingPermissionMessages_Message),
								 false );
	initAndRegisterI2cReceiver(&(handle->receivers[1]), 
								"OvertakingPermissionMessagesExecutedOvertaking",
								5,
								sizeof(OvertakingPermissionMessagesExecutedOvertaking_OvertakingPermissionMessages_Message),
								 false );
	handle->ownI2cAddress = b->COMMUNICATOR_op.i2c_option.ownAddress;
	handle->otherI2cAddress = b->COMMUNICATOR_op.i2c_option.otherAddress;
	ptr->concreteHandle = handle;
	
	return ptr;
}
static PortHandle* create_OVERTAKINGINITIATORMqttHandle(coordinatorComponent_Builder* b, PortHandle *ptr){
	ptr->type = PORT_HANDLE_TYPE_MQTT;
	//create the handle for the discrete port OVERTAKINGINITIATOR with all its message types
	MqttHandle* handle = (MqttHandle*) malloc(sizeof(MqttHandle)+1*sizeof(MqttSubscriber));
	handle->numOfSubs = 1;
	//register a subscriber for every message type of the port
	initAndRegisterMqttSubscriber(&(handle->subscribers[0]),
									b->OVERTAKINGINITIATOR_op.mqtt_option.subscriptionTopic,
									"OvertakingCoordinationMessagesAcceptOvertaking",
									1,
									sizeof(OvertakingCoordinationMessagesAcceptOvertaking_OvertakingCoordinationMessages_Message),
									 false );	
	handle->publishingTopic = b->OVERTAKINGINITIATOR_op.mqtt_option.publishingTopic;
	handle->subscriptionTopic = b->OVERTAKINGINITIATOR_op.mqtt_option.subscriptionTopic;
	ptr->concreteHandle = handle;

	return ptr;
}
static PortHandle* create_OVERTAKINGAFFILIATEMqttHandle(coordinatorComponent_Builder* b, PortHandle *ptr){
	ptr->type = PORT_HANDLE_TYPE_MQTT;
	//create the handle for the discrete port OVERTAKINGAFFILIATE with all its message types
	MqttHandle* handle = (MqttHandle*) malloc(sizeof(MqttHandle)+2*sizeof(MqttSubscriber));
	handle->numOfSubs = 2;
	//register a subscriber for every message type of the port
	initAndRegisterMqttSubscriber(&(handle->subscribers[0]),
									b->OVERTAKINGAFFILIATE_op.mqtt_option.subscriptionTopic,
									"OvertakingCoordinationMessagesRequestOvertaking",
									5,
									sizeof(OvertakingCoordinationMessagesRequestOvertaking_OvertakingCoordinationMessages_Message),
									 false );	
	initAndRegisterMqttSubscriber(&(handle->subscribers[1]),
									b->OVERTAKINGAFFILIATE_op.mqtt_option.subscriptionTopic,
									"OvertakingCoordinationMessagesFinishedOvertaking",
									5,
									sizeof(OvertakingCoordinationMessagesFinishedOvertaking_OvertakingCoordinationMessages_Message),
									 false );	
	handle->publishingTopic = b->OVERTAKINGAFFILIATE_op.mqtt_option.publishingTopic;
	handle->subscriptionTopic = b->OVERTAKINGAFFILIATE_op.mqtt_option.subscriptionTopic;
	ptr->concreteHandle = handle;

	return ptr;
}


/**
 * @brief Create a component instance with the given id.
 * 
 * @details Creates a component instance using the builder and the configuration options, and also configures the port instances.
 * 
 * @param ID the identifier of the component instance
 */
CoordinatorComponent* MCC_create_CoordinatorComponent(uint8_T ID){
	struct coordinatorComponent_Builder b = INIT_BUILDER;
	switch(ID){
		case CI_COMMUNICATORFCOORDINATOR:
			b.ID = ID;
			b.OVERTAKINGINITIATOR = PORT_ACTIVE;
			b.createOVERTAKINGINITIATORHandle = &create_OVERTAKINGINITIATORMqttHandle;
			b.OVERTAKINGINITIATOR_op.mqtt_option.publishingTopic = "fastCarCoordinatorECU/communicator.F/overtakingInitiator1/";
			b.OVERTAKINGINITIATOR_op.mqtt_option.subscriptionTopic = "slowCarCoordinatorECU/communicator.S/overtakingAffiliate1/";
			b.COMMUNICATOR = PORT_ACTIVE;
			b.createCOMMUNICATORHandle = &create_COMMUNICATORI2cHandle;
			b.COMMUNICATOR_op.i2c_option.ownAddress = 1;
			b.COMMUNICATOR_op.i2c_option.otherAddress = 9;
			b.OVERTAKINGAFFILIATE = PORT_ACTIVE;
			b.createOVERTAKINGAFFILIATEHandle = &create_OVERTAKINGAFFILIATEMqttHandle;
			b.OVERTAKINGAFFILIATE_op.mqtt_option.publishingTopic = "fastCarCoordinatorECU/communicator.F/overtakingAffiliate1/";
			b.OVERTAKINGAFFILIATE_op.mqtt_option.subscriptionTopic = "slowCarCoordinatorECU/communicator.S/overtakingInitiator1/";
		break;
	default:
		break;
	}
	return MCC_CoordinatorComponent_Builder(&b);
}
	
