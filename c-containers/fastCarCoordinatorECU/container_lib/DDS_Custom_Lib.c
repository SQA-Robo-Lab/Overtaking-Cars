#include "DDS_Custom_Lib.h"

const DDSHandle INIT_DDSHandle = { NULL, NULL, NULL, 0, 0 };

int publisher_shutdown(DDS_DomainParticipant *participant) {
	DDS_ReturnCode_t retcode;
	int status = 0;

	if (participant != NULL) {
		retcode = DDS_DomainParticipant_delete_contained_entities(participant);
		if (retcode != DDS_RETCODE_OK) {
			printf("delete_contained_entities error %d\n", retcode);
			status = -1;
		}

		retcode = DDS_DomainParticipantFactory_delete_participant(
		DDS_TheParticipantFactory, participant);
		if (retcode != DDS_RETCODE_OK) {
			printf("delete_participant error %d\n", retcode);
			status = -1;
		}
	}

	/* RTI Data Distribution Service provides finalize_instance() method on
	 domain participant factory for people who want to release memory used
	 by the participant factory. Uncomment the following block of code for
	 clean destruction of the singleton. */
	/*
	 retcode = DDS_DomainParticipantFactory_finalize_instance();
	 if (retcode != DDS_RETCODE_OK) {
	 printf("finalize_instance error %d\n", retcode);
	 status = -1;
	 }
	 */

	return status;
}

/* Delete all entities */
int subscriber_shutdown(DDS_DomainParticipant *participant) {
	DDS_ReturnCode_t retcode;
	int status = 0;

	if (participant != NULL) {
		retcode = DDS_DomainParticipant_delete_contained_entities(participant);
		if (retcode != DDS_RETCODE_OK) {
			printf("delete_contained_entities error %d\n", retcode);
			status = -1;
		}

		retcode = DDS_DomainParticipantFactory_delete_participant(
		DDS_TheParticipantFactory, participant);
		if (retcode != DDS_RETCODE_OK) {
			printf("delete_participant error %d\n", retcode);
			status = -1;
		}
	}

	/* RTI Data Distribution Service provides the finalize_instance() method on
	 domain participant factory for users who want to release memory used
	 by the participant factory. Uncomment the following block of code for
	 clean destruction of the singleton. */
	/*
	 retcode = DDS_DomainParticipantFactory_finalize_instance();
	 if (retcode != DDS_RETCODE_OK) {
	 printf("finalize_instance error %d\n", retcode);
	 status = -1;
	 }
	 */

	return status;
}

void PublisherListener_PublicationMatched(void *listener_data,	DDS_DataWriter *writer,	const struct DDS_PublicationMatchedStatus *status) {
	PortHandle* p = (PortHandle*) listener_data;
	DDSHandle* dds_handle = (DDSHandle*) p->concreteHandle;
	DDS_SubscriptionBuiltinTopicData subscriptionData =
			DDS_SubscriptionBuiltinTopicData_INITIALIZER;
	DDS_DataWriter_get_matched_subscription_data(writer, &subscriptionData,
			&(status->last_subscription_handle));
	struct DDS_PublisherQos pubQos = DDS_PublisherQos_INITIALIZER;
	DDS_Publisher_get_qos(dds_handle->publisher, &pubQos);
	if (subscriptionData.partition.name._length == pubQos.partition.name._length){
	dds_handle->numOfWriterToMatch--;
	if (dds_handle->numOfWriterToMatch == 0) {
		p->port->status = PORT_ACTIVE;
	}
	}
	DDS_SubscriptionBuiltinTopicData_finalize(&subscriptionData);

}

void PublisherListener_LivelinessLost(void *listener_data,	DDS_DataWriter *writer, const struct DDS_LivelinessLostStatus *status) {

		PortHandle* p = (PortHandle*) listener_data;
		DDSHandle* dds_handle = (DDSHandle*) p->concreteHandle;
		struct DDS_PublisherQos pubQos = DDS_PublisherQos_INITIALIZER;
		DDS_Publisher_get_qos(dds_handle->publisher, &pubQos);
		//if (subscriptionData.partition.name._length != pubQos.partition.name._length)
	//		return;
		dds_handle->numOfWriterToMatch++;
		p->port->status = PORT_CONNECTIONLOST;
		DDS_PublisherQos_finalize(&pubQos);


}

void SubscriberListener_LivelinessChanged(void *listener_data,DDS_DataReader *reader,const struct DDS_LivelinessChangedStatus *status) {
		PortHandle* p = (PortHandle*) listener_data;
		DDSHandle* dds_handle = (DDSHandle*) p->concreteHandle;
		DDS_PublicationBuiltinTopicData publishData =
				DDS_PublicationBuiltinTopicData_INITIALIZER;
		DDS_DataReader_get_matched_publication_data(reader, &publishData, &(status->last_publication_handle));
		struct DDS_SubscriberQos subQos = DDS_SubscriberQos_INITIALIZER;
		DDS_Subscriber_get_qos(dds_handle->subscriber, &subQos);
		if (publishData.partition.name._length == subQos.partition.name._length){
		dds_handle->numOfReaderToMatch--;
		if (dds_handle->numOfReaderToMatch == 0) {
			p->port->status = PORT_ACTIVE;
		}
		}
		DDS_PublicationBuiltinTopicData_finalize(&publishData);


}

void SubscriberListener_SubscriptionMatched(void *listener_data,DDS_DataReader *reader,	const struct DDS_SubscriptionMatchedStatus *status) {
		PortHandle* p = (PortHandle*) listener_data;
		DDSHandle* dds_handle = (DDSHandle*) p->concreteHandle;
			struct DDS_SubscriberQos subQos = DDS_SubscriberQos_INITIALIZER;
			DDS_Subscriber_get_qos(dds_handle->subscriber, &subQos);
		//	if (publishData.partition.name._length != subQos.partition.name._length)
		//		return;
			dds_handle->numOfReaderToMatch++;
			p->port->status = PORT_CONNECTIONLOST;
			DDS_SubscriberQos_finalize(&subQos);
}
