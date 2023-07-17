#include "CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand.h"
void CI_POWERTRAINFPOWERTRAINvelocityPortaccessCommand(int32_T* velocity){
	// Start of user code API
	//*velocity = fastCarDriverController.getDriveController()->getSpeed();
  *velocity = getCurrentSpeed();
	// End of user code
}
