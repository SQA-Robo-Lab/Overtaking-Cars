#ifndef MCC_MCC_DISTANCESENSORCOMPONENT_H_
#define MCC_MCC_DISTANCESENSORCOMPONENT_H_

#ifdef __cplusplus
  extern "C" {
#endif	
// Library
#include "ContainerTypes.h"
#include "LocalBufferManager.h"


//Identifier of this ECU
#include "ECU_Identifier.h"

//include the component_interface header
#include "distanceSensorComponent_Interface.h"
//include api mapping headers
#include "CI_FRONTDISTANCESENSORSDISTANCESENSORdistancePortaccessCommand.h"
#include "CI_REARDISTANCESENSORSDISTANCESENSORdistancePortaccessCommand.h"

		
/**
 * @file 
 * @author generated
 * @brief Specification of Component Container for Component of Type: Atomic_Component_DistanceSensor
 * @details This file contains an implementation of the container interfaces of a components
 */

/**
 * @brief Forward Declaration of the method MCC_create_DistanceSensorComponent
 * @details The method for initializing and creating a component instance of type: Atomic_Component_DistanceSensor
 */
DistanceSensorComponent* MCC_create_DistanceSensorComponent(uint8_T id);
#ifdef __cplusplus
  }
#endif
#endif /* MCC_MCC_DISTANCESENSORCOMPONENT_H_ */
