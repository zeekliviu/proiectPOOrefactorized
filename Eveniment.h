#include <iostream>
#include <string>
#include "Bilet.h"
#include "Locatie.h"
#pragma warning(disable:4996)
using namespace std;
#pragma once
class Eveniment
{
private:
	char* denumire;
	char* data;
	char* ora;
	static unsigned int nrEvenimente;
	unsigned int id;
	Locatie* locatie;
	Bilet** bilete;
	int nrBilete;
public:
	Eveniment();
	Eveniment(const char*);
	Eveniment(const char*, Locatie*);
	Eveniment(const Eveniment&);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	char* getDenumire();
	char* getData();
	char* getOra();
	unsigned int getId();
	static unsigned int getNrEvenimente();
	Locatie* getLocatie();
	Bilet** getBilete();
};

