# Overtaking-Cars

This is a MUML modeling project, providing the PIM, PDM and PSM for the scenario of cooperative overtaking of two autonomous cars.

Open the models with the MUML Tool Suite.

The repository contains the following contents:
* ```arduino-containers_manual playground```: to be ignored/deleted - just for manual testing
* ```componentType``` - the component type code that was generated using the Export -> Source Code -> ANSI C99 Component Type option
* ```container-models``` - an exemplary MUML container model (deployment configuration model)
* ```model```: the actual repository content! ```roboCar.muml``` is the EMF model file. The platform modeling diagrams are in in the ```hwplatform``` and ```hwresource``` directories, the platform-independent model in the ```behavior```, ```component```, ```instance```, ```msgtype```, ```protocol``` and ```realtimestatechart``` directories. For the allocation there are two examplary allocation specifications, that are however not working (!! reason could not be found). Instead, the desired allocation was created manually in the roboCar.muml file, and the allocation table was created as a demonstration (```SystemAllocationOffastAndSlowCar_v2.tex```). 
