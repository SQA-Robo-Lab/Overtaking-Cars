#ifndef ECU_IDENTIFIER_H
#define ECU_IDENTIFIER_H
	
// code for ECU Config fastCarDriverECU_config
/**
*
*@brief Identifier for Messages used on fastCarDriverECU_config
*@details Identifier to Identy Local Messages
*/
//Identifier for Messages used on this ECU
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 1 /**< ECU Identifier: For the Message-Type: denyPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 2 /**< ECU Identifier: For the Message-Type: requestPermission */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE 3 /**< ECU Identifier: For the Message-Type: executedOvertaking */
#define MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE 4 /**< ECU Identifier: For the Message-Type: grantPermission */

//Identifier for ComponentInstances
/**
*
*@brief Identifier to distinguish Component Instance on ECU fastCarDriverECU_config
*@details Used by a component container to identify component instances of the same component type
*/
#define CI_FRONTDISTANCESENSORFDISTANCESENSOR 1 /**< Identifier for Component Instance frontDistanceSensor.F */
#define CI_REARDISTANCESENSORFDISTANCESENSOR 2 /**< Identifier for Component Instance rearDistanceSensor.F */
#define CI_POWERTRAINFPOWERTRAIN 3 /**< Identifier for Component Instance powerTrain.F */
#define CI_DRIVECONTROLFDRIVECONTROL 4 /**< Identifier for Component Instance driveControl.F */
			
#endif /* ECU_IDENTIFIER_H */
