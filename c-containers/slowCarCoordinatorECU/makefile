

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


CONT =  MCC_coordinatorComponent.o
CONT_LIB =  MessageBuffer.o LocalBufferManager.o DDS_Custom_Lib.o

RTSC = coordinatorCoordinatorComponentStateChart.o 
COMP = coordinatorComponent.o  
CONTMAPPING = 
OPERATIONREPOSITORIES = 		
LIB =   Debug.o
CC = gcc
CFLAGS = -DC99 -DDEBUG -ggdb -Wall -c  $(DEFINES) -I types -I lib -I $(NDDSHOME)/include -I $(NDDSHOME)/include/ndds 
all: app

app : main.o $(RTSC) $(COMP) $(LIB) $(CONT_LIB) $(HYB) $(CONT) $(CONTMAPPING)   $(DDSSOURCES)
	$(CC) main.o $(RTSC) $(COMP) $(LIB) $(CONT_LIB) $(HYB) $(CONT) $(CONTMAPPING) $(DDSSOURCES) $(LIBS) -o app
coordinatorCoordinatorComponentStateChart.o: RTSCs/coordinatorCoordinatorComponentStateChart.c
	$(CC) $(CFLAGS) RTSCs/coordinatorCoordinatorComponentStateChart.c
coordinatorComponent.o: components/coordinatorComponent.c
	$(CC) $(CFLAGS) components/coordinatorComponent.c


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


MCC_coordinatorComponent.o: component_container/MCC_coordinatorComponent.c
	$(CC) $(CFLAGS) component_container/MCC_coordinatorComponent.c

Debug.o: lib/Debug.c
	$(CC) $(CFLAGS) lib/Debug.c




clean:
	rm -rf *o app
