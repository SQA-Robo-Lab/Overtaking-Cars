#ifndef ECU_IDENTIFIER_H
#define ECU_IDENTIFIER_H
	
// code for ECU Config fastCarDriverECU_config
/**
*
*@brief Identifier for Messages used on fastCarDriverECU_config
*@details Identifier to Identy Local Messages
*/
//Identifier for Messages used on this ECU
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 1 /**< ECU Identifier: For the Message-Type: requestPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 2 /**< ECU Identifier: For the Message-Type: grantPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 3 /**< ECU Identifier: For the Message-Type: denyPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE 4 /**< ECU Identifier: For the Message-Type: executedOvertaking */

//Identifier for ComponentInstances
/**
*
*@brief Identifier to distinguish Component Instance on ECU fastCarDriverECU_config
*@details Used by a component container to identify component instances of the same component type
*/
#define CI_REARDISTANCESENSORFDISTANCESENSOR 1 /**< Identifier for Component Instance rearDistanceSensor.F */
#define CI_FRONTDISTANCESENSORFDISTANCESENSOR 2 /**< Identifier for Component Instance frontDistanceSensor.F */
#define CI_DRIVECONTROLFDRIVECONTROL 3 /**< Identifier for Component Instance driveControl.F */
#define CI_POWERTRAINFPOWERTRAIN 4 /**< Identifier for Component Instance powerTrain.F */
			
#endif /* ECU_IDENTIFIER_H */
