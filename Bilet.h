#pragma once
#include <iostream>
#include <string>
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
	friend ostream& operator<<(ostream&, const Bilet&);
	friend istream& operator>>(istream&, Bilet&);
	bool operator==(const Bilet&); // pentru a verifica daca 2 bilete apartin aceluiasi client
	bool operator<(const Bilet&); // pentru a verifica daca dimensiunea UID-ului unui bilet este mai mica decat a celui de-al doilea (daca este mai mica, inseamna ca numele clientului curent este mai mic decat al celui primit ca parametru)
	char* getNumeClient();
	int getId();
	int getNrLoc();
	int getNrRand();
	int* getUID();
	int getDimUID();
	void setNumeClient(const char*);
	void setNumarLoc(unsigned int);
	void setNumarRand(unsigned int);
	bool verificaBilet(string);
	void setNrBilete(int);
};

