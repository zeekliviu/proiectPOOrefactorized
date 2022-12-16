#pragma once
#include <iostream>
using namespace std;
class Locatie
{
private:
	string nume;
	const int nrMaximLocuri;
public:
	Locatie();
	Locatie(const string&, int);
	Locatie(const Locatie&);
	~Locatie();
	Locatie& operator=(const Locatie&);
	string getNume();
	int getNrMaximLocuri();
};

