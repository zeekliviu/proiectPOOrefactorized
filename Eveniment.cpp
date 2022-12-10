#include "Eveniment.h"
int Eveniment::nrEvenimente = 0;
Eveniment::Eveniment()
{
	nrEvenimente++;
	id = 0;
	denumire = new char[strlen("Necunoscut") + 1];
	strcpy_s(denumire, strlen("Necunoscut") + 1, "Necunoscut");
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	locatie = new Locatie();
	//bilete = nullptr;
}
Eveniment::Eveniment(const char* denumire, Locatie* l)
{
	nrEvenimente++;
	id = nrEvenimente;
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	locatie = new Locatie(*l);
	//bilete = nullptr;
}
Eveniment::Eveniment(const Eveniment& e)
{
	nrEvenimente++;
	id = nrEvenimente;
	denumire = new char[strlen(e.denumire) + 1];
	strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
	locatie = new Locatie(*e.locatie);
}
Eveniment::~Eveniment()
{
	if (denumire)
		delete[] denumire;
	if (locatie)
		delete locatie;
}
Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		if (denumire)
			delete[] denumire;
		denumire = new char[strlen(e.denumire) + 1];
		strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
		if (locatie)
			delete locatie;
		locatie = new Locatie(*e.locatie);
	}
	return *this;
}
ostream& operator<<(ostream& out, const Eveniment& e)
{
	out << "Denumire: " << e.denumire << endl;
	out << "Locatie: " << e.locatie->getNume() << endl;
	out << "Nr maxim locuri: " << e.locatie->getNrMaximLocuri() << endl;
	return out;
}
istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Denumire: ";
	char buffer[30];
	int nrLocuri;
	in >> buffer;
	if (e.denumire)
		delete[] e.denumire;
	e.denumire = new char[strlen(buffer) + 1];
	strcpy_s(e.denumire, strlen(buffer) + 1, buffer);
	cout << "Locatie: ";
	in >> buffer;
	if (e.locatie)
		delete e.locatie;
	in >> nrLocuri;
	e.locatie = new Locatie(buffer, nrLocuri);
	return in;
}