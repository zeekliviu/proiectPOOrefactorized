#pragma once
#include <iostream>
using namespace std;
class Bilet
{
private:
	char* numeClient;
	static unsigned int nrBilete;
	unsigned int id;
	unsigned int nrLoc;
	unsigned int nrRand;
	int* UID;
	unsigned int dimUID;
public:
	Bilet();
	Bilet(const char*, unsigned int, unsigned int);
	Bilet(const Bilet&);
	~Bilet();
	Bilet& operator=(const Bilet&);
	char* getNumeClient();
	int getId();
	int getNrLoc();
	int getNrRand();
	int* getUID();
	int getDimUID();
};

