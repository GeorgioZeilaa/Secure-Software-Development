#include "Resource.h"

Resource* Resource::newResource(unsigned resourceID, unsigned role, unsigned accessType) {
	Permission p = Permission();
	if (p.checkPermission(resourceID, role, accessType)) //if the permissions are met in the matrix table then full access message will be shown
	{
		cout << "Full Access Granted\n";
		return new Resource(resourceID);
	}
	else {
		cout << "Minimal Access Level\n";
		return nullptr;
	}
}

unsigned Resource::getId() { return id; };

string Resource::getSecret() { return secret; };