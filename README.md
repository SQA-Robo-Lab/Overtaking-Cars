# Overtaking-Cars

This is a MUML modeling project, providing the PIM, PDM and PSM for the scenario of cooperative overtaking of two autonomous cars.

Open the models with the MUML Tool Suite.

The repository contains the following contents:
* ```container-models``` - an exemplary MUML container model (deployment configuration model). It can be created from the roboCar.muml model using the Export -> MeachtronicUML/Container Model and Middleware Configuration using the MQTT and I2C Middleware Configuration option.
* ```model```: the actual repository content! ```roboCar.muml``` is the EMF model file. The platform modeling diagrams are in in the ```hwplatform``` and ```hwresource``` directories, the platform-independent model in the ```behavior```, ```component```, ```instance```, ```msgtype```, ```protocol``` and ```realtimestatechart``` directories. For the allocation there are two examplary allocation specifications, that are however not working (!! reason could not be found). Instead, the desired allocation was created manually in the roboCar.muml file, and the allocation table was created as a demonstration (```SystemAllocationOffastAndSlowCar_v2.tex```). There is also an exemplare ApiML specification (.osdsl), but a working ApiMappingML file could not be created.
* The above models were used to create the ```arduino-containers_demo```. All details are in this directory's [readme](./arduino-containers_demo/README.md).
