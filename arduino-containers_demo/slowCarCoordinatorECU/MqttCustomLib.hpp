#ifndef MQTT_CUSTOM_LIB_H
#define MQTT_CUSTOM_LIB_H

#include "ContainerTypes.h"
#include <PubSubClient.h>

typedef struct MqttSubscriber {
    char* topic;
    char* messageTypeName;
    MessageBuffer* buffer;
} MqttSubscriber;


typedef struct MqttHandle {
    char* publishingTopic;
    char* subscriptionTopic;
    uint8_T numOfSubs;
    MqttSubscriber subscribers[];
} MqttHandle;

struct WiFiConfig {
    char* ssid;
    char* pass;
    int status;
};

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
void mqttCommunication_setup(struct WiFiConfig *wifiConfig, 
                            struct MqttConfig *mqttConfig);

/**
 * @brief A loop method to keep the MQTT communication alive. Call in the loop method of an ECU
 * that makes use of MQTT communcation.
 * 
 * @param mqttConfig the configuration for the MQTT connection
 */
void mqttCommunication_loop(struct MqttConfig *mqttConfig);

/**
 * @brief Create and Register an MQTT subscriber
 * 
 * @param subscriber the pointer to the subscriber to be created
 * @param subscriptionTopic the topic path for the subscription
 * @param messageTypeName the message ID so subscribe to
 * @param bufferCapacity the capacity of the message buffer
 * @param messageSize the size of a message element
 * @param bufferMode false: discard new incoming message; true: replace oldest message
 */
void createAndRegisterMqttSubscriber(MqttSubscriber* subscriber,
                                    char* subscriptionTopic,
                                    char* messageTypeName,
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
void sendMqttMessage(char* publishingTopic,
                    char* messageTypeName,
                    byte* message,
                    unsigned int messageLength);
#endif /* MQTT_CUSTOM_LIB_H */
