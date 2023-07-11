	/**
 * @file 
 * @author generated by Fraunhofer IEM
 * @brief Specification of Component of Type: DistanceSensor
 * @details This files contains a description of the DistanceSensor in form of the DistanceSensorComponent
 * 			and all methods which can be executed on an Instance of this Component
 */
		#ifndef DISTANCESENSORCOMPONENT_Interface_H_
		#define DISTANCESENSORCOMPONENT_Interface_H_

#ifdef __cplusplus
  extern "C" {
#endif		// Library
	#include "../types/standardTypes.h"
	#include "../types/customTypes.h"
	#include "../lib/port.h"
	#include "../lib/clock.h"
	#include "../lib/Debug.h"
			/*****
 			 *
 			 *  Forward Delcaration of Container Functions
 			 *
 			 */		
			
						void MCC_DistanceSensorComponent_distance_send_value(Port* p, int32_T* value);
			
			
	
			/*****
 			 *
 			 *  Component Functions
 			 *
 			 */
			/**
			 * @file 
			 * @author generated by Fraunhofer IEM 
			 * @brief Specification of Component of Type: DistanceSensor
			 * @details This files contains a description of the DistanceSensor in form of the DistanceSensorComponent
			 * 			and all methods which can be executed on an Instance of this Component
			 */
				
						/**
						 * @brief Forward Declaration of the struct DistanceSensorComponent
						 */
							typedef struct DistanceSensorComponent DistanceSensorComponent;
						
						/**
						*  
						* @brief Description for a ComponentInstance of Type: DistanceSensor
						* @details This struct describes a specific Component Instances which is typed over the Component: DistanceSensor
						*/
						struct DistanceSensorComponent {
						
								uint8_T ID;	
						
						
							
										Port distancePort; /**< A  Component's Port: distance */
										Clock distancePortClock; /**< A  Hybrid/ Continuous Port's Clock: distancePortClock */
								
									void (*distancePortAccessFunction) (int32_T*); /**access function pointer for continuous port */
									/*FIXME: Add InitFunction and Destory Funcion */
						
									int32_T distance; /*A Ports Data Variable*/
								
								
						
								DistanceSensorComponent * next;/**< A Pointer to the next component part, if this component ist part of a multipart in the CIC */
								
							};
					
						/**
						* @brief This Methodes intializes the Component: DistanceSensor
						* @details All struct members of the struct DistanceSensorComponent are initialized
						* 
						* @param component The DistanceSensorComponent to be initialized
						*/	
							void DistanceSensorComponent_initialize(DistanceSensorComponent* component);
				
						/**
						* @brief Creates a Instance of the Component: DistanceSensor
						* @details Allocates Memory for the struct DistanceSensorComponent
						* @return A Pointer to the new created DistanceSensorComponent
						*/
							DistanceSensorComponent DistanceSensorComponent_create();
				
						/**
						 * @brief Destroys a Component: DistanceSensor
						 * @details Frees the Memory for the struct DistanceSensorComponent
						 * 
						* @param component The specific DistanceSensorComponent to be destroyed
						 */
							void DistanceSensorComponent_destroy(DistanceSensorComponent* component);
						
						/**
						* @brief Executes the next Step of the behavior an Instance of the Component: DistanceSensor
						* @details The behavior of the Component:  DistanceSensor is executed.
						*			
						* @param component The DistanceSensorComponent whose behavior shall be checked
						*/
							void DistanceSensorComponent_processStep(DistanceSensorComponent* component);
				
			
			
			
			
						/*Getter and Setter for Sending Values of Hybrid/Continuous ports*/
									void setterOf_distance(Port* distancePort, int32_T* distance);/**< A Pointer to the setter function of the port: distance */
					
						
		

	





#ifdef __cplusplus
  }
#endif
		#endif /* DISTANCESENSORCOMPONENT_Interface_H_ */
