#include "AuthenticationInfo.h" 
#include "Authenticator.h"
#include "Subject.h"
#include <iostream> 

using namespace std;

AuthenticationInfo::AuthenticationInfo()
{
	loginsvector.clear();//clears the vector

	inputfile.open("Login.data");
	string UserID;
	Login loginclass;//to get access to set and get for login details including permission level for role based access

	if (inputfile.fail())//just in case it fails to load the login.data file for login details
	{
		cout << "could not open file to login!" << endl;
	}
	else
	{
		cout << "checking username and password!" << endl;
		
		while (getline(inputfile, UserID))//gets the first row of every user detail as ID which is unique to every user in login.data
		{
			string username;
			string password;
			string permissionlevel;
			//adds the data into the vector
			getline(inputfile, username);
			getline(inputfile, password);
			getline(inputfile, permissionlevel);
			loginclass.setusername(username);
			loginclass.setpassword(password);
			loginclass.setpermissionlevel(permissionlevel);

			loginsvector.push_back(loginclass);//saves the data in the vector
		}
	}
	inputfile.close();
};

bool AuthenticationInfo::validateUser(string name, string pass) 
{
	bool validUser = false;
	for (uint16_t i = 0; i < loginsvector.size(); i++)//loops through the vector according to its data
	{
		if (name == loginsvector[i].getusername())//compares username input and username in vector that was gathered from login.data
		{
			if (pass == loginsvector[i].getpassword())//the same for password like username
			{
				permissionAuthInfo = stoi(loginsvector[i].getpermissionlevel());//saves the permission level of that specific user if the username and password match
				validUser = true;//returns true if authenticated
			}
		}
	}
	return validUser;
}