#ifndef RESOURCE_H
#define RESOURCE_H

#include "Permission.h"

using namespace std;

class Resource {
private:
	unsigned id;
	string secret;
	Resource(unsigned a) : id(a) {
		secret = "bla bla bla";
	}
public:
	static Resource* newResource(unsigned resourceID, unsigned role, unsigned accessType);
	unsigned getId();
	string getSecret();
};

#endif