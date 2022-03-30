#ifndef ECU_IDENTIFIER_H
#define ECU_IDENTIFIER_H
	
// code for ECU Config fastCarCoordinatorECU_config
/**
*
*@brief Identifier for Messages used on fastCarCoordinatorECU_config
*@details Identifier to Identy Local Messages
*/
//Identifier for Messages used on this ECU
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 1 /**< ECU Identifier: For the Message-Type: requestPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE 2 /**< ECU Identifier: For the Message-Type: executedOvertaking */
#define MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE 3 /**< ECU Identifier: For the Message-Type: finishedOvertaking */
#define MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE 4 /**< ECU Identifier: For the Message-Type: requestOvertaking */
#define MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE 5 /**< ECU Identifier: For the Message-Type: acceptOvertaking */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 6 /**< ECU Identifier: For the Message-Type: grantPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 7 /**< ECU Identifier: For the Message-Type: denyPermission */

//Identifier for ComponentInstances
/**
*
*@brief Identifier to distinguish Component Instance on ECU fastCarCoordinatorECU_config
*@details Used by a component container to identify component instances of the same component type
*/
#define CI_COMMUNICATORFCOORDINATOR 1 /**< Identifier for Component Instance communicator.F */
			
#endif /* ECU_IDENTIFIER_H */
