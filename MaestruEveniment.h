#pragma once
#include <iostream>
#include "Eveniment.h"
using namespace std;
class MaestruEveniment
{
private:
	string nume;
	string parola;
	Eveniment* evenimente;
	int nrEvenimente;
public:
	MaestruEveniment();
	MaestruEveniment(const string&, const string&);
	MaestruEveniment(const MaestruEveniment&);
	~MaestruEveniment();
	MaestruEveniment& operator=(const MaestruEveniment&);
	string getNume();
	void setNume(const string&);
	void setParola(const string&);
	void adaugaEveniment();
	void stergeEveniment(int);
	void modificaEveniment(int);
	int afiseazaEvenimente();
	void cumparaBilet(int);
	void verificaBilet(int);
};