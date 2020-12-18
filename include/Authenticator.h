#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "AuthenticationInfo.h" 
#include "Subject.h" 
#include "ProofofID.h"

//Authenticator class 
class Authenticator
{
public:
	Authenticator(); // constructor initializes data members
	ProofofID* authenticateUser(Subject &s); // attempts to authenticate user
	uint16_t permissionAuth = 3;
private:
	string encryptDecrypt(string toEncrypt);
}; 

#endif // AUTHENTICATOR_H