#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <iostream> 
#include "Resource.h"
#include "Role.h"

using namespace std;

class Subject {
private:
	string id;
	string password;
	string proofID;
	unsigned unid;
	Resource* r;
	Role role;
public:
	//Subject(string a, string pass);
	Subject();
	string getPassword();
	void setproofofID(string proof);
	string getproofofID();


	Subject(unsigned aid) :unid(aid) {
		role.setRoleName(aid);
		cout << "Subject created!" << endl;
	}
	unsigned getunId();
	string getId();
	Role getRole() { return role; };
	Resource* getResource(unsigned resourceID, unsigned accessType);
};

#endif // SUBJECT_H


