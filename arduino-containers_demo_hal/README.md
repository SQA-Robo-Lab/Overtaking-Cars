# Arduino Containers Demo HAL

The purpose of this directory is to demonstrate the implementation of a cooperative overtaking scenario using the MechatronicUML Tool Suite and the code generation features of the extended platform-modeling approach, using the new Hardware Abstraction Library (HAL).

The code of the HAL can be found in https://github.com/SQA-Robo-Lab/Sofdcar-HAL

The target platform are the robot cars described in https://github.com/SQA-Robo-Lab/Arduino-Car

For additional documentation, consult https://github.com/SQA-Robo-Lab/MUML-CodeGen-Wiki. 

The subdirectories contain the following:
* ```generated-files```: generated code as produced by the code generator, including the intermediate ```MUML_Container.muml_container``` model
* ```deployable-files```: The rearranged generated code with the required manual adaptions

## Build, Deployment, Testing

The code in the ```deployable-files``` directory can be successfully built using the Arduino tools (```verify```).

Using the ```upload``` function of the Arduino environment, the code can be deployed on the robot car. The ```...DeriverECU``` to the respective Arduino Mega, and the ```...CoordinatorECU``` to the respective car's Arduino Nano.