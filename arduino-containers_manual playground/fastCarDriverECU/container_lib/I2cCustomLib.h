#ifndef I2C_CUSTOM_LIB_H
#define I2C_CUSTOM_LIB_H

#include <Wire.h>

#include "ContainerTypes.h"

typedef struct I2cReceiver {
    uint16_T messageId;
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
 * @param messageId the messageId to receive
 * @param bufferCapacity the capacity of the buffer
 * @param messageSize the size of the message to be received
 * @param bufferMode false: discard new incoming message; true: replace oldest message
 */
void createAndRegisterI2cReceiver(I2cReceiver* receiver,
                        uint16_T messageId,
                        size_t bufferCapacity,
                        size_t messageSize,
                        bool_t bufferMode);

/**
 * @brief Send a message via I2C.
 * 
 * @param receiverAddress the I2C bus address of the receiving ECU
 * @param messageId the messageId of the message to send
 * @param message the actual message
 */
void sendI2cMessage(uint8_T receiverAddress,
                    uint16_T messageId,
                    void* message);

#endif /* I2C_CUSTOM_LIB_H */