#include "Authenticator.h" 

using namespace std;

Authenticator::Authenticator(){ };

ProofofID* Authenticator::authenticateUser(Subject &s)
{
	AuthenticationInfo ainfo;//gathered data for login purposes
	ProofofID* proofofID = nullptr;//default proofofid is null until logged in successfully
	string Id = s.getId();
	string pass = s.getPassword();
	string token = "";//token for proof of id, this is for further authentication
	bool authenticated = false;
	if (ainfo.validateUser(Id, pass))	//this validated so username and password match the inputs then it will be true and generate a unique token
	{
			cout << "\nWelcome!";
			cout << "\nAuthenticated!\n";
			token = encryptDecrypt(Id = pass);
			proofofID = new ProofofID(token);
			permissionAuth = ainfo.permissionAuthInfo;
			system("pause");//pause after login

	}
	else
	{
		cout << "Invalid user ID or password. Please try again.";
		system("pause");
	}
	return proofofID;

}; // end function authenticateUser

string Authenticator::encryptDecrypt(string toEncrypt)
{
	char key = 'A';//any char key will work
	string output = toEncrypt;
	for (uint16_t i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;
		return output;//returns the generated key
		return output;//returns the generated key
	}
}