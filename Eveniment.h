#include <iostream>
#include <string>
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
	char* getDenumire();
	char* getData();
	char* getOra();
	int getId();
	static unsigned int getNrEvenimente();
	Locatie* getLocatie();
	int getTotalLocuriCumparate();
	void cumparaBilet();
};

