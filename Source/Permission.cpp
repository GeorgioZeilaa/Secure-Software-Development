#include "Permission.h"

Permission::Permission() //this is the matrix table for permissions level to be set
{
	userResourceAccessMap[Administrator] = { FA,	 FA,	FA };
	userResourceAccessMap[User] = { E | W,	 E | W | R,	E | W | R };
}

bool Permission::checkPermission(unsigned resourceID, unsigned role, unsigned accessType) 
{
	if (userResourceAccessMap[role].at(resourceID)&accessType) 
	{
		return true;
	}
	else return false;
}