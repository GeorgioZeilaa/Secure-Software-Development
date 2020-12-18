#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include "Resource.h"

class resourceFactory {
public:
	Resource* accessResource(unsigned resourceID, unsigned role, unsigned accessType);
};

#endif