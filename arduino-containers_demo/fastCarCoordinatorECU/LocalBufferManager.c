//FIXME: avialable per ECU across container

#ifdef __cplusplus
extern "C" {
#endif
// Library
#include "LocalBufferManager.h"

const LocalHandle INIT_LocalHandle = { 0, 0,0};


struct subscriber_node {
	LocalSubscriber* subscriber;
	struct subscriber_node *next;
};

struct buffer_hashed {
	uint16_T id; /*key */
	struct subscriber_node* subscriberList;
	UT_hash_handle hh; // make structure hashtable
};

static struct buffer_hashed *buffer_list = NULL; /* important! initialize to NULL */

void publishMessage(uint16_T bufferID, uint16_T msgID, void* msg) {
	struct buffer_hashed *b;
	uint16_T new_id = bufferID + msgID;
	//find interested Subscriber
	HASH_FIND_INT(buffer_list, &new_id, b);
	if (b != NULL) {
		struct subscriber_node *lst = b->subscriberList;
		while (lst != NULL) {
			MessageBuffer_enqueue(lst->subscriber->buffer, msg);
			lst = lst->next;
		}
	}
}

static void appendSubscriber(struct subscriber_node **lst,
		LocalSubscriber* value) {
	struct subscriber_node *new_node;
	while (*lst != NULL) {
		lst = &(*lst)->next;
	}
	new_node = malloc(sizeof(struct subscriber_node));
	new_node->subscriber = value;
	new_node->next = NULL;
	*lst = new_node;
}

static void registerSubscriber(LocalSubscriber* sub, uint16_T bufferID,
		uint16_T msgID) {
	struct buffer_hashed *b;
	uint16_T new_id = bufferID + msgID;
	HASH_FIND_INT(buffer_list, &new_id, b); /* id already in the hash? */
	if (b == NULL) {
		b = (struct buffer_hashed*) malloc(sizeof(struct buffer_hashed));
		b->id = new_id;
		b->subscriberList = NULL;
		appendSubscriber(&(b->subscriberList), sub);
		HASH_ADD_INT(buffer_list, id, b); /* id: name of key field */
	}
	else{
		appendSubscriber(&(buffer_list->subscriberList), sub);
	}
}

void subscribeToMessage( LocalSubscriber* subscriber, uint16_T bufferID, uint16_T msgID,
		size_t capactiy, size_t elementSize, bool_t mode) {
	subscriber->buffer = MessageBuffer_create(capactiy, elementSize, mode);
	subscriber->msgID=msgID;
	registerSubscriber(subscriber, bufferID, msgID);
}

#ifdef __cplusplus
}
#endif
