#ifndef ROLE_H
#define ROLE_H

#include "Permission.h"

class Role
{
	unsigned roleName;
	map<unsigned, unsigned> userRoleAccessMap;
public:
	Role() {
		userRoleAccessMap[0] = Administrator;
		userRoleAccessMap[1] = User;
		userRoleAccessMap[2] = User;
	}
	unsigned getRoleName() {
		return roleName;
	}
	void setRoleName(unsigned subjectID) {
		roleName = userRoleAccessMap[subjectID];
	}
};

#endif