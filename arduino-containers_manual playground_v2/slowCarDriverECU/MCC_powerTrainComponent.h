#ifndef MCC_MCC_POWERTRAINCOMPONENT_H_
#define MCC_MCC_POWERTRAINCOMPONENT_H_

#ifdef __cplusplus
  extern "C" {
#endif	
// Library
#include "ContainerTypes.h"
#include "LocalBufferManager.h"


//Identifier of this ECU
#include "ECU_Identifier.h"

//include the component_interface header
#include "powerTrainComponent_Interface.h"
//include api mapping headers
#include "CI_POWERTRAINSPOWERTRAINvelocityPortaccessCommand.h"

		
/**
 * @file 
 * @author generated
 * @brief Specification of Component Container for Component of Type: Atomic_Component_PowerTrain
 * @details This file contains an implementation of the container interfaces of a components
 */

/**
 * @brief Forward Declaration of the method MCC_create_PowerTrainComponent
 * @details The method for initializing and creating a component instance of type: Atomic_Component_PowerTrain
 */
PowerTrainComponent* MCC_create_PowerTrainComponent(uint8_T id);
#ifdef __cplusplus
  }
#endif
#endif /* MCC_MCC_POWERTRAINCOMPONENT_H_ */
