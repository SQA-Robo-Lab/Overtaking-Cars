/**
 * @file MqttCustomLib.cpp
 * @author david
 * @brief Implementation of the library to wrap the MQTT commuication capabilities for the robot cars.
 * 
 * @details The library uses the <PubSubClient.h> for Arduino and the MessageBuffer.h from the MUML C Component Type Code generator.
 * Futhermore, it uses a SoftwareSerial connection via the DigitalIO Pins 2 and 3 of the Arduino, and expects a connection to an
 * ESP8266-01s WiFi module using the <WiFiEsp.h> library. Only then, it can successfully connect to an MQTT server to publish messages.
 */
#include "MqttCustomLib.hpp"

#include <SoftwareSerial.h>
#include <WiFiEsp.h>

#define MQTT_ESP_BAUDRADTE 9600

// #define _SS_MAX_RX_BUFF 256 // May be required for receiving larger messages via Software Serial, requires more testing


WiFiEspClient globalWifiClient;
PubSubClient globalMqttClient;
SoftwareSerial EspSerial(2,3);

/**
 * @brief A struct to store a linked list of MqttSubscribers.
 */
struct MqttSubscriberListElement {
    MqttSubscriber* subscriber;
    struct MqttSubscriberListElement *nextElement;
};

static struct MqttSubscriberListElement *mqttSubscriberList = NULL; /*init an empty list*/

/**
 * @brief Create a and mallocs a string baseTopic + messageTypeName
 * Callers MUST care about freeing the allocated memory later!
 * 
 * @param baseTopic The first part of the string
 * @param messageTypeName The second part of the string
 * @return char* the composed string
 */
static char* createAndMallocTopic(char* const baseTopic, char* const messageTypeName){
    char *temp;
    temp = (char *) malloc(strlen(baseTopic) + strlen(messageTypeName) + 1);
    strcpy(temp, baseTopic);
    strcat(temp, messageTypeName);
    return temp;
}

/**
 * @brief Connects to the MQTT broker, if there is no connection established.
 * 
 * @param mqttClientName the name to register at the broker with
 */
static void mqttConnect(char* const mqttClientName){
    while(!globalMqttClient.connected()){ 
        if (globalMqttClient.connect(mqttClientName)) {
            #ifdef DEBUG
            Serial.println("MQTT connected");
            #endif
        } else {
            #ifdef DEBUG
            Serial.println("MQTT not connected");
            #endif
            delay(1000);
        }
    }
}


/**
 * @brief Callback function for the MQTT receiver. Consumes the message and puts it into the 
 * corresponding message buffer.
 * 
 * @param topic the topic the message was received from
 * @param payload the actual message
 * @param length the length of the message
 */
static void consumeMessageIntoBuffer(char* topic, byte* payload, unsigned int length){
    #ifdef DEBUG
    Serial.print("Mqtt Message arrived [");
    Serial.print(topic);
    Serial.println("] ");
    #endif

    struct MqttSubscriberListElement **list = &mqttSubscriberList;
    MessageBuffer* bufferToFill = NULL;
    while(*list != NULL){ //iterate through the list
        MqttSubscriber* currentSubscriber = (*list)->subscriber;
        if (strcmp(topic, currentSubscriber->topic) == 0){
            bufferToFill = currentSubscriber->buffer;
            break;
        }
        list = &(*list)->nextElement;
    }
    if (bufferToFill != NULL){
        MessageBuffer_enqueue(bufferToFill, payload); //enqueing copies the payload
    }
}

static void mqttCommunication_setup(struct WiFiConfig* const wifiConfig, struct MqttConfig* const mqttConfig){
    wifiConfig->status = WL_IDLE_STATUS;
    EspSerial.begin(MQTT_ESP_BAUDRADTE);
    WiFi.init(&EspSerial);
    while(wifiConfig->status != WL_CONNECTED){
        wifiConfig->status = WiFi.begin(wifiConfig->ssid, wifiConfig->pass);
    }
    #ifdef DEBUG
    Serial.println("Connected to WiFi!");
    #endif
    delay(1000);

    globalMqttClient.setClient(globalWifiClient);
    globalMqttClient.setServer(mqttConfig->serverIPAddress, mqttConfig->serverPort);
    globalMqttClient.setCallback(consumeMessageIntoBuffer);
    globalMqttClient.setKeepAlive(20);
    
    mqttConnect(mqttConfig->clientName);
}

static void mqttCommunication_loop(struct MqttConfig* const mqttConfig){
    if (!globalMqttClient.connected()){
        mqttConnect(mqttConfig->clientName);
    }
    globalMqttClient.loop();
}

/**
 * @brief The library stores a linked list of subscribers. This method appends one subscriber to the list.
 * 
 * @param list a pointer to a list element pointer indicating the start of the list
 * @param newSubscriber the subscriber to append to the list
 */
static void appendMqttSubscriberToList(struct MqttSubscriberListElement **list,
                                        MqttSubscriber *newSubscriber){
    struct MqttSubscriberListElement *newListElement;
    while(*list != NULL){ //navigate to the end of the list
        list = &(*list)->nextElement;
    }
    newListElement = (struct MqttSubscriberListElement*) malloc(sizeof(struct MqttSubscriberListElement));
    newListElement->subscriber = newSubscriber;
    newListElement->nextElement = NULL;
    *list = newListElement; //append the new item to the list
}

void initAndRegisterMqttSubscriber(MqttSubscriber* const subscriber,
                                    char* const subscriptionTopic,
                                    char* const messageTypeName,
                                    size_t bufferCapacity,
                                    size_t messageSize,
                                    bool_t bufferMode){
    subscriber->buffer = MessageBuffer_create(bufferCapacity, messageSize, bufferMode);
    subscriber->topic = createAndMallocTopic(subscriptionTopic, messageTypeName);
    subscriber->messageTypeName = messageTypeName;
    appendMqttSubscriberToList(&mqttSubscriberList, subscriber);
    globalMqttClient.subscribe(subscriber->topic);
}

static void sendMqttMessage(char* const publishingTopic,
                            char* const messageTypeName,
                            byte* const message,
                            unsigned int messageLength){
    char *composedTopic = createAndMallocTopic(publishingTopic, messageTypeName);
    globalMqttClient.publish(composedTopic, message, messageLength);
    free(composedTopic);
}
