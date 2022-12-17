#include "Locatie.h"
Locatie::Locatie(): nrMaximLocuri(0)
{
	nume = "Necunoscut";
}
Locatie::Locatie(const string& nume, int nrMaximLocuri) : nrMaximLocuri(nrMaximLocuri)
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
ostream& operator<<(ostream& out, const Locatie& l)
{
	out << "Denumire locatie: " << l.nume << '\n';
	out << "Numarul maxim de locuri din locatie: " << l.nrMaximLocuri << '\n';
	return out;
}
istream& operator>>(istream& in, Locatie& l)
{
	cout << "Denumire locatie: ";
	getline(in, l.nume);
	return in;
}
explicit Locatie::operator string()
{
	return nume;
}
string Locatie::getNume()
{
	return nume;
}
int Locatie::getNrMaximLocuri()
{
	return nrMaximLocuri;
}
void Locatie::setNume(string nume)
{
	this->nume = nume;
}