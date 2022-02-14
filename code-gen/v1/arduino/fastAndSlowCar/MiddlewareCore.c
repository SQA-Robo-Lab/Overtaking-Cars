#include "MiddlewareCore.h"
//import all needed ComponentHeaders
#include "driveControlComponent_Interface.h"
#include "coordinatorComponent_Interface.h"
#include "driveControlComponent_Interface.h"
#include "coordinatorComponent_Interface.h"

/*
 * create a new middleware instance
 * called by the system initialization (once)
 */
Middleware* Middleware_create(void){
	mw = (Middleware*) malloc(sizeof(Middleware));
	/*
	 * call create-function for every NI of the ECU
	 */
	mw->intern = NetworkInterface_create("intern");

	if(Middelware_init() == true){
		return mw;
	}
	else{
		return NULL;
	}

}

/*
 * initialize the middleware instance
 * called by the system initialization (once)
 */
bool_t Middelware_init(void){
		
	if (mw != NULL){
        mw->idOfECU = 1;
        mw->incoming = NetworkMessageBuffer_create(15, true);
        mw->outgoing = NetworkMessageBuffer_create(15, true);
		return true;
	}else
		return false;
}

/*
 * destroys the middleware instance
 * called by the system initialization (once)
 */
bool_t Middleware_destroy(void){
	if (mw != NULL){
		//destroy all components
	DriveControlComponent_destroy(mw->driveControlComponent);
	CoordinatorComponent_destroy(mw->communicatorComponent);
	DriveControlComponent_destroy(mw->driveControlComponent);
	CoordinatorComponent_destroy(mw->communicatorComponent);

//destroy all network interfaces
	NetworkInterface_destroy(mw->intern);


//destroy all NetworkMessageBuffer
  	NetworkMessageBuffer_destroy(mw->incoming);
    NetworkMessageBuffer_destroy(mw->outgoing);
// destroy the middleware itself
		free(mw);
		return true;
	}else
		return false;
}

/*
 * sends a message.
 */
bool_t MW_sendMessage(PortID targetPort, MessageID id, void *msg){
	MiddlewareMessage* nwMsg = (MiddlewareMessage*) malloc(sizeof(MiddlewareMessage));
	nwMsg->_msgID = id;
	nwMsg->_targetPort = targetPort;
	
	//choose right function to create the bytearray (which is actually a chararray).
	switch(id){
		default:
			nwMsg->_mumlMsg_len = 0;
			break;
	}
	Port *p = MW_getPortforIdentifier(targetPort);
	if (p != NULL){
		Port_addMessage(p, nwMsg);
		
		
		return true;
	}
	else
		return false;


}


/*
 * calls the receive-message of the middleware and delivers all messages to the correct buffers
 * will be called periodically
 */
bool_t MW_deliverReceivedMessages(void){
//not needed for local middleware
return true;	
}


/*
 * receives messages for every known NetworkInterface
 */
bool_t MW_NIreceiveMessages(void){
  //not needed for local middleware  
	
    return true;
}

/*
 * as long we have messages in the outgoing-buffer,
 * we try to send them via the "best" network interface
 */
bool_t MW_NIsendMessages(void){
	//not needed for local middleware
return true;
}


Port* MW_getPortforIdentifier(PortID portID){
    switch (portID) {
case PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1:
	return mw->driveControlComponent->driveControlPort;
	break;
case PORT_COMMUNICATORCOORDINATORDRIVECONTROL1:
	return mw->communicatorComponent->communicatorPort;
	break;
case PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1:
	return mw->communicatorComponent->overtakingInitiatorPort;
	break;
case PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1:
	return mw->communicatorComponent->overtakingAffiliatePort;
	break;
case PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1:
	return mw->driveControlComponent->driveControlPort;
	break;
case PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1:
	return mw->communicatorComponent->overtakingInitiatorPort;
	break;
case PORT_COMMUNICATORCOORDINATORDRIVECONTROL1:
	return mw->communicatorComponent->communicatorPort;
	break;
case PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1:
	return mw->communicatorComponent->overtakingAffiliatePort;
	break;
        default:
            return NULL;
    }
    
}


/*
* Return the  PortID of a receiving port for a given sender PortID
*
*/
PortID MW_getTargetPortIDforIdentifier(PortID portID){ 
switch (portID) {
		case PORT_FASTCARROBOCAROVERTAKINGINITIATOR1:
		return PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1;
		break;
		case PORT_FASTCARROBOCAROVERTAKINGAFFILIATE1:
		return PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1;
		break;
		case PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1:
		return PORT_COMMUNICATORCOORDINATORDRIVECONTROL1;
		break;
		case PORT_COMMUNICATORCOORDINATORDRIVECONTROL1:
		return PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1;
		break;
		case PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1:
		return PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1;
		break;
		case PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1:
		return PORT_FASTCARROBOCAROVERTAKINGAFFILIATE1;
		break;
		case PORT_SLOWCARROBOCAROVERTAKINGINITIATOR1:
		return PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1;
		break;
		case PORT_SLOWCARROBOCAROVERTAKINGAFFILIATE1:
		return PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1;
		break;
		case PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1:
		return PORT_COMMUNICATORCOORDINATORDRIVECONTROL1;
		break;
		case PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1:
		return PORT_SLOWCARROBOCAROVERTAKINGINITIATOR1;
		break;
		case PORT_COMMUNICATORCOORDINATORDRIVECONTROL1:
		return PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1;
		break;
		case PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1:
		return PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1;
		break;
        default:
            return -1;
    }
}
