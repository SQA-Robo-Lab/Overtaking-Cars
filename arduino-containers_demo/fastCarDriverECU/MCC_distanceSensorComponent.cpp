// Container HeaderFile
#include "MCC_distanceSensorComponent.h"

/**
*  
* @brief The options a port declares
* @details These options are used in the struct distanceSensorComponent_Builder
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
* @brief The builder struct for the Component Type: DistanceSensor
* @details This is a realization of the builder pattern, the struct represents a Concrete Builder
*/ 
typedef struct distanceSensorComponent_Builder {
		uint8_T ID;
		//create Builder Functions for each Port
			PortStatus DISTANCE; /**< The status of port distance */
			PortHandle* (*createDISTANCEHandle)(struct distanceSensorComponent_Builder*, PortHandle*); /**< The builder method to create a PortHandle for port distance */
			struct port_option DISTANCE_op; /**< The port_option for the PortHandle of port distance */
		void (*distancePortAccessFunction) (int32_T*); /**access function pointer for continuous port */
		/*FIXME add initialize and destroy function pointer*/
}distanceSensorComponent_Builder;

/**
*
*@brief A initializer for the struct distanceSensorComponent_Builder
*@details Shall be used when creating a struct distanceSensorComponent_Builder manually
*/
static const distanceSensorComponent_Builder INIT_BUILDER = { 
	0, 
	PORT_DEACTIVATED, 
	NULL, 
	{0,0}
};

/**
*
*@brief The pool of component instance of Component Type DistanceSensor
*@details The container manages the resource instances in this pool, and this pool allocates the memory for component instances statically
*/
	static DistanceSensorComponent instancePool [2];
	static int pool_length = 0;
	static int pool_index = 0;

/**
*
*@brief The send method for DirectedTypedPort distance 
*
*/	
void MCC_DistanceSensorComponent_distance_send_value(Port* port, int32_T* msg){
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
*@brief The builder for component instance of Component Type DistanceSensor
*@details This method creates and initializes a component instance properly by using the struct distanceSensorComponent_Builder
*/
	static DistanceSensorComponent* MCC_DistanceSensorComponent_Builder(distanceSensorComponent_Builder* b){
		instancePool[pool_index].ID = b->ID;
		instancePool[pool_index].distancePortAccessFunction = b->distancePortAccessFunction;
		//For each port initialize it
			if(b->DISTANCE != PORT_DEACTIVATED) {
			instancePool[pool_index].distancePort.status = b->DISTANCE;
			instancePool[pool_index].distancePort.handle = (PortHandle*) malloc(sizeof(PortHandle));
 			instancePool[pool_index].distancePort.handle->port = &(instancePool[pool_index].distancePort);
			b->createDISTANCEHandle(b, (instancePool[pool_index].distancePort.handle));
			//instancePool[pool_index].distancePort.handle->port = &(instancePool[pool_index].distancePort);
		}
	
		return &instancePool[pool_index++];
	}

static PortHandle* create_DISTANCELocalHandle(distanceSensorComponent_Builder* b, PortHandle *ptr){
	ptr->type = PORT_HANDLE_TYPE_LOCAL;
	LocalHandle* hndl = (LocalHandle*) malloc(sizeof(LocalHandle)+0*sizeof(LocalSubscriber));
	ptr->concreteHandle = hndl;
	hndl->pubID = b->DISTANCE_op.local_option.pubID;
	hndl->subID = b->DISTANCE_op.local_option.subID;
	return ptr;
}


/**
 * @brief Create a component instance with the given id.
 * 
 * @details Creates a component instance using the builder and the configuration options, and also configures the port instances.
 * 
 * @param ID the identifier of the component instance
 */
DistanceSensorComponent* MCC_create_DistanceSensorComponent(uint8_T ID){
	struct distanceSensorComponent_Builder b = INIT_BUILDER;
	switch(ID){
		case CI_FRONTDISTANCESENSORFDISTANCESENSOR:
			b.ID = ID;
			b.distancePortAccessFunction=&CI_FRONTDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand;
			b.DISTANCE = PORT_ACTIVE;
			b.createDISTANCEHandle = &create_DISTANCELocalHandle;
			b.DISTANCE_op.local_option.pubID = -25176;
			b.DISTANCE_op.local_option.subID = -12409;
		break;
		case CI_REARDISTANCESENSORFDISTANCESENSOR:
			b.ID = ID;
			b.distancePortAccessFunction=&CI_REARDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand;
			b.DISTANCE = PORT_ACTIVE;
			b.createDISTANCEHandle = &create_DISTANCELocalHandle;
			b.DISTANCE_op.local_option.pubID = -9629;
			b.DISTANCE_op.local_option.subID = 2631;
		break;
	default:
		break;
	}
	return MCC_DistanceSensorComponent_Builder(&b);
}
	
