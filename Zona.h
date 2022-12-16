#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"
#pragma warning(disable:4996)
using namespace std;
class Zona
{
private:
	string nume;
	int nrLocuri;
	Bilet* bilete;
	int nrBilete;
public:
	Zona();
	Zona(const char*, int);
	Zona(const Zona&);
	Zona& operator=(const Zona&);
	string getNume();
	int getNrLocuri();
	int getNrBilete();
	void setNume(const char*);
	void setNrLocuri(int);
	friend ostream& operator<<(ostream&, const Zona&);
	friend istream& operator>>(istream&, Zona&);
	void cumparaBilet();
};

