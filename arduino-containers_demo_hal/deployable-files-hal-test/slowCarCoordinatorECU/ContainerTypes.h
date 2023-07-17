#ifndef CONTAINER_TYPES_
#define CONTAINER_TYPES_
#ifdef __cplusplus
extern "C" {
#endif
//available per ECU across container
//copied from orglmuml.c.adapter.container/resources/container_lib due to necessary adjustments

//Global for all Container (e.g. Lib_Container)
#include "port.h" //no subdirs for Arduino build
#include "MessageBuffer.h"


typedef enum {
	PORT_HANDLE_TYPE_MQTT, PORT_HANDLE_TYPE_I2C, PORT_HANDLE_TYPE_LOCAL
} HandleType;

typedef struct PortHandle {
	HandleType type;
	Port* port;
	void *concreteHandle;
} PortHandle;

#ifdef __cplusplus
}
#endif

#endif /* CONTAINER_TYPES_ */
