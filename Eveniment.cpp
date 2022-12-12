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
	out << "=========== Data: " << e.data << endl;
	out << "=========== Ora: " << e.ora << endl;
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
		}
		if (nrLocuri <= 0)
			cout << "Numar invalid! Mai incearca!\nIntrodu numarul de locuri: ";
	} while (nrLocuri <= 0);
	e.locatie = new Locatie(buffer, nrLocuri);
	cout << "Data (zz/ll/aaaa): ";
	getline(in, buffer);
	bool is_ok = false;
	if (buffer.length() == 10)
	{
		int an, luna, zi;
		an = atoi(buffer.c_str() + 6);
		luna = atoi(buffer.c_str() + 3);
		zi = atoi(buffer.c_str());
		class::data d = data::data(zi, luna, an);
		if (d.verificaData())
			is_ok = true;
	}
	while (!is_ok)
	{
		cout << "Data incorecta. Introduceti data in formatul zz/ll/aaaa: ";
		getline(in, buffer);
		if (buffer.length() == 10)
		{
			int an, luna, zi;
			an = atoi(buffer.c_str() + 6);
			luna = atoi(buffer.c_str() + 3);
			zi = atoi(buffer.c_str());
			class::data d = data::data(zi, luna, an);
			if (d.verificaData())
				is_ok = true;
		}
	}
	if (e.data != nullptr)
		delete[] e.data, e.data = nullptr;
	e.data = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(e.data, strlen(buffer.c_str()) + 1, buffer.c_str());
	cout << "Ora (hh:mm): ";
	getline(in, buffer);
	is_ok = false;
	if (buffer.length() == 5)
	{
		int ora, minut;
		ora = atoi(buffer.c_str());
		minut = atoi(buffer.c_str() + 3);
		int copie_ora = ora, copie_min = minut;
		int nrCifOra = 0, nrCifMin = 0;
		if (buffer[0] == '0')
			nrCifOra++;
		if (buffer[3] == '0')
			nrCifMin++;
		if (copie_ora == 0)
			nrCifOra++;
		if (copie_min == 0)
			nrCifMin++;
		while (copie_ora)
		{
			copie_ora /= 10;
			nrCifOra++;
		}
		while (copie_min)
		{
			copie_min /= 10;
			nrCifMin++;
		}
		char bufOra[3];
		char bufMin[3];
		strncpy_s(bufOra, buffer.c_str(), 2);
		strncpy_s(bufMin, buffer.c_str() + 3, 2);
		if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
		{
			timp t = timp::timp(ora, minut);
			if (!t.getFlag())
				is_ok = true;
		}
		else is_ok = false;
	}
	while (!is_ok)
	{
		cout << "Ora incorecta. Introduceti ora in formatul hh:mm: ";
		getline(in, buffer);
		if (buffer.length() == 5)
		{
			int ora, minut;
			ora = atoi(buffer.c_str());
			minut = atoi(buffer.c_str() + 3);
			int copie_ora = ora, copie_min = minut;
			int nrCifOra = 0, nrCifMin = 0;
			if (buffer[0] == '0')
				nrCifOra++;
			if (buffer[3] == '0')
				nrCifMin++;
			if (copie_ora == 0)
				nrCifOra++;
			if (copie_min == 0)
				nrCifMin++;
			while (copie_ora)
			{
				copie_ora /= 10;
				nrCifOra++;
			}
			while (copie_min)
			{
				copie_min /= 10;
				nrCifMin++;
			}
			char bufOra[3];
			char bufMin[3];
			strncpy_s(bufOra, buffer.c_str(), 2);
			strncpy_s(bufMin, buffer.c_str() + 3, 2);
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				timp t = timp::timp(ora, minut);
				if (!t.getFlag())
					is_ok = true;
			}
			else is_ok = false;
		}
	}
	if (e.ora != nullptr)
		delete[] e.ora, e.ora = nullptr;
	e.ora = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(e.ora, strlen(buffer.c_str()) + 1, buffer.c_str());
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