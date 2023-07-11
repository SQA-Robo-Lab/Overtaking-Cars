/**
 * @file MqttCustomLib.hpp
 * @author david
 * @brief Library to wrap the MQTT commuication capabilities for the robot cars.
 * 
 * @details The library uses the <PubSubClient.h> for Arduino and the MessageBuffer.h from the MUML C Component Type Code generator.
 * Furthermore, its implementation has several hardware assumptions, see MqttCustomLib.cpp.
 * The library does not provide functions to consume messages or check for existing messages. Instead, the library consumes
 * messages from the communication channel and puts them into MessageBuffers. The MessageBuffers provide exists and receive 
 * methods. Refer to MessageBuffer.h.
 */
#ifndef MQTT_CUSTOM_LIB_H
#define MQTT_CUSTOM_LIB_H

#include "ContainerTypes.h"
#include <PubSubClient.h>

/**
 * @brief An MqttSubscriber subscribes to a certain topic for a certain messageTypeName,
 * and the messages are stored in a buffer. The topic is publishingTopic+messageTypeName,
 * and is stored in the assembled way to avoid new string construction for each sending. 
 */
typedef struct MqttSubscriber {
    char* topic;
    char* messageTypeName;
    MessageBuffer* buffer;
} MqttSubscriber;

/**
 * @brief A concrete port handle for MQTT.
 */
typedef struct MqttHandle {
    char* publishingTopic;
    char* subscriptionTopic;
    uint8_T numOfSubs;
    MqttSubscriber subscribers[];
} MqttHandle;

/**
 * @brief The configuration properties to setup the WiFi connection.
 */
struct WiFiConfig {
    char* ssid;
    char* pass;
    int status;
};

/**
 * @brief The configuration properties to connec to the MQTT server.
 */
struct MqttConfig {
    char* serverIPAddress;
    int serverPort;
    char* clientName;
};

/**
 * @brief Setup the communication via MQTT. Call once per ECU.
 * 
 * @details Establishes a WiFi connection and a connection to the MQTT broker.
 * For MQTT, currently only unauthenticated connections are supported. Furthermore,
 * the method assumes a SoftwareSerial connection via pins 2 and 3, and an ESP8266-01s
 * WiFi Module that it connects to.
 * 
 * @param wifiConfig the configuration for the WiFi network
 * @param mqttConfig the configuration for the MQTT connection
 */
void mqttCommunication_setup(struct WiFiConfig* const wifiConfig, 
                            struct MqttConfig* const mqttConfig);

/**
 * @brief A loop method to keep the MQTT communication alive. Call it in the loop method of an ECU
 * that makes use of MQTT communcation.
 * 
 * @param mqttConfig the configuration for the MQTT connection
 */
void mqttCommunication_loop(struct MqttConfig* const mqttConfig);

/**
 * @brief Initializes and registers an MQTT subscriber.
 * 
 * @param subscriber the pointer to the subscriber to be initialized - USERS MUST ALLOCATE MEMORY!
 * @param subscriptionTopic the topic path for the subscription
 * @param messageTypeName the message ID to subscribe to
 * @param bufferCapacity the capacity of the message buffer
 * @param messageSize the size of a message element
 * @param bufferMode false: discard new incoming message; true: replace oldest message
 */
void initAndRegisterMqttSubscriber(MqttSubscriber* const subscriber,
                                    char* const subscriptionTopic,
                                    char* const messageTypeName,
                                    size_t bufferCapacity,
                                    size_t messageSize,
                                    bool_t bufferMode);

/**
 * @brief Send a message via MQTT.
 * 
 * @param publishingTopic the topic path for publishing
 * @param messageTypeName the message type name of the message to send
 * @param message the message to be sent
 * @param messageLength the length of the message to be sent
 */
void sendMqttMessage(char* const publishingTopic,
                    char* const messageTypeName,
                    byte* const message,
                    unsigned int messageLength);
#endif /* MQTT_CUSTOM_LIB_H */
