/**
 * @file 
 * @author badrobot
 * @brief This file specifies the MessageBuffer, which are contained at the Components
 * @details  The MessageBuffer are used at the Components to store  MiddlewareMessage%s
 */
#ifndef MESSAGEBUFFER_H_
#define MESSAGEBUFFER_H_

//FIXME: moved from Lib Folder here (components shall not have a dependency to a buffer)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



#include "standardTypes.h"
/**
 * 
 * @brief A MessageBuffer of a Port
 * @details MessageBuffers are contained at a Port and store received MiddlewareMessages in MessageBuffer::queue
 * 
 */
typedef struct MessageBuffer{
	void* buffer; /**< A ring buffer of MiddlewareMessages  */
	void *buffer_end; // end of buffer
	size_t capacity; // capacity of thge buffer
	size_t count; /**< The number of currently enqueued MiddlewareMessages; The current Size of the Queue */
	size_t elementSize; //size of elements stored in buffer
	void* head;  /**< The current Index of the MessageBuffer::queue */ // points to the current head element
	void* tail;  /**< The current Tail of the MessageBuffer::queue */ // points to the next free slot
	bool_t bufferMode;  /**< The mode of a MessageBuffer - false: discard new incoming message; true: replace oldest message*/
}MessageBuffer;


 /**
  * @brief Creates a new MessageBuffer
  * @details Memory for a MessageBuffer and its queue is allocated and the MessageBuffer is initialized
  * 
  * @param size the size of the queue for this MessageBuffer
  * @param mode description
  * @param numberOfIDs the number of IDs which are supported, the size of the Array numberIfIDs
  * @param supportedIDs an Array of IDs which are can be stored in this MessageBuffer
  * @return the pointer to the allocated MessageBuffer
  */
MessageBuffer* MessageBuffer_create(size_t capacity, size_t elementSize, bool_t mode);



 /**
  * @brief Get the current size of a MessageBuffer
  * @details Returns the current number of MiddlewareMessage%s, which are enqueued in a MessageBuffer
  * 
  * @param buf The  MessageBuffer
  * @return MessageBuffer::currentSize
  */
size_t MessageBuffer_getSize(MessageBuffer* buf);



 /**
  * @brief Enqueues a new MiddlewareMessage to a MessageBuffer
  * @details  before you enqueue the MiddlewareMessage, make sure that you have checked that this is the correct buffer
  * 
  * @param buf The MessageBuffer to which the MiddlewareMessage shall be enqueued
  * @param msg The MiddlewareMessage which shall be enqueued
  * 
  * @return True, if the MiddlewareMessage could be enqueued, otherwise False
  */
bool_t MessageBuffer_enqueue(MessageBuffer* buf, const void* msg);



 /**
  * @brief Dequeues the Head of the MessageBuffer and returns the MiddlewareMessage
  * 
  * @param buf The MessageBuffer
  *
  * @return A pointer to the MiddlewareMessage if one is contained, otherwise NULL
  */
bool_t MessageBuffer_dequeue(MessageBuffer* buf, void* msg);


/**
 * @brief Whether a MessageBuffer contains a MiddlewareMessage with a specific MessageID
 *
 * @param buf The MessageBuffer
 * @param ID The ID of a MiddlewareMessage for which it shall be checked if suchone exists
 *
 * @return True, if a MiddlewareMessage with the given MessageID is contained, otherwise False
 */
bool_t MessageBuffer_doesMessageExists(MessageBuffer* buf);




 /**
  * @brief Destroys the MessageBuffer
  * @details Destroys the MessageBuffer and all MiddlewareMessage which are contained in MessageBuffer::queue
  * 
  * @param buf The MessageBuffer which shall be destroyed
  */
void MessageBuffer_destroy(MessageBuffer* buf);

#endif /* MESSAGEBUFFER_H_ */
