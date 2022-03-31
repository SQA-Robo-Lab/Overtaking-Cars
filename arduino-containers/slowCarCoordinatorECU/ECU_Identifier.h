#ifndef ECU_IDENTIFIER_H
#define ECU_IDENTIFIER_H
	
// code for ECU Config slowCarCoordinatorECU_config
/**
*
*@brief Identifier for Messages used on slowCarCoordinatorECU_config
*@details Identifier to Identy Local Messages
*/
//Identifier for Messages used on this ECU
#define MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE 1 /**< ECU Identifier: For the Message-Type: finishedOvertaking */
#define MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE 2 /**< ECU Identifier: For the Message-Type: acceptOvertaking */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 3 /**< ECU Identifier: For the Message-Type: denyPermission */
#define MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE 4 /**< ECU Identifier: For the Message-Type: requestOvertaking */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE 5 /**< ECU Identifier: For the Message-Type: executedOvertaking */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 6 /**< ECU Identifier: For the Message-Type: requestPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 7 /**< ECU Identifier: For the Message-Type: grantPermission */

//Identifier for ComponentInstances
/**
*
*@brief Identifier to distinguish Component Instance on ECU slowCarCoordinatorECU_config
*@details Used by a component container to identify component instances of the same component type
*/
#define CI_COMMUNICATORSCOORDINATOR 1 /**< Identifier for Component Instance communicator.S */
			
#endif /* ECU_IDENTIFIER_H */
