#include "MqttCustomLib.hpp"

#include <SoftwareSerial.h>
#include <WiFiEsp.h>

#define MQTT_ESP_BAUDRADTE 9600

// #define _SS_MAX_RX_BUFF 256 // May be required for receiving larger messages via Software Serial


static WiFiEspClient globalWifiClient;
static PubSubClient globalMqttClient;
SoftwareSerial EspSerial(2,3);

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
static char* createAndMallocTopic(char* baseTopic, char* messageTypeName){
    char *temp;
    temp = (char *) malloc(strlen(baseTopic) + strlen(messageTypeName));
    strcpy(temp, baseTopic);
    strcat(temp, messageTypeName);
    return temp;
}

/**
 * @brief Connects to the MQTT broker, if there is no connection established.
 * 
 * @param mqttClientName the name to register at the broker with
 */
static void mqttConnect(char* mqttClientName){
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
    Serial.print("] ");
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
        MessageBuffer_enqueue(bufferToFill, payload);
    }
}

static void MqttCommunication_setup(struct WiFiConfig *wifiConfig, struct MqttConfig *mqttConfig){
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
    
    mqttConnect(mqttConfig->clientName);

    globalMqttClient.setKeepAlive(20);
    globalMqttClient.setCallback(consumeMessageIntoBuffer);
}

static void MqttCommunication_loop(struct MqttConfig *mqttConfig){
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

void createAndRegisterMqttSubscriber(MqttSubscriber* subscriber,
                                    char* subscriptionTopic,
                                    char* messageTypeName,
                                    size_t bufferCapacity,
                                    size_t messageSize,
                                    bool_t bufferMode){
    subscriber->buffer = MessageBuffer_create(bufferCapacity, messageSize, bufferMode);
    subscriber->topic = createAndMallocTopic(subscriptionTopic, messageTypeName);
    appendMqttSubscriberToList(&mqttSubscriberList, subscriber);
    globalMqttClient.subscribe(subscriber->topic);
}

static void sendMqttMessage(char* publishingTopic,
                            char* messageTypeName,
                            byte* message,
                            unsigned int messageLength){
    char *composedTopic = createAndMallocTopic(publishingTopic, messageTypeName);
    globalMqttClient.publish(composedTopic, message, messageLength);
    free(composedTopic);
}
