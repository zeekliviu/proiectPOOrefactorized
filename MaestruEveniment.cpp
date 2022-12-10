#include "MaestruEveniment.h"
MaestruEveniment::MaestruEveniment()
{
	nume = "Necunoscut";
	cod = 0;
}
MaestruEveniment::MaestruEveniment(const string& nume, int cod)
{
	this->nume = nume;
	this->cod = cod;
}
MaestruEveniment::MaestruEveniment(const MaestruEveniment& m)
{
	nume = m.nume;
	cod = m.cod;
}
MaestruEveniment::~MaestruEveniment()
{
}
MaestruEveniment& MaestruEveniment::operator=(const MaestruEveniment& m)
{
	if (this != &m)
	{
		nume = m.nume;
		cod = m.cod;
	}
	return *this;
}
string MaestruEveniment::getNume()
{
	return nume;
}
int MaestruEveniment::getCod()
{
	return cod;
}
