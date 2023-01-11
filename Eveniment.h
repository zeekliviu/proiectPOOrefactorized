#include "Bilet.h"
#include "Locatie.h"
#include "Zona.h"
#include "data.h"
#include "timp.h"
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
	int id;
	Locatie* locatie;
	Zona zone[5];
	int nrZone;
public:
	Eveniment();
	Eveniment(const char*);
	Eveniment(const char*, Locatie*);
	Eveniment(const Eveniment&);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
	void operator[](int); // ca sa afisam o zona dupa index
	Eveniment operator++(); // ca sa crestem numarul de evenimente cu 1 pre-incrementare
	Eveniment operator++(int); // ca sa crestem numarul de evenimente cu 1 post-incrementare
	char* getDenumire();
	char* getData();
	char* getOra();
	int getId();
	Zona* getZone();
	int getNrZone();
	static unsigned int getNrEvenimente();
	Locatie* getLocatie();
	int getTotalLocuriCumparate();
	void cumparaBilet();
	void cumparaBilet(string, string, int, int, bool, string);
	void verificaBilet();
	void verificaBilet(string, string);
	void salveazaInFisier(ofstream&);
	void restaureazaDinFisier(ifstream&);
};

