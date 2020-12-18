#ifndef PROOFOFID_H
#define PROOFOFID_H

#include <string>
#include <iostream> 

using namespace std;

class ProofofID
{
private:
	string proofID;
public:
	ProofofID() {};
	ProofofID(string);
	string getproofID();
	void setproofID(string);
};

#endif