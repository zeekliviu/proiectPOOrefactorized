#include "Eveniment.h"
unsigned int Eveniment::nrEvenimente = 0;
Eveniment::Eveniment()
{
	nrEvenimente++;
	id = nrEvenimente;
	denumire = new char[strlen("Necunoscut") + 1];
	strcpy_s(denumire, strlen("Necunoscut") + 1, "Necunoscut");
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	locatie = new Locatie();
	bilete = nullptr;
	nrBilete = 0;
}
Eveniment::Eveniment(const char* denumire)
{
	nrEvenimente++;
	id = nrEvenimente;
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	locatie = new Locatie();
	bilete = nullptr;
	nrBilete = 0;
}
Eveniment::Eveniment(const char* denumire, Locatie* l)
{
	nrEvenimente++;
	id = nrEvenimente;
	this->denumire = new char[strlen(denumire) + 1];
	strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	locatie = new Locatie(*l);
	bilete = nullptr;
	nrBilete = 0;
}
Eveniment::Eveniment(const Eveniment& e)
{
	nrEvenimente++;
	id = nrEvenimente;
	denumire = new char[strlen(e.denumire) + 1];
	strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
	data = new char[strlen("TBA") + 1];
	strcpy_s(data, strlen("TBA") + 1, "TBA");
	ora = new char[strlen("TBA") + 1];
	strcpy_s(ora, strlen("TBA") + 1, "TBA");
	locatie = new Locatie(*e.locatie);
	if (e.bilete)
	{
		nrBilete = e.nrBilete;
		bilete = new Bilet * [nrBilete];
		for (int i = 0; i < nrBilete; i++)
			bilete[i] = new Bilet(*e.bilete[i]);
	}
	else
	{
		nrBilete = 0;
		bilete = nullptr;
	}
}
Eveniment::~Eveniment()
{
	if (denumire)
		delete[] denumire;
	if (locatie)
		delete locatie;
	if (bilete)
	{
		for (int i = 0; i < nrBilete; i++)
			delete bilete[i];
		delete[] bilete;
	}
}
Eveniment& Eveniment::operator=(const Eveniment& e)
{
	if (this != &e)
	{
		id = e.id;
		if (denumire)
			delete[] denumire;
		denumire = new char[strlen(e.denumire) + 1];
		strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
		if (locatie)
			delete locatie;
		locatie = new Locatie(*e.locatie);
		if (bilete)
		{
			for (int i = 0; i < nrBilete; i++)
				delete bilete[i];
			delete[] bilete;
		}
		if (e.bilete)
		{
			nrBilete = e.nrBilete;
			bilete = new Bilet * [nrBilete];
			for (int i = 0; i < nrBilete; i++)
				bilete[i] = new Bilet(*e.bilete[i]);
		}
		else
		{
			nrBilete = 0;
			bilete = nullptr;
		}
	}
	return *this;
}
ostream& operator<<(ostream& out, const Eveniment& e)
{
	out << "=========== ID: " << e.id << endl;
	out << "=========== Denumire: " << e.denumire << endl;
	out << "=========== Locatie: " << e.locatie->getNume() << endl;
	out << "=========== Numar maxim de locuri: " << e.locatie->getNrMaximLocuri() << endl;
	out << "=========== Numar bilete vandute: " << e.nrBilete << endl;
	out << "=========== Locuri disponibile: " << e.locatie->getNrMaximLocuri() - e.nrBilete << endl<<endl<<endl;
	return out;
}
istream& operator>>(istream& in, Eveniment& e)
{
	cout << "Denumire: ";
	string buffer;
	char buf[UCHAR_MAX], cc;
	int nrLocuri;
	getline(in, buffer);
	if (e.denumire)
		delete[] e.denumire;
	e.denumire = new char[buffer.length() + 1];
	strcpy_s(e.denumire, buffer.length() + 1, buffer.c_str());
	cout << "Locatie: ";
	getline(in, buffer);
	if (e.locatie)
		delete e.locatie;
	cout << "Introdu numarul de locuri: ";
	do
	{
		while (true)
		{
			if (!fgets(buf, sizeof buf, stdin))
				break;
			if (sscanf(buf, "%d %c", &nrLocuri, &cc) != 1)
			{
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul de locuri: ";
				continue;
			}
			break;
			if (nrLocuri <= 0)
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul de locuri: ";
		}
	} while (nrLocuri <= 0);
	e.locatie = new Locatie(buffer, nrLocuri);
	return in;
}
char* Eveniment::getDenumire()
{
	if (denumire)
	{
		char* copie = new char[strlen(denumire) + 1];
		strcpy_s(copie, strlen(denumire) + 1, denumire);
		return copie;
	}
	return nullptr;
}
char* Eveniment::getData()
{
	if (data)
	{
		char* copie = new char[strlen(data) + 1];
		strcpy_s(copie, strlen(data) + 1, data);
		return copie;
	}
	return nullptr;
}
char* Eveniment::getOra()
{
	if (ora)
	{
		char* copie = new char[strlen(ora) + 1];
		strcpy_s(copie, strlen(ora) + 1, ora);
		return copie;
	}
	return nullptr;
}
Locatie* Eveniment::getLocatie()
{
	if (locatie)
		return new Locatie(*locatie);
	return nullptr;
}
unsigned int Eveniment::getId()
{
	return id;
}
unsigned int Eveniment::getNrEvenimente()
{
	return nrEvenimente;
}
Bilet** Eveniment::getBilete()
{
	if (bilete)
	{
		Bilet** copie = new Bilet * [nrBilete];
		for (int i = 0; i < nrBilete; i++)
			copie[i] = new Bilet(*bilete[i]);
		return copie;
	}
	return nullptr;
}