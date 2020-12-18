#include "Subject.h" 
#include "resourceFactory.h"

using namespace std;

Subject::Subject() {
	cout << "\nEnter UserID :";
	cin >> id;
	cout << "\nEnter password :";
	cin >> password;
	proofID = "";
}

unsigned Subject::getunId() { return unid; };
string Subject::getId() { return id; };
string Subject::getPassword() { return password; };

void Subject::setproofofID(string proof) {
	proofID = proof;
};

string Subject::getproofofID() {
	return proofID;
}

Resource* Subject::getResource(unsigned resourceID, unsigned accessType)
{
	resourceFactory* rf = new resourceFactory();
	r = rf->accessResource(resourceID, role.getRoleName(), accessType);
	delete rf;//deletes the pointer that was created so no memory learks occur
	return r;//returns the pointer data that was set
}