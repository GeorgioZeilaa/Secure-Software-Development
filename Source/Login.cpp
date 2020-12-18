#include "Login.h"

#include "Subject.h"
#include "ProofofID.h"
#include "Authenticator.h"

//get and set for user details, this is login purposes
string Login::getpassword()
{
	return password;
}

string Login::getusername()
{
	return username;
}

void Login::setusername(string username)
{
	this->username = username;
}

void Login::setpassword(string password)
{
	this->password = password;
}

void Login::setpermissionlevel(string permissionlevel)
{
	this->permissionlevel = permissionlevel;
}

string Login::getpermissionlevel()
{
	return permissionlevel;
}

uint16_t Login::check()//runs an authentication
{
	Subject s;
	Authenticator a;
	ProofofID* proofofID = a.authenticateUser(s);
	if (proofofID != nullptr)
	{
		cout << "subject proof of id " << s.getproofofID() << endl;
		cout << "systems proof of id " << proofofID->getproofID() << endl;
		cout << "Permissions level: " << a.permissionAuth << endl;
		permissionlevellogin = a.permissionAuth;
		return 1;
	}
	return 0;
}
uint16_t Login::checkauthorisation()//runs an authorisation
{
	uint16_t subjectID = permissionlevellogin;
	uint16_t resourceID = 0;//first column used for simplicity in the matrix table for permissions
	uint16_t accessType = FA;//checks if the user is an actual admin, if not then it will not authorise the user to view everything, for now its only admin FA

	Subject* s = new Subject(subjectID);
	Resource* r = s->getResource(resourceID, accessType);

	if (r != nullptr)
	{
		return 1;//returns 1 if user authorised
	}

	return 0;//returns 0 if user not authorised for his access level
	system("pause");
}