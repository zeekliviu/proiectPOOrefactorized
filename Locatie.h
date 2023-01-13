#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ISalvabil.h"
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
	friend ostream& operator<<(ostream&, const Locatie&);
	friend istream& operator>>(istream&, Locatie&);
	explicit operator string(); // ca sa obtinem numele locatiei (alternativ la getter)
	string getNume();
	int getNrMaximLocuri();
	void setNume(string);
	void salveazaInFisier(ofstream&);
	void restaureazaDinFisier(ifstream&);
};

