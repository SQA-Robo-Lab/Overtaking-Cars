		#ifndef MCC_MCC_DISTANCESENSORCOMPONENT_H_
		#define MCC_MCC_DISTANCESENSORCOMPONENT_H_

#ifdef __cplusplus
  extern "C" {
#endif	
				// Library
				#include "../container_lib/ContainerTypes.h"
				#include "../container_lib/LocalBufferManager.h"
				
			
				//Identifier of this ECU
				#include "../ECU_Identifier.h"
			
				//include the component_interfache header
				#include "../components/distanceSensorComponent_Interface.h"
				//include api mapping headers
				#include "../APImappings/CI_REARDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.h"
				#include "../APImappings/CI_FRONTDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.h"
			
					
			/**
			 * @file 
			 * @author generated
			 * @brief Specification of Component Container for Component of Type: Atomic_Component_DistanceSensor
			 * @details This files contains an implementation of the container interfaces of a components
			 */
				
									/**
									 * @brief Forward Declaration of the method MCC_create_DistanceSensorComponent
									 * @details The method for initializing and creating a component instance oc type: Atomic_Component_DistanceSensor
									 */
				DistanceSensorComponent* MCC_create_DistanceSensorComponent(uint8_T id);
#ifdef __cplusplus
  }
#endif
		#endif /* MCC_MCC_DISTANCESENSORCOMPONENT_H_ */
