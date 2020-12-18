#include "resourceFactory.h"

Resource* resourceFactory::accessResource(unsigned resourceID, unsigned role, unsigned accessType)
{
	return Resource::newResource(resourceID, role, accessType);
}