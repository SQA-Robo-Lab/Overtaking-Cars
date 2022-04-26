#ifndef DDS_CUSTOM_LIB_H_
#define DDS_CUSTOM_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "ndds/ndds_c.h"
#include "ContainerTypes.h"
//FIXME create DDSHandle;
typedef struct DDSHandle {
	DDS_DomainParticipant *participant;
	DDS_Publisher *publisher;
	DDS_Subscriber *subscriber;
	u_int8_t numOfWriterToMatch;
	u_int8_t numOfReaderToMatch;
} DDSHandle;


extern const DDSHandle INIT_DDSHandle;
//FIXME: makefile flag for DDS ends here

int publisher_shutdown(DDS_DomainParticipant *participant);
int subscriber_shutdown(DDS_DomainParticipant *participant);



/**
 * Call back functions used by DDS to indicate status changes
 */
void PublisherListener_PublicationMatched(void *listener_data, DDS_DataWriter *writer, const struct DDS_PublicationMatchedStatus *status);

void PublisherListener_LivelinessLost(void *listener_data, DDS_DataWriter *writer, const struct DDS_LivelinessLostStatus *status);


void SubscriberListener_LivelinessChanged(void *listener_data, DDS_DataReader *reader, const struct DDS_LivelinessChangedStatus *status);

void SubscriberListener_SubscriptionMatched(void *listener_data, DDS_DataReader *reader, const struct DDS_SubscriptionMatchedStatus *status);

#ifdef __cplusplus
	}
#endif
#endif
