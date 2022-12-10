#include <iostream>
#include "Bilet.h"
#include "Locatie.h"
using namespace std;
#pragma once
class Eveniment
{
private:
	char* denumire;
	char* data;
	char* ora;
	static int nrEvenimente;
	int id;
	Locatie* locatie;
public:
	Eveniment();
	Eveniment(const char*, Locatie*);
	Eveniment(const Eveniment&);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	friend ostream& operator<<(ostream&, const Eveniment&);
	friend istream& operator>>(istream&, Eveniment&);
};

