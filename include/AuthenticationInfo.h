#ifndef AUTH_INFO_H
#define AUTH_INFO_H


#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "Login.h"

using namespace std;

class AuthenticationInfo
{
private:
	ifstream inputfile;
	vector<Login> loginsvector;
public:
	AuthenticationInfo(); // constructor sets attributes 
	bool validateUser(string name, string password);
	uint16_t permissionAuthInfo = 3;
};

#endif // AUTH_INFO_H