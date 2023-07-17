#ifndef MCC_MCC_COORDINATORCOMPONENT_H_
#define MCC_MCC_COORDINATORCOMPONENT_H_

// Library
#include "ContainerTypes.h"
#include "LocalBufferManager.h"


//Identifier of this ECU
#include "ECU_Identifier.h"

//I2C Specific includes
#include "I2cCustomLib.hpp"
//MQTT specific includes
#include "MqttCustomLib.hpp"
//include the component_interface header
#include "coordinatorComponent_Interface.h"
//include api mapping headers

		
/**
 * @file 
 * @author generated
 * @brief Specification of Component Container for Component of Type: Atomic_Component_Coordinator
 * @details This file contains an implementation of the container interfaces of a components
 */

/**
 * @brief Forward Declaration of the method MCC_create_CoordinatorComponent
 * @details The method for initializing and creating a component instance of type: Atomic_Component_Coordinator
 */
CoordinatorComponent* MCC_create_CoordinatorComponent(uint8_T id);

#endif /* MCC_MCC_COORDINATORCOMPONENT_H_ */
