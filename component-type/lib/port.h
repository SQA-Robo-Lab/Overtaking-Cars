/**
 * @file 
 * @author badrobot
 * @brief The Ports of ComponentInstances
 * @details  In MechatronicUML this correspond to the PortInstance of a Component-Instance.
 *       Since the Codegen-model does only contain discretePorts, we do not need to provide
 *      an implementation of hybrid, continuous or delegation ports.
 */
#ifndef PORT_H_
#define PORT_H_

#include "stdlib.h"
#include "../types/standardTypes.h"
#include "../types/customTypes.h"

/**
 * @brief The structure Port
 * @details A Port is contained at an Instance of a Component and has some #MessageBuffer%s to store incoming Messages.
 * 			Furthermore, a Port has an unique ID which is used to identify the Port
 * @note 	The PortID is not only unique for one ECU, but for all ECUs, it serves as an unique address
 */


//FIXME: create typedef PortHandle
typedef struct PortHandle* PortHandlePtr;


/**
 * @brief The structure Port
 * @details A Port is contained at an Instance of a Component and has some #MessageBuffer%s to store incoming Messages.
 * 			Furthermore, a Port has an unique ID which is used to identify the Port
 * @note 	The PortID is not only unique for one ECU, but for all ECUs, it serves as an unique address
 */

//FIXME: typedef PortStatus
typedef enum {
	PORT_DEACTIVATED, PORT_UNCONNECTED, PORT_CONNECTIONLOST, PORT_ACTIVE
} PortStatus;

typedef struct Port {
	PortStatus status;
	PortHandlePtr handle;
} Port;


#endif /* PORT_H_ */
