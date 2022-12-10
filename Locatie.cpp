#include "Locatie.h"
Locatie::Locatie(): nrMaximLocuri(0)
{
	nume = "Necunoscut";
}
Locatie::Locatie(const string& nume, unsigned int nrMaximLocuri) : nrMaximLocuri(nrMaximLocuri)
{
	this->nume = nume;
}
Locatie::Locatie(const Locatie& l) : nrMaximLocuri(l.nrMaximLocuri)
{
	nume = l.nume;
}
Locatie::~Locatie()
{
}
Locatie& Locatie::operator=(const Locatie& l)
{
	if (this != &l)
		nume = l.nume;
	return *this;
}
string Locatie::getNume()
{
	return nume;
}
unsigned int Locatie::getNrMaximLocuri()
{
	return nrMaximLocuri;
}