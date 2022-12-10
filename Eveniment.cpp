#include "Eveniment.h"
int Eveniment::nrEvenimente = 0;
Eveniment::Eveniment(): nrMaximLocuri(0)
{
	nrEvenimente++;
	id = 0;
	denumire = new char[strlen("Necunoscut") + 1];
	strcpy_s(denumire, strlen("Necunoscut") + 1, "Necunoscut");
}
Eveniment::Eveniment(const char* denumire, int nrMaximLocuri) : nrMaximLocuri(nrMaximLocuri)
{
	nrEvenimente++;
	id = nrEvenimente;
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
}
Eveniment::Eveniment(const Eveniment& e) : nrMaximLocuri(e.nrMaximLocuri)
{
	nrEvenimente++;
	id = nrEvenimente;
	denumire = new char[strlen(e.denumire) + 1];
	strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
}
Eveniment::~Eveniment()
{
	if (denumire)
		delete[] denumire;
}
Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		if (denumire)
			delete[] denumire;
		denumire = new char[strlen(e.denumire) + 1];
		strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
	}
	return *this;
}