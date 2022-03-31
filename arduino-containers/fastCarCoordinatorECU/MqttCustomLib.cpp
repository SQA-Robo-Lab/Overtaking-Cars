#include "MqttCustomLib.h"

#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <WiFiEsp.h>

#define MQTT_ESP_BAUDRADTE 9600

static WiFiEspClient globalWifiClient;
static PubSubClient globalMqttClient;

struct MqttSubscriberListElement {
    MqttSubscriber* subscriber;
    struct MqttSubscriberListElement *nextElement;
};

static struct MqttSubscriberListElement *mqttSubscriberList = NULL; /*init an empty list*/

static void MqttCommunication_setup(struct WiFiConfig *wifiConfig, 
                            struct MqttConfig *mqttConfig){
    SoftwareSerial EspSerial(2,3);
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

    globalMqttClient.setKeepAlive(10);
    globalMqttClient.setCallback(consumeMessageIntoBuffer);
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
        char temp[8];
        itoa(currentSubscriber->messageId, temp, 10);
        if (strcmp(topic, strcat(currentSubscriber->subscriptionTopic, temp)) == 0){
            bufferToFill = currentSubscriber->buffer;
            break;
        }
        list = &(*list)->nextElement;
    }
    if (bufferToFill != NULL){
        //TODO: think about unmarshalling
        MessageBuffer_enqueue(bufferToFill, payload);
    }
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

static void MqttCommunication_loop(struct MqttConfig *mqttConfig){
    if (!globalMqttClient.connected()){
        mqttConnect(mqttConfig->clientName);
    }
    globalMqttClient.loop();
}

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
                                    uint16_T messageId,
                                    size_t bufferCapacity,
                                    size_t messageSize,
                                    bool_t bufferMode){
    subscriber->buffer = MessageBuffer_create(bufferCapacity, messageSize, bufferMode);
    subscriber->messageId = messageId;
    subscriber->subscriptionTopic = subscriptionTopic;
    char temp[8];
    itoa(messageId, temp, 10);
    globalMqttClient.subscribe(strcat(subscriptionTopic, temp));
}

static void sendMqttMessage(char* publishingTopic,
                            uint16_T messageId,
                            void* message){
    char temp[8];
    itoa(messageId, temp, 10);
    //TODO: marshalling of message
    globalMqttClient.publish(strcat(publishingTopic, temp), "test");
}