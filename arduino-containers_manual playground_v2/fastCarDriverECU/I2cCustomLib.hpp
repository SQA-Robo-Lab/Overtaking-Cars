#ifndef I2C_CUSTOM_LIB_H
#define I2C_CUSTOM_LIB_H

#include <Wire.h>
#include <Arduino.h>

#include "ContainerTypes.h"

typedef struct I2cReceiver {
    char* messageTypeName;
    MessageBuffer* buffer;
} I2cSubscriber;

typedef struct I2cHandle {
    uint8_T ownI2cAddress;
    uint8_T otherI2cAddress;
    uint8_T numOfReceivers;
    I2cReceiver receivers[];
} I2cHandle;

/**
 * @brief Setup the I2C communication once per ECU.
 * 
 * @param ownI2cAddress the own address on the I2C bus.
 */
void I2cCommunication_setup(uint8_T ownI2cAddress);

/**
 * @brief Create and register an I2c Receiver object
 * 
 * @param receiver a pointer to the receiver to be created
 * @param messageTypeName the message type name of the message to receive
 * @param bufferCapacity the capacity of the buffer
 * @param messageSize the size of the message to be received
 * @param bufferMode false: discard new incoming message; true: replace oldest message
 */
void createAndRegisterI2cReceiver(I2cReceiver* receiver,
                        char* messageTypeName,
                        size_t bufferCapacity,
                        size_t messageSize,
                        bool_t bufferMode);

/**
 * @brief Send a message via I2C.
 * 
 * @param receiverAddress the I2C bus address of the receiving ECU
 * @param messageTypeName the message type name of the message to send
 * @param message the actual message
 * @param messageLength the length of the message
 */
void sendI2cMessage(uint8_T receiverAddress,
                    char* messageTypeName,
                    byte* message,
                    size_t messageLength);

#endif /* I2C_CUSTOM_LIB_H */