#pragma once
#include "Bilet.h"
#pragma warning(disable:4996)
using namespace std;
class Zona
{
private:
	string nume;
	int nrLocuri;
	unsigned int nrMaximRanduri;
	unsigned int nrMaximLocuri;
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
	int operator*(const Zona&); // daca vrem sa determinam numarul de locuri din comasarea a doua zone
	float operator/(const Zona&); // daca vrem sa determinam cat la suta din locurile obiectului curent reprezinta locurile din obiectul primit ca parametru
	void cumparaBilet(const char*, const char*, const char*, string);
	void cumparaBilet(const char*, const char*, const char*, string, int, int, bool, string, string);
	void verificaBilet();
	void verificaBilet(string);
	void salveazaInFisier(ofstream&);
	void restaureazaDinFisier(ifstream&);
};

