#include "MaestruEveniment.h"
MaestruEveniment::MaestruEveniment()
{
	nume = "";
	parola = "";
	evenimente = nullptr;
	nrEvenimente = 0;
}
MaestruEveniment::MaestruEveniment(const string& nume, const string& parola)
{
	this->nume = nume;
	this->parola = parola;
}
MaestruEveniment::MaestruEveniment(const MaestruEveniment& m)
{
	nume = m.nume;
	parola = m.parola;
}
MaestruEveniment::~MaestruEveniment()
{
}
MaestruEveniment& MaestruEveniment::operator=(const MaestruEveniment& m)
{
	if (this != &m)
	{
		nume = m.nume;
		parola = m.parola;
	}
	return *this;
}
string MaestruEveniment::getNume()
{
	return nume;
}
void MaestruEveniment::setNume(const string& nume)
{
	this->nume = nume;
}
void MaestruEveniment::setParola(const string& parola)
{
	this->parola = parola;
}
void MaestruEveniment::adaugaEveniment()
{
	if(nrEvenimente)
	{
		Eveniment* aux = new Eveniment[nrEvenimente];
		for (int i = 0; i < nrEvenimente; i++)
			aux[i] = evenimente[i];
		delete[] evenimente;
		evenimente = new Eveniment[nrEvenimente + 1];
		for (int i = 0; i < nrEvenimente; i++)
			evenimente[i] = aux[i];
		delete[] aux;
		nrEvenimente++;
		cin >> evenimente[nrEvenimente];
	}
	else
		evenimente = new Eveniment[nrEvenimente++];
}