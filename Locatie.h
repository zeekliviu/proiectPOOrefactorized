#pragma once
#include <iostream>
using namespace std;
class Locatie
{
private:
	string nume;
	const unsigned int nrMaximLocuri;
public:
	Locatie();
	Locatie(const string&, unsigned int);
	Locatie(const Locatie&);
	~Locatie();
	Locatie& operator=(const Locatie&);
	string getNume();
	unsigned int getNrMaximLocuri();
};

