# Code generation from MechatronicUML using MQTT and I2C for Arduino

This directory contains the generated platform-specific container code. Per ECU, you find one directory with an .ino-file.

The following things are required to get a fully working implementation:
* You need to generate or implement the platform-independent component code (the functional implementation) using the Generate Component Type Code functionality in the MechatronicUML Tool Suite, see https://github.com/SQA-Robo-Lab/MUML-CodeGen-Wiki/tree/main/user-documentation.
* For MQTT communication, you require an MQTT server. Currently, it is expected to be accessible at 192.168.0.100:1883 (see org.muml.psm.container.transformation). If you can make your local machine available at the given IP address, you can simply us the Docker configuration we generated for you to quickly start-up your MQTT server :-) use ```docker-compose up```! You find the configuration files in the mosquitto/ directory.
					
					
					
					
* For MQTT communication, you also require a WiFi connection using the ESP8266-01s WiFi Module. See more information in the MqttCustomLib.hpp in the respective ECU's directory.
* For I2C communication, the Arduino is expected to be using its I2C pins. See more information in the I2cCustomLib.hpp in the respective ECU's directory.
