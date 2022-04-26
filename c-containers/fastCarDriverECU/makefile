

ifndef NDDSHOME
#EXPORT THE VARIABLE NDDSHOME AND MAKE SHURE YOU HAVE A VALID RTI LICENCE. OTHERWISE PROGRAMS DO NOT RUN
NDDSHOME := "NOT SET"
endif
#TARGET_ARCH = x64Linux3.xgcc4.6.3

SYSLIBS = -ldl -lnsl -lm -lpthread -lrt
DEFINES = -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT 
#FIXME CHANGE LIB PATH IF DDS PROVIDES ANOTHER PATH
LIBS = -L$(NDDSHOME)/lib/x64Linux3gcc4.8.2/ \
        -lnddscz -lnddscorez $(SYSLIBS)
DDSSOURCES = MUML_DDSSupport.o MUML_DDSPlugin.o MUML_DDS.o 


CONT =  MCC_driveControlComponent.o MCC_distanceSensorComponent.o MCC_powerTrainComponent.o
CONT_LIB =  MessageBuffer.o LocalBufferManager.o DDS_Custom_Lib.o

RTSC = driveControlDriveControlComponentStateChart.o 
COMP = powerTrainComponent.o distanceSensorComponent.o driveControlComponent.o  
CONTMAPPING = CI_REARDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.o CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand.o CI_FRONTDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.o 
OPERATIONREPOSITORIES = 	 robotCarPowerTrainOpRep.o		
LIB =   Debug.o
CC = gcc
CFLAGS = -DC99 -DDEBUG -ggdb -Wall -c  $(DEFINES) -I types -I lib -I $(NDDSHOME)/include -I $(NDDSHOME)/include/ndds 
all: app

app : main.o $(RTSC) $(COMP) $(LIB) $(CONT_LIB) $(HYB) $(CONT) $(CONTMAPPING) $(OPERATIONREPOSITORIES)  $(DDSSOURCES)
	$(CC) main.o $(RTSC) $(COMP) $(LIB) $(CONT_LIB) $(HYB) $(CONT) $(CONTMAPPING)$(OPERATIONREPOSITORIES) $(DDSSOURCES) $(LIBS) -o app
driveControlDriveControlComponentStateChart.o: RTSCs/driveControlDriveControlComponentStateChart.c
	$(CC) $(CFLAGS) RTSCs/driveControlDriveControlComponentStateChart.c
powerTrainComponent.o: components/powerTrainComponent.c
	$(CC) $(CFLAGS) components/powerTrainComponent.c
distanceSensorComponent.o: components/distanceSensorComponent.c
	$(CC) $(CFLAGS) components/distanceSensorComponent.c
driveControlComponent.o: components/driveControlComponent.c
	$(CC) $(CFLAGS) components/driveControlComponent.c
CI_REARDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.o: APImappings/CI_REARDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.c
	$(CC) $(CFLAGS) APImappings/CI_REARDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.c
CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand.o: APImappings/CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand.c
	$(CC) $(CFLAGS) APImappings/CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand.c
CI_FRONTDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.o: APImappings/CI_FRONTDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.c
	$(CC) $(CFLAGS) APImappings/CI_FRONTDISTANCESENSORFDISTANCESENSORdistancePortaccessCommand.c


MUML_DDSSupport.o: dds/MUML_DDSSupport.c
	$(CC) $(CFLAGS) dds/MUML_DDSSupport.c
MUML_DDSPlugin.o: dds/MUML_DDSPlugin.c
	$(CC) $(CFLAGS) dds/MUML_DDSPlugin.c
MUML_DDS.o: dds/MUML_DDS.c
	$(CC) $(CFLAGS) dds/MUML_DDS.c




MessageBuffer.o: container_lib/MessageBuffer.c
	$(CC) $(CFLAGS) container_lib/MessageBuffer.c
LocalBufferManager.o: container_lib/LocalBufferManager.c
	$(CC) $(CFLAGS) container_lib/LocalBufferManager.c
DDS_Custom_Lib.o: container_lib/DDS_Custom_Lib.c
	$(CC) $(CFLAGS) container_lib/DDS_Custom_Lib.c


MCC_driveControlComponent.o: component_container/MCC_driveControlComponent.c
	$(CC) $(CFLAGS) component_container/MCC_driveControlComponent.c
MCC_distanceSensorComponent.o: component_container/MCC_distanceSensorComponent.c
	$(CC) $(CFLAGS) component_container/MCC_distanceSensorComponent.c
MCC_powerTrainComponent.o: component_container/MCC_powerTrainComponent.c
	$(CC) $(CFLAGS) component_container/MCC_powerTrainComponent.c

Debug.o: lib/Debug.c
	$(CC) $(CFLAGS) lib/Debug.c


 robotCarPowerTrainOpRep.o: operations/robotCarPowerTrainOpRep.c
	$(CC) $(CFLAGS) operations/robotCarPowerTrainOpRep.c


clean:
	rm -rf *o app
