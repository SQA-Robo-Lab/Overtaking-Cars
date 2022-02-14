//general includes
#include "MiddlewareCore.h"
#include "Debug.h"
//including all files for used Components
#include "coordinatorComponent_Interface.h"
#include "driveControlComponent_Interface.h"
#include "coordinatorCoordinatorComponentStateChart.h"
#include "driveControlDriveControlComponentStateChart.h"

//variables for component instances

Middleware* mw;

void setup(){
  Serial.begin(9600);

//create and  initialize middleware object
 Middleware_create();
			MessageID * messageIDsOfbufferOfdriveControlComponent;
					//create instance driveControl of type DriveControlComponent
					 mw->driveControlComponent = DriveControlComponent_create();
								messageIDsOfbufferOfdriveControlComponent = (MessageID*) calloc(2,sizeof(MessageID));
									messageIDsOfbufferOfdriveControlComponent[0] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE;
									messageIDsOfbufferOfdriveControlComponent[1] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE;
								MessageBuffer* driveControlMessageBuffercommunicator1driveControl = MessageBuffer_create(5,false,2,messageIDsOfbufferOfdriveControlComponent);
			
							MessageBuffer** allBuffersOfdriveControldriveControl = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfdriveControldriveControl[0] = driveControlMessageBuffercommunicator1driveControl;
				
							mw->driveControlComponent->driveControlPort = Port_create(PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1, 1, allBuffersOfdriveControldriveControl);
						
					//create behavior for component driveControlComponent
					mw->driveControlComponent->stateChart = DriveControlDriveControlComponentStateChart_create(mw->driveControlComponent);
			
			MessageID * messageIDsOfbufferOfcommunicatorComponent;
					//create instance communicator of type CoordinatorComponent
					 mw->communicatorComponent = CoordinatorComponent_create();
								messageIDsOfbufferOfcommunicatorComponent = (MessageID*) calloc(2,sizeof(MessageID));
									messageIDsOfbufferOfcommunicatorComponent[0] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE;
									messageIDsOfbufferOfcommunicatorComponent[1] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE;
								MessageBuffer* commmunicatorMessageBufferdriveControl1communicator = MessageBuffer_create(5,false,2,messageIDsOfbufferOfcommunicatorComponent);
			
							MessageBuffer** allBuffersOfcommunicatorcommunicator = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfcommunicatorcommunicator[0] = commmunicatorMessageBufferdriveControl1communicator;
				
							mw->communicatorComponent->communicatorPort = Port_create(PORT_COMMUNICATORCOORDINATORDRIVECONTROL1, 1, allBuffersOfcommunicatorcommunicator);
						
								messageIDsOfbufferOfcommunicatorComponent = (MessageID*) calloc(1,sizeof(MessageID));
									messageIDsOfbufferOfcommunicatorComponent[0] = MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE;
								MessageBuffer* initiatorMessageBuffercarCoordinator1communicator = MessageBuffer_create(1,false,1,messageIDsOfbufferOfcommunicatorComponent);
			
							MessageBuffer** allBuffersOfcommunicatorovertakingInitiator = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfcommunicatorovertakingInitiator[0] = initiatorMessageBuffercarCoordinator1communicator;
				
							mw->communicatorComponent->overtakingInitiatorPort = Port_create(PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1, 1, allBuffersOfcommunicatorovertakingInitiator);
						
								messageIDsOfbufferOfcommunicatorComponent = (MessageID*) calloc(2,sizeof(MessageID));
									messageIDsOfbufferOfcommunicatorComponent[0] = MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE;
									messageIDsOfbufferOfcommunicatorComponent[1] = MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE;
								MessageBuffer* affiliateMessageBufferovertakingAffiliate1communicator = MessageBuffer_create(5,false,2,messageIDsOfbufferOfcommunicatorComponent);
			
							MessageBuffer** allBuffersOfcommunicatorovertakingAffiliate = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfcommunicatorovertakingAffiliate[0] = affiliateMessageBufferovertakingAffiliate1communicator;
				
							mw->communicatorComponent->overtakingAffiliatePort = Port_create(PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1, 1, allBuffersOfcommunicatorovertakingAffiliate);
						
					//create behavior for component communicatorComponent
					mw->communicatorComponent->stateChart = CoordinatorCoordinatorComponentStateChart_create(mw->communicatorComponent);
			
			MessageID * messageIDsOfbufferOfdriveControlComponent;
					//create instance driveControl of type DriveControlComponent
					 mw->driveControlComponent = DriveControlComponent_create();
								messageIDsOfbufferOfdriveControlComponent = (MessageID*) calloc(2,sizeof(MessageID));
									messageIDsOfbufferOfdriveControlComponent[0] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESGRANTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE;
									messageIDsOfbufferOfdriveControlComponent[1] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESDENYPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE;
								MessageBuffer* driveControlMessageBuffercommunicator1driveControl = MessageBuffer_create(5,false,2,messageIDsOfbufferOfdriveControlComponent);
			
							MessageBuffer** allBuffersOfdriveControldriveControl = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfdriveControldriveControl[0] = driveControlMessageBuffercommunicator1driveControl;
				
							mw->driveControlComponent->driveControlPort = Port_create(PORT_DRIVECONTROLDRIVECONTROLCOMMUNICATOR1, 1, allBuffersOfdriveControldriveControl);
						
					//create behavior for component driveControlComponent
					mw->driveControlComponent->stateChart = DriveControlDriveControlComponentStateChart_create(mw->driveControlComponent);
			
			MessageID * messageIDsOfbufferOfcommunicatorComponent;
					//create instance communicator of type CoordinatorComponent
					 mw->communicatorComponent = CoordinatorComponent_create();
								messageIDsOfbufferOfcommunicatorComponent = (MessageID*) calloc(1,sizeof(MessageID));
									messageIDsOfbufferOfcommunicatorComponent[0] = MESSAGE_OVERTAKINGCOORDINATIONMESSAGESACCEPTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE;
								MessageBuffer* initiatorMessageBuffercarCoordinator1communicator = MessageBuffer_create(1,false,1,messageIDsOfbufferOfcommunicatorComponent);
			
							MessageBuffer** allBuffersOfcommunicatorovertakingInitiator = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfcommunicatorovertakingInitiator[0] = initiatorMessageBuffercarCoordinator1communicator;
				
							mw->communicatorComponent->overtakingInitiatorPort = Port_create(PORT_COMMUNICATORCOORDINATORCARCOORDINATOR1, 1, allBuffersOfcommunicatorovertakingInitiator);
						
								messageIDsOfbufferOfcommunicatorComponent = (MessageID*) calloc(2,sizeof(MessageID));
									messageIDsOfbufferOfcommunicatorComponent[0] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESREQUESTPERMISSIONOVERTAKINGPERMISSIONMESSAGESMESSAGE;
									messageIDsOfbufferOfcommunicatorComponent[1] = MESSAGE_OVERTAKINGPERMISSIONMESSAGESEXECUTEDOVERTAKINGOVERTAKINGPERMISSIONMESSAGESMESSAGE;
								MessageBuffer* commmunicatorMessageBufferdriveControl1communicator = MessageBuffer_create(5,false,2,messageIDsOfbufferOfcommunicatorComponent);
			
							MessageBuffer** allBuffersOfcommunicatorcommunicator = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfcommunicatorcommunicator[0] = commmunicatorMessageBufferdriveControl1communicator;
				
							mw->communicatorComponent->communicatorPort = Port_create(PORT_COMMUNICATORCOORDINATORDRIVECONTROL1, 1, allBuffersOfcommunicatorcommunicator);
						
								messageIDsOfbufferOfcommunicatorComponent = (MessageID*) calloc(2,sizeof(MessageID));
									messageIDsOfbufferOfcommunicatorComponent[0] = MESSAGE_OVERTAKINGCOORDINATIONMESSAGESREQUESTOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE;
									messageIDsOfbufferOfcommunicatorComponent[1] = MESSAGE_OVERTAKINGCOORDINATIONMESSAGESFINISHEDOVERTAKINGOVERTAKINGCOORDINATIONMESSAGESMESSAGE;
								MessageBuffer* affiliateMessageBufferovertakingAffiliate1communicator = MessageBuffer_create(5,false,2,messageIDsOfbufferOfcommunicatorComponent);
			
							MessageBuffer** allBuffersOfcommunicatorovertakingAffiliate = (MessageBuffer**) malloc(1*sizeof(MessageBuffer*));
							allBuffersOfcommunicatorovertakingAffiliate[0] = affiliateMessageBufferovertakingAffiliate1communicator;
				
							mw->communicatorComponent->overtakingAffiliatePort = Port_create(PORT_COMMUNICATORCOORDINATOROVERTAKINGAFFILIATE1, 1, allBuffersOfcommunicatorovertakingAffiliate);
						
					//create behavior for component communicatorComponent
					mw->communicatorComponent->stateChart = CoordinatorCoordinatorComponentStateChart_create(mw->communicatorComponent);
			

					mw->driveControlComponent->getterOf_distance =  read_distance_ofdistanceSensorComponent_distanceSensor;
					mw->driveControlComponent->getterOf_distance =  read_distance_ofdistanceSensorComponent_distanceSensor;
#ifdef DEBUG
printDebugInformation("Initialization done...start execution.\n");
#endif
}

void loop(){

			DriveControlComponent_processStep(mw->driveControlComponent);
			CoordinatorComponent_processStep(mw->communicatorComponent);
			DriveControlComponent_processStep(mw->driveControlComponent);
			CoordinatorComponent_processStep(mw->communicatorComponent);

}
