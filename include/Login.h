#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>


using namespace std;

class Login
{
private:
	string username;
	string password;
	string permissionlevel;
public:
	string getusername(void);
	string getpassword(void);
	string getpermissionlevel(void);
	void setusername(string username);
	void setpassword(string password);
	void setpermissionlevel(string permissionlevel);
	uint16_t check();
	uint16_t checkauthorisation();
	uint16_t permissionlevellogin = 3;
};

#endif