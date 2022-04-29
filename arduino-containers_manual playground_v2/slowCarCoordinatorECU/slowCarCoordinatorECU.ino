#define C99

#include "Debug.h"

#include "I2cCustomLib.hpp"

#include "MqttCustomLib.hpp"
#include <WiFiEsp.h>

static struct MqttConfig* mqttConfig;

#include "MCC_coordinatorComponent.h"


//variable for component Instances
CoordinatorComponent* atomic_c1;

void setup(){
	atomic_c1= MCC_create_CoordinatorComponent(CI_COMMUNICATORSCOORDINATOR);
	
	I2cCommunication_setup(2);

	//collect the data required for the WiFi configuration
	struct WiFiConfig wifiConfig = {
		"Section Control",
		"********",
		WL_IDLE_STATUS
	};

	//collect the data required for the MQTT configuration
	struct MqttConfig mConf = {
		"192.168.0.100",
		1883,
		"slowCarCoordinatorECU_config"
	};
	mqttConfig = &mConf;

	MqttCommunication_setup(&wifiConfig, mqttConfig);

	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization done...start execution.\n");
	#endif
}

void loop(){
	MqttCommunication_loop(mqttConfig);

	CoordinatorComponent_processStep(atomic_c1);
}	



