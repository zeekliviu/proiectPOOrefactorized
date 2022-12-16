#include "Zona.h"
Zona::Zona()
{
	nume = "";
	nrLocuri = 0;
	bilete = nullptr;
	nrBilete = 0;
}
Zona::Zona(const char* nume, int nrLocuri)
{
	this->nume = nume;
	this->nrLocuri = nrLocuri;
	bilete = nullptr;
	nrBilete = 0;
}
Zona::Zona(const Zona& z)
{
	nume = z.nume;
	nrLocuri = z.nrLocuri;
	bilete = new Bilet[z.nrBilete];
	for (int i = 0; i < z.nrBilete; i++)
		bilete[i] = z.bilete[i];
	nrBilete = z.nrBilete;
}
Zona& Zona::operator=(const Zona& z)
{
	nume = z.nume;
	nrLocuri = z.nrLocuri;
	if(bilete)
		delete[] bilete;
	bilete = new Bilet[z.nrBilete];
	for (int i = 0; i < z.nrBilete; i++)
		bilete[i] = z.bilete[i];
	nrBilete = z.nrBilete;
	return *this;
}
string Zona::getNume()
{
	return nume;
}
int Zona::getNrLocuri()
{
	return nrLocuri;
}
int Zona::getNrBilete()
{
	return nrBilete;
}
void Zona::setNume(const char* nume)
{
	this->nume = nume;
}
void Zona::setNrLocuri(int nrLocuri)
{
	this->nrLocuri = nrLocuri;
}
ostream& operator<<(ostream& out, const Zona& z)
{
	out << "\t\tNume zona: " << z.nume << endl;
	out << "\t\tNumar locuri: " << z.nrLocuri << endl;
	out << "\t\tNumar bilete disponibile: " << z.nrLocuri - z.nrBilete << endl;
	return out;
}
istream& operator>>(istream& in, Zona& z)
{
	char buf[UCHAR_MAX], cc;
	cout << "Nume zona: ";
	getline(in, z.nume);
	cout << "Numar locuri: ";
	do
	{
		while (true)
		{
			if (!fgets(buf, sizeof buf, stdin))
				break;
			if (sscanf(buf, "%d %c", &z.nrLocuri, &cc) != 1)
			{
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul de locuri: ";
				continue;
			}
			break;
		}
		if (z.nrLocuri <= 0)
			cout << "Numar invalid! Mai incearca!\nIntrodu numarul de locuri: ";
	} while (z.nrLocuri <= 0);
	return in;
}
void Zona::cumparaBilet()
{
	if (nrBilete == nrLocuri)
	{
		cout << "Nu mai sunt locuri disponibile in zona " << nume << "!\n";
		return;
	}
	Bilet* aux = new Bilet[nrBilete + 1];
	for (int i = 0; i < nrBilete; i++)
		aux[i] = bilete[i];
	delete[] bilete;
	bilete = aux;
	string numeclient;
	cout << "Nume client: ";
	getline(cin, numeclient);
	bilete[nrBilete].setNumeClient(numeclient.c_str());
	
	bilete[nrBilete].setNrLoc(nrBilete + 1);
	nrBilete++;
}