#include "I2cCustomLib.h"
#include <ArduinoJson.h>

#define MAX_I2C_MESSAGE_SIZE_IN_USE 512

struct I2cReceiverListElement {
    I2cReceiver* receiver;
    struct I2cReceiverListElement *nextElement;
};

static struct I2cReceiverListElement *i2cReceiverList = NULL; /*init an empty list*/

static void sendI2cMessage(uint8_T receiverAddress,
                    uint16_T messageId,
                    void* message){
    char *messageString = marshal(messageId, message);
    Wire.beginTransmission(receiverAddress);
    Wire.write(messageString);
    Wire.endTransmission();
}

static void i2cCommunication_setup(uint8_T ownI2cAddress){
    Wire.begin(ownI2cAddress);
    Wire.onReceive(receiveI2cMessageIntoBuffer);
}

static void receiveI2cMessageIntoBuffer(int numberOfBytesReceived){
    char messageStringBuffer[numberOfBytesReceived +1]; //allocate space to store the message
    memset(messageStringBuffer, 0, numberOfBytesReceived); //fill the string buffer with 0s
    Wire.readBytes(messageStringBuffer, numberOfBytesReceived); //write the message into the string buffer
    uint8_T messageId = unmarshalType(messageStringBuffer); //get the messasgeId
    struct I2cReceiverListElement **list = &i2cReceiverList;
    MessageBuffer *bufferToFill = NULL;
    while(*list != NULL){ //iterate through the list
        I2cReceiver *currentReceiver = (*list)->receiver;
        if (currentReceiver->messageId == messageId){
            bufferToFill = currentReceiver->buffer;
            break;
        }
        list = &(*list)->nextElement;
    }
    if (bufferToFill != NULL){
        //TODO: messageStringBuffer holds a JSON string - should be unmarshalled if content matters
        MessageBuffer_enqueue(bufferToFill, messageStringBuffer);
    }
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
                        uint16_T messageId,
                        size_t bufferCapacity,
                        size_t messageSize,
                        bool_t bufferMode){
    receiver->buffer = MessageBuffer_create(bufferCapacity, messageSize, bufferMode);
    receiver->messageId = messageId;
    appendI2cReceiverToList(&i2cReceiverList, receiver);
}

static char* marshal(uint16_T messageId, void* message){
    DynamicJsonDocument doc(MAX_I2C_MESSAGE_SIZE_IN_USE);
    doc["msgId"] = messageId;
    doc["payload"] = message;

    char jsonString[MAX_I2C_MESSAGE_SIZE_IN_USE];
    serializeJson(doc, jsonString);
    return jsonString;
}

static uint16_T unmarshalType(char* jsonString){
    DynamicJsonDocument doc(MAX_I2C_MESSAGE_SIZE_IN_USE);
    deserializeJson(doc, jsonString);
    return (uint16_T) doc["msgId"];
}
