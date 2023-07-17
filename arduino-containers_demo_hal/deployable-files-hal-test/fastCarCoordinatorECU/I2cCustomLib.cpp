/**
 * @file I2cCustomLib.cpp
 * @author david
 * @brief Implementation of the library to wrap the I2C commuication capabilities for the robot cars.
 * 
 * @details The library uses the <Wire.h> for Arduino and the MessageBuffer.h from the MUML C Component Type Code generator.
 * The library does not provide a method to consume/receive messages:
 */
#include "I2cCustomLib.hpp"

/**
 * @brief A struct to store a linked list of I2cReceivers.
 */
struct I2cReceiverListElement {
    I2cReceiver* receiver;
    struct I2cReceiverListElement *nextElement;
};

static struct I2cReceiverListElement *i2cReceiverList = NULL; /*init an empty list*/

/**
 * @brief Prepends the message type to the message with a separator: messageTypeName\0message
 * Also dynamically allocates space for the returned byte* -> users MUST free the memory on their own!
 * 
 * @param messageTypeName the name of the message type
 * @param message the actual message
 * @return byte* array of the length: messageLength + strlen(messageTypeName+1)
 */
static byte* marshal(char* messageTypeName, byte* message, size_t messageLength){
    byte* marshalled = (byte *) malloc(strlen(messageTypeName) + 1 + messageLength);
    strcpy((char*) marshalled, messageTypeName);
    memcpy(marshalled+strlen(messageTypeName)+1, message, messageLength);
    return marshalled;
}
/**
 * @brief Cuts the messageTypeName from a message of the form "messageTypeName\0message"
 * Also dynamically allocates space for the returned char* -> users MUST free the memory on their own!
 * 
 * @param receivedBytes the received bytes
 * @param maxLength and their length
 * @return char* points to the unmarshalled messageTypeName
 */
static char* unmarshalTypeName(byte* receivedBytes, size_t maxLength){
    char* messageTypeName = (char*) malloc(maxLength);
    strcpy(messageTypeName, (char*) receivedBytes);
    return messageTypeName;
}

/**
 * @brief Callback function for the I2C receiver. Puts it into the corresponding message buffer.
 * 
 * @param numberOfBytesReceived the length of the message
 */
static void receiveI2cMessageIntoBuffer(int numberOfBytesReceived){
    byte receivedBytes[numberOfBytesReceived]; //allocate space to store the message
    Wire.readBytes(receivedBytes, numberOfBytesReceived); //write the message into the buffer
    char* messageTypeName = unmarshalTypeName(receivedBytes, numberOfBytesReceived); //get the messasgeId
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
        //receivedBytes is structured like messageTypeName\0message
        MessageBuffer_enqueue(bufferToFill, receivedBytes+strlen(messageTypeName)+1);
    }
    free(messageTypeName);
}

static void sendI2cMessage(uint8_T receiverAddress,
                            char* const messageTypeName,
                            byte* const message,
                            size_t messageLength){
    byte *marhsalledMessage = marshal(messageTypeName, message, messageLength);
    Wire.beginTransmission((int) receiverAddress);
    Wire.write(marhsalledMessage, messageLength + strlen(messageTypeName) + 1);
    Wire.endTransmission();
    free(marhsalledMessage);
}

static void i2cCommunication_setup(uint8_T ownI2cAddress){
    Wire.begin((int) ownI2cAddress);
    Wire.onReceive(receiveI2cMessageIntoBuffer);
}

/**
 * @brief The library stores a linked list of receivers. This method appends one receiver to the list.
 * 
 * @param list a pointer to a list element pointer indicating the start of the list
 * @param newReceiver the receiver to append to the list
 */
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

static void initAndRegisterI2cReceiver(I2cReceiver* const receiver,
                        char* const messageTypeName,
                        size_t bufferCapacity,
                        size_t messageSize,
                        bool_t bufferMode){
    receiver->buffer = MessageBuffer_create(bufferCapacity, messageSize, bufferMode);
    receiver->messageTypeName = messageTypeName;
    appendI2cReceiverToList(&i2cReceiverList, receiver);
}