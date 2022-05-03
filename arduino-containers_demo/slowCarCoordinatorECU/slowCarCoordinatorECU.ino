
#include "Debug.h"

#include "I2cCustomLib.hpp"

#include "MqttCustomLib.hpp"
#include <WiFiEsp.h>

static struct MqttConfig* mqttConfig;

#include "MCC_coordinatorComponent.h"

// Start of user code DEVICEINITINCLUDES
#// End of user code


//variable for component Instances
CoordinatorComponent* atomic_c1;

void setup(){
	#ifdef DEBUG
	Serial.begin(9600);
	Serial.println("Initialization starting...");
	#endif
	// Start of user code DEVICEINIT
	/* TODO: if devices are used which need an initialization, call the functionse here */
	// End of user code
	atomic_c1= MCC_create_CoordinatorComponent(CI_COMMUNICATORSCOORDINATOR);
	
	i2cCommunication_setup(2);

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

	mqttCommunication_setup(&wifiConfig, mqttConfig);

	#ifdef DEBUG
	Serial.println("Initialization done...start execution.");
	#endif
}

void loop(){
	mqttCommunication_loop(mqttConfig);

	CoordinatorComponent_processStep(atomic_c1);
}	



