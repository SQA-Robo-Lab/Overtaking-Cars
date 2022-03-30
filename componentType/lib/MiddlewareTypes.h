/*
 * MiddlewareTypes.h
 *
 *  Created on: 11.03.2014
 *      Author: badrobot
 */
/**
 * @file 
 * @author badrobot
 * @brief The data types which are used in the MiddleWare
 * @warning These data types shall be adapted for a specific target platform
 */

#ifndef MIDDLEWARETYPES_H_
#define MIDDLEWARETYPES_H_
#include "../types/standardTypes.h"
#include "../types/customTypes.h"

/**
 * @brief Type to specify the length of a Queue
 */
typedef unsigned short queue_size_t;

/**
 * @brief Type to specify the length of a Buffer
 */
typedef int bufferSize_t; 

/**
 * @brief Type to specify the ID of a Message
 */
typedef int_t MessageID;

/**
 * @brief Type to specify the ID of a Port
 */
typedef int_t PortID;

/**
 * @brief Type to specify the ID of a ECU
 */ 
typedef int_t ECUID;

/**
 * @brief Type to specify QoS Properties for Messages
 * @note shall be later used to ensure QoS Properties for Messages
 */
typedef struct QoSProps QoSProps;

/**
 * @brief Type to specify a ECU
 */
typedef int_t ECU;

#endif /* MIDDLEWARETYPES_H_ */
