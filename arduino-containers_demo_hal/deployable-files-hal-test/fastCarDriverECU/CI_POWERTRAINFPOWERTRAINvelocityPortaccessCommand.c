#include "CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand.h"
#include <SimpleHardwareController_Connector.h>
void CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand(int32_T* velocity){
	// Start of user code API
	//*velocity = fastCarDriverController.getDriveController()->getSpeed();
  *velocity = SimpleHardwareController_DriveController_GetSpeed();
	// End of user code
}
