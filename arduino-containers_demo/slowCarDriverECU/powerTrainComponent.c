// Standard library

#include "powerTrainComponent_Interface.h"

void PowerTrainComponent_initialize(PowerTrainComponent *component)
{

	/*Initialize all DirectedTypedPorts*/
	Clock_reset(component->velocityPortClock);
}

PowerTrainComponent PowerTrainComponent_create(void)
{

	PowerTrainComponent component;

	return component;
}

void PowerTrainComponent_destroy(PowerTrainComponent *component)
{
	if (component != NULL)
	{

		// suicide
		free(component);
	}
}

void PowerTrainComponent_processStep(PowerTrainComponent *component)
{

	/*Receive Messages for Continuous In Ports*/
	{
		/*FIXME Currently a Continuous Port has no update interval. We set a fixed interval of 1ms.  An interval has to be defined in the model in the future.*/
		int localTimeInterval = 1;
		if (Clock_getTime(component->velocityPortClock) >= localTimeInterval * 1) // interval of continuous port
		{
			bool_T changed = false;
			changed = getterOf_velocity(&component->velocityPort, &component->velocity);
			Clock_reset(component->velocityPortClock);
			if (changed)
			{
				component->velocityPortAccessFunction(&component->velocity);
			}
		}
	}
}

bool_T getterOf_velocity(Port *velocityPort, int32_T *velocity)
{
	if (MCC_PowerTrainComponent_velocity_exists_value(velocityPort))
	{
		MCC_PowerTrainComponent_velocity_recv_value(velocityPort, velocity);
		return true;
	}
	else
		return false;
}
