/*
 * MessageBuffer.c
 *
 *  Created on: 13.03.2014
 *      Author: badrobot
 */

#include "MessageBuffer.h"

MessageBuffer* MessageBuffer_create(size_t capacity, size_t elementSize,
		bool_t mode) {
	MessageBuffer* buf = (MessageBuffer*) malloc(sizeof(MessageBuffer));
	if (buf != NULL) {
		buf->elementSize = elementSize;
		buf->capacity = capacity;
		buf->bufferMode = mode;
		buf->buffer = malloc(capacity * elementSize);
		buf->buffer_end = (char *) buf->buffer + buf->capacity * buf->elementSize;
		//initialize the new created MessageBuffer
		buf->head = buf->buffer;
		buf->tail = buf->buffer;
		buf->count = 0;
	}
	return buf;
}
size_t MessageBuffer_getSize(MessageBuffer* buf) {

	return buf->count;
}

bool_t MessageBuffer_enqueue(MessageBuffer* buf, const void* msg) {
	if (buf->count < buf->capacity) {
		//the buffer is still not full
		memcpy(buf->tail,msg,  buf->elementSize);
		buf->tail = (char *) buf->tail + buf->elementSize;
		buf->count++;
		if (buf->tail == buf->buffer_end) {
			buf->tail = buf->buffer;
		}
		return true;
	} else if (buf->bufferMode) { //replace oldest message in buffer
		//tail points to start again (see above)
		memcpy(buf->tail, msg ,buf->elementSize);
		buf->tail = (char *) buf->tail + buf->elementSize;
		buf->head = (char *) buf->head + buf->elementSize;

		return true;
	}

	return false;

}

bool_t MessageBuffer_dequeue(MessageBuffer* buf, void* msg) {
	if (buf->count > 0) {
		memcpy(msg, buf->head, buf->elementSize);
		buf->head = (char *) buf->head + buf->elementSize;
		buf->count--;
		if (buf->head == buf->buffer_end) {
			buf->head = buf->buffer;
		}
	return true;
	}

	return false;
}

bool_t MessageBuffer_doesMessageExists(MessageBuffer* buf) {

	return buf->count > 0;
}

void MessageBuffer_destroy(MessageBuffer* buf) {
	if (buf != NULL) {
		//free the memory of the messages which are contained in this buffer
		free(buf->buffer);
		//free the memory of the MessageBuffer
		free(buf);
	}
}
