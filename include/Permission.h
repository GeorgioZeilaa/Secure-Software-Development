#ifndef PERMISSION_H
#define PERMISSION_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum AccessType {
	NA = 0x00,
	CO = 0x01,
	E = 0x02,
	W = 0x04,
	R = 0x08,
	FA = 0x10
};
enum Roles
{
	Administrator,
	User
};

class Permission {
private:
	typedef vector<unsigned> resources;
	map< unsigned, resources> userResourceAccessMap;
public:
	Permission();
	bool checkPermission(unsigned resourceID, unsigned role, unsigned accessType);
};
#endif