#pragma once
#include "Eveniment.h"
#include "ISalvabil.h"
using namespace std;
class MaestruEveniment : public ISalvabil
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
	friend ostream& operator<<(ostream&, const MaestruEveniment&);
	friend istream& operator>>(istream&, MaestruEveniment&);
	bool operator>(const MaestruEveniment&); // verifica daca numele obiectului curent este mai mare decat al celui primit ca parametru
	bool operator>=(const MaestruEveniment&); // verifica daca lungimea parolei este mai mare sau egala cu parola obiectului primit ca parametru (in caz de egalitate, este posibil sa vorbim despre acelasi user)
	string getNume();
	int getNrEvenimente();
	Eveniment* getEvenimente();
	void setNume(const string&);
	void setParola(const string&);
	void adaugaEveniment();
	void stergeEveniment(int);
	void modificaEveniment(int);
	int afiseazaEvenimente();
	void cumparaBilet(int);
	void cumparaBilet(int, string, int, int, bool, string, string);
	void verificaBilet(int);
	void verificaBilet(int, string, string);
	void salveazaInFisier(ofstream&);
	void restaureazaDinFisier(ifstream&);
	void citesteFisier(ifstream&);
};