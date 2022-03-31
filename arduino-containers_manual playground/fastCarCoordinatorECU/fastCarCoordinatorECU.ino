#define C99

#include "Debug.h"

#include "I2cCustomLib.h"

#include "MqttCustomLib.h"
#include <WiFiEsp.h>

static struct WiFiConfig* wifiConfig;
static struct MqttConfig* mqttConfig;

#include "MCC_coordinatorComponent.h"


//variable for component Instances
CoordinatorComponent* atomic_c1;

void setup(){
	atomic_c1= MCC_create_CoordinatorComponent(CI_COMMUNICATORFCOORDINATOR);
	
	I2cCommunication_setup(1);

	//collect the data required for the WiFi configuration
	wifiConfig = (struct WiFiConfig*) malloc(sizeof(struct WiFiConfig));
	wifiConfig->ssid = "Section Control";
	wifiConfig->pass = "********";
	wifiConfig->status = WL_IDLE_STATUS;

	//collect the data required for the MQTT configuration
	mqttConfig = (struct MqttConfig*) malloc(sizeof(struct MqttConfig));
	mqttConfig->serverIPAddress = "192.168.0.100";
	mqttConfig->serverPort = 1883;
	mqttConfig->clientName = "fastCarCoordinatorECU_config";

	MqttCommunication_setup(wifiConfig, mqttConfig);

	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization done...start execution.\n");
	#endif
}

void loop(){
	MqttCommunication_loop(mqttConfig);

	CoordinatorComponent_processStep(atomic_c1);
}	


