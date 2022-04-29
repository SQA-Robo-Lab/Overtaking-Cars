#include "I2cCustomLib.hpp"

#define MAX_I2C_MESSAGE_SIZE_IN_USE 512

struct I2cReceiverListElement {
    I2cReceiver* receiver;
    struct I2cReceiverListElement *nextElement;
};

static struct I2cReceiverListElement *i2cReceiverList = NULL; /*init an empty list*/

/**
 * @brief Prepends the message type to the message with a separator: messageTypeName|message
 * 
 * @param messageTypeName 
 * @param message 
 * @return byte* array of the length: messageLength + strlen(messageTypeName+1)
 */
static byte* marshal(char* messageTypeName, byte* message, size_t messageLength){
    // TODO
    return (byte *) "test|message";
}

static char* unmarshalTypeName(byte* receivedBytes){
    // TODO
    return "test";
}

/**
 * @brief Callback function for the I2C receiver. Puts it into the corresponding message buffer.
 * 
 * @param numberOfBytesReceived the length of the message
 */
static void receiveI2cMessageIntoBuffer(int numberOfBytesReceived){
    byte receivedBytes[numberOfBytesReceived]; //allocate space to store the message
    Wire.readBytes(receivedBytes, numberOfBytesReceived); //write the message into the buffer
    char* messageTypeName = unmarshalTypeName(receivedBytes); //get the messasgeId
    struct I2cReceiverListElement **list = &i2cReceiverList;
    MessageBuffer *bufferToFill = NULL;
    while(*list != NULL){ //iterate through the list
        I2cReceiver *currentReceiver = (*list)->receiver;
        if (strcmp(currentReceiver->messageTypeName, messageTypeName) == 0){
            bufferToFill = currentReceiver->buffer;
            break;
        }
        list = &(*list)->nextElement;
    }
    if (bufferToFill != NULL){
        //TODO: receivedBytes starts with the messageTypeName - should be unmarshalled if content matters
        MessageBuffer_enqueue(bufferToFill, receivedBytes);
    }
}

static void sendI2cMessage(uint8_T receiverAddress,
                            char* messageTypeName,
                            byte* message,
                            size_t messageLength){
    byte *marhsalledMessage = marshal(messageTypeName, message, messageLength);
    Wire.beginTransmission((int) receiverAddress);
    Wire.write(marhsalledMessage, messageLength + strlen(messageTypeName+1));
    Wire.endTransmission();
}

static void i2cCommunication_setup(uint8_T ownI2cAddress){
    Wire.begin((int) ownI2cAddress);
    Wire.onReceive(receiveI2cMessageIntoBuffer);
}

static void appendI2cReceiverToList(struct I2cReceiverListElement **list, I2cReceiver *newReceiver){
    struct I2cReceiverListElement *newListElement;
    while(*list != NULL){ //navigate to the end of the list
        list = &(*list)->nextElement;
    }
    newListElement = (struct I2cReceiverListElement*) malloc(sizeof(struct I2cReceiverListElement));
    newListElement->receiver = newReceiver;
    newListElement->nextElement = NULL;
    *list = newListElement; //append the new item to the list
}

static void createAndRegisterI2cReceiver(I2cReceiver* receiver,
                        char* messageTypeName,
                        size_t bufferCapacity,
                        size_t messageSize,
                        bool_t bufferMode){
    receiver->buffer = MessageBuffer_create(bufferCapacity, messageSize, bufferMode);
    receiver->messageTypeName = messageTypeName;
    appendI2cReceiverToList(&i2cReceiverList, receiver);
}