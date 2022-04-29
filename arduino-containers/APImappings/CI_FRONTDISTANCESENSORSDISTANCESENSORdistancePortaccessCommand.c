#include "CI_FRONTDISTANCESENSORSDISTANCESENSORdistancePortaccessCommand.h"
void CI_FRONTDISTANCESENSORSDISTANCESENSORdistancePortaccessCommand(int32_T* distance){
	// Start of user code API
	*distance = getFrontDistance();
	// End of user code
}
