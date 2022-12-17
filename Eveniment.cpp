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
	nrZone = 0;
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
	nrZone = 0;
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
	nrZone = 0;
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
	nrZone = e.nrZone;
	for (int i = 0; i < nrZone; i++)
		zone[i] = e.zone[i];
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
		id = e.id;
		if (denumire)
			delete[] denumire;
		denumire = new char[strlen(e.denumire) + 1];
		strcpy_s(denumire, strlen(e.denumire) + 1, e.denumire);
		if (locatie)
			delete locatie;
		locatie = new Locatie(*e.locatie);
		nrZone = e.nrZone;
		for (int i = 0; i < nrZone; i++)
			zone[i] = e.zone[i];
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
	out << "=========== Numar zone: " << e.nrZone << endl;
	out << "=========== Denumire zone & locuri pe zona: "<<endl;
	out << "\t\t============ ZONE ============\n" << endl;
	if (e.nrZone == 0)
		out << "\t\tNu exista zone disponibile." << endl;
	else for (int i = 0; i < e.nrZone; i++)
	{
		out << "\t\tID: " << i+1 << endl;
		out << e.zone[i] << endl;
	}
	out << "\t\t============ ZONE ============" << endl;
	out << "=========== Numar maxim de locuri: " << e.locatie->getNrMaximLocuri() << endl;
	Eveniment* ev = const_cast<Eveniment*>(&e);
	out << "=========== Numar bilete vandute: " << ev->getTotalLocuriCumparate() << endl;
	out << "=========== Locuri disponibile: " << e.locatie->getNrMaximLocuri() - ev->getTotalLocuriCumparate() << endl<<endl<<endl;
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
	cout << "Introdu numarul maxim de locuri: ";
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
	if (e.locatie)
		delete e.locatie;
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
		if (buffer[2] != '/' || buffer[5] != '/')
			is_ok = false;
		if (!isdigit(buffer[0]) || !isdigit(buffer[1]) || !isdigit(buffer[3]) || !isdigit(buffer[4]) || !isdigit(buffer[6]) || !isdigit(buffer[7]) || !isdigit(buffer[8]) || !isdigit(buffer[9]))
			is_ok = false;
		if(buffer[6]=='0')
			is_ok = false;
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
			if (buffer[2] != '/' || buffer[5] != '/')
				is_ok = false;
			if (!isdigit(buffer[0]) || !isdigit(buffer[1]) || !isdigit(buffer[3]) || !isdigit(buffer[4]) || !isdigit(buffer[6]) || !isdigit(buffer[7]) || !isdigit(buffer[8]) || !isdigit(buffer[9]))
				is_ok = false;
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
			if (buffer[2] != ':')
				is_ok = false;
			if (!isdigit(buffer[0]) || !isdigit(buffer[1]) || !isdigit(buffer[3]) || !isdigit(buffer[4]))
				is_ok = false;
		}
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
			bufOra[2] = '\0';
			bufMin[2] = '\0';
			if (nrCifOra == strlen(bufOra) && nrCifMin == strlen(bufMin))
			{
				timp t = timp::timp(ora, minut);
				if (!t.getFlag())
					is_ok = true;
			}
			if (buffer[2] != ':')
				is_ok = false;
		}
	}
	if (e.ora != nullptr)
		delete[] e.ora, e.ora = nullptr;
	e.ora = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(e.ora, strlen(buffer.c_str()) + 1, buffer.c_str());
	cout << "Numar zone eveniment: ";
	do
	{
		while (true)
		{
			if (!fgets(buf, sizeof buf, stdin))
				break;
			if (sscanf(buf, "%d %c", &e.nrZone, &cc) != 1)
			{
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul de zone: ";
				continue;
			}
			break;
		}
		if (e.nrZone <= 0)
			cout << "Numar invalid! Mai incearca!\nIntrodu numarul de zone: ";
	} while (e.nrZone <= 0);
	for (int i = 0; i < e.nrZone; i++)
	{
		string nume;
		nrLocuri = 0;
		int nrLocuriPrecedente = 0;
		for (int j = 0; j < i; j++)
			nrLocuriPrecedente += e.zone[j].getNrLocuri();
		if (e.locatie->getNrMaximLocuri() - nrLocuriPrecedente)
		{
			cout << "Denumire zona " << i + 1 << ": ";
			getline(in, nume);
			cout << "Numar locuri pentru zona " << nume << ": ";
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
			while (nrLocuri > e.locatie->getNrMaximLocuri())
			{
				cout << "Numarul de locuri din zona " << nume << " este mai mare decat numarul maxim de locuri din locatie!\n";
				cout << "Introduceti numarul de locuri din zona " << nume << ": ";
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
			}
		}
		if (i == 0)
		{
			e.zone[i].setNume(nume.c_str());
			e.zone[i].setNrLocuri(nrLocuri);
		}
		else 
		{
			if (e.locatie->getNrMaximLocuri() - nrLocuriPrecedente == 0)
			{
				cout << "Nu mai sunt locuri disponibile pentru alocare.\n";
				e.zone[i].setNume("");
				e.zone[i].setNrLocuri(0);
				e.nrZone = i;
				break;
			}
			else while (nrLocuri > e.locatie->getNrMaximLocuri() - nrLocuriPrecedente)
			{
				cout << "Numarul de locuri din zona " << nume << " este mai mare decat numarul de locuri ramase din locatie!\n";
				cout << "Introduceti numarul de locuri din zona " << nume << ": ";
				nrLocuri = 0;
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
			}
			e.zone[i].setNrLocuri(nrLocuri);
			e.zone[i].setNume(nume.c_str());
		}
	}
	return in;
}
void Eveniment::operator[](int i)
{
	if (i >= 0 && i < nrZone)
		cout << zone[i];
	else
		cout << "Index invalid!\n";
}
Eveniment Eveniment::operator++()
{
	nrEvenimente++;
	return *this;
}
Eveniment Eveniment::operator++(int)
{
	Eveniment aux = *this;
	nrEvenimente++;
	return aux;
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
int Eveniment::getId()
{
	return id;
}
Zona* Eveniment::getZone()
{
	return zone;
}
int Eveniment::getNrZone()
{
	return nrZone;
}
unsigned int Eveniment::getNrEvenimente()
{
	return nrEvenimente;
}
int Eveniment::getTotalLocuriCumparate()
{
	int rez = 0;
	for (int i = 0; i < nrZone; i++)
		rez += zone[i].getNrBilete();
	return rez;
}
void Eveniment::cumparaBilet()
{
	
	if (getTotalLocuriCumparate() == locatie->getNrMaximLocuri())
	{
		cout << "Nu mai sunt locuri disponibile la acest eveniment!\n";
		return;
	}
	else
	{
		char buf[UCHAR_MAX], cc;
		cout << "\t\t============ ZONE ============\n" << endl;
		if (nrZone == 0)
			cout << "\t\tNu exista zone disponibile." << endl;
		else for (int i = 0; i < nrZone; i++)
		{
			cout << "\t\tID: " << i + 1 << endl;
			cout << zone[i] << endl;
		}
		cout << "Zona la care vrei biletul: ";
		int zona = 0;
		do
		{
			while (true)
			{
				if (!fgets(buf, sizeof buf, stdin))
					break;
				if (sscanf(buf, "%d %c", &zona, &cc) != 1)
				{
					cout << "Numar invalid! Mai incearca!\nIntrodu numarul zonei: ";
					continue;
				}
				break;
			}
			if (zona-1 < 0 || zona-1 >= nrZone)
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul zonei: ";
		} while (zona-1 < 0 || zona-1 >= nrZone);
		if (zone[zona - 1].getNrLocuri() == zone[zona - 1].getNrBilete())
			cout << "Nu mai sunt locuri disponibile in zona " << zone[zona - 1].getNume() << "!\n";
		else
			zone[zona - 1].cumparaBilet();
	}
}
void Eveniment::verificaBilet()
{
	char buf[UCHAR_MAX], cc;
	cout << "\t\t============ ZONE ============\n" << endl;
	if (nrZone == 0)
	{
		cout << "\t\tNu exista zone disponibile." << endl;
		return;
	}
	else for (int i = 0; i < nrZone; i++)
	{
		cout << "\t\tID: " << i + 1 << endl;
		cout << zone[i] << endl;
	}
	cout << "Zona la care vrei sa verifici biletul: ";
	int zona = 0;
	do
	{
		while (true)
		{
			if (!fgets(buf, sizeof buf, stdin))
				break;
			if (sscanf(buf, "%d %c", &zona, &cc) != 1)
			{
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul zonei: ";
				continue;
			}
			break;
		}
		if (zona - 1 < 0 || zona - 1 > nrZone)
			cout << "Numar invalid! Mai incearca!\nIntrodu numarul zonei: ";
	} while (zona - 1 < 0 || zona - 1 > nrZone);
	if (zone[zona - 1].getNrBilete() == 0)
		cout << "Nu exista bilete cumparate in zona " << zone[zona - 1].getNume() << "!\n";
	else
		zone[zona - 1].verificaBilet();
}