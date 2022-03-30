#include "lib/Debug.h"

#include "container_lib/I2cCustomLib.h"

#include "container_lib/MqttCustomLib.h"

static struct WiFiConfig* wifiConfig;
static struct MqttConfig* mqttConfig;

#include "component_container/MCC_coordinatorComponent.h"


//variable for component Instances
CoordinatorComponent* atomic_c1;

int setup(){
	atomic_c1= MCC_create_CoordinatorComponent(CI_COMMUNICATORSCOORDINATOR);
	
	I2cCommunication_setup(2);

	//collect the data required for the WiFi configuration
	wifiConfig = malloc(sizeof(struct WiFiConfig));
	wifiConfig->ssid = "Section Control";
	wifiConfig->pass = "********";
	wifiConfig->status = WL_IDLE_STATUS;

	//collect the data required for the MQTT configuration
	mqttConfig = malloc(sizeof(struct MqttConfig));
	mqttConfig->serverIPAddress = "192.168.0.100";
	mqttConfig->serverPort = 1883;
	mqttConfig->clientName = "slowCarCoordinatorECU_config";

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



