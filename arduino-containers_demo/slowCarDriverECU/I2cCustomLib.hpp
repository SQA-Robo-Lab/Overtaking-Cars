/**
 * @file I2cCustomLib.hpp
 * @author david
 * @brief Library to wrap the I2C commuication capabilities for the robot cars.
 * 
 * @details The library uses the <Wire.h> for Arduino and the MessageBuffer.h from the MUML C Component Type Code generator.
 * The library does not provide functions to consume messages or check for existing messages. Instead, the library consumes
 * messages from the communication channel and puts them into MessageBuffers. The MessageBuffers provide exists and receive 
 * methods.
 */
#ifndef I2C_CUSTOM_LIB_H
#define I2C_CUSTOM_LIB_H

#include <Wire.h>
#include <Arduino.h>

#include "ContainerTypes.h"

/**
 * @brief An I2C receiver receives messages of a certain messageTypeName and stores them in a buffer.
 */
typedef struct I2cReceiver {
    char* messageTypeName;
    MessageBuffer* buffer;
} I2cSubscriber;

/**
 * @brief The concrete port handle for I2C to store the required configurations.
 */
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
void i2cCommunication_setup(uint8_T ownI2cAddress);

/**
 * @brief Initializes and registers an I2c Receiver object
 * 
 * @param receiver a pointer to the receiver to be initialized - USERS MUST ALLOCATE MEMORY!
 * @param messageTypeName the message type name of the message to receive
 * @param bufferCapacity the capacity of the buffer
 * @param messageSize the size of the message to be received
 * @param bufferMode false: discard new incoming message; true: replace oldest message
 */
void initAndRegisterI2cReceiver(I2cReceiver* const receiver,
                        char* const messageTypeName,
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
                    char* const messageTypeName,
                    byte* const message,
                    size_t messageLength);

#endif /* I2C_CUSTOM_LIB_H */