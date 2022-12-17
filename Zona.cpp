#include "Zona.h"
void combinatii_posibile(int n)
{
	if(n==1)
		cout << "1 loc pe 1 rand." << endl;
	for (int i = 1; i <= sqrt(n); i++)
		if (n % i == 0)
			if (i != (n / i))
			cout << i << " rand(uri) si " << n / i << " locuri pe rand sau invers, adica " << n / i << " randuri si " << i << " loc(uri) pe rand.\n";
			else cout << i << " randuri si " << n / i << " locuri pe rand.\n";
}
Zona::Zona()
{
	nume = "";
	nrLocuri = 0;
	bilete = nullptr;
	nrBilete = 0;
	nrMaximLocuri = 0;
	nrMaximRanduri = 0;
}
Zona::Zona(const char* nume, int nrLocuri)
{
	this->nume = nume;
	this->nrLocuri = nrLocuri;
	bilete = nullptr;
	nrBilete = 0;
	nrMaximLocuri = 0;
	nrMaximRanduri = 0;
}
Zona::Zona(const Zona& z)
{
	nume = z.nume;
	nrLocuri = z.nrLocuri;
	bilete = new Bilet[z.nrBilete];
	for (int i = 0; i < z.nrBilete; i++)
		bilete[i] = z.bilete[i];
	nrBilete = z.nrBilete;
	nrMaximLocuri = z.nrMaximLocuri;
	nrMaximRanduri = z.nrMaximRanduri;
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
	nrMaximLocuri = z.nrMaximLocuri;
	nrMaximRanduri = z.nrMaximRanduri;
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
	out << "\t\tNumar total locuri: " << z.nrLocuri << endl;
	out << "\t\tDispuse pe randuri si locuri dupa cum urmeaza: " << endl;
	for (unsigned int i = 0; i < z.nrMaximRanduri; i++)
	{
		cout << "\n\t\tRand " << i + 1 << " ";
		for (unsigned int j = 0; j < z.nrMaximLocuri; j++)
		{
			if (z.bilete[i * z.nrMaximLocuri + j].getUID() != nullptr)
				cout << "|_"<<char(1)<<"_|";
			else cout << "|___|";
		}
		cout << "\n\t\t\t ";
		for (unsigned int j = 0; j < z.nrMaximLocuri; j++)
			cout << j + 1 << "    ";
		cout << "\n";
	}
					
	out << "\n\t\tUnde "<<char(1)<<" reprezinta loc ocupat.\n"<<"\t\tNumar bilete disponibile : " << z.nrLocuri - z.nrBilete << endl;
	return out;
}
istream& operator>>(istream& in, Zona& z)
{
	char buf[UCHAR_MAX], cc;
	/*cout << "Nume zona: ";
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
	} while (z.nrLocuri <= 0);*/
	cout << "Locurile din zona " << z.nume << " pot fi impartite dupa cum urmeaza : \n";
	combinatii_posibile(z.nrLocuri);
	cout << "Introduceti numarul de randuri: ";
	do
	{
		while (true)
		{
			if (!fgets(buf, sizeof buf, stdin))
				break;
			if (sscanf(buf, "%d %c", &z.nrMaximRanduri, &cc) != 1)
			{
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul de randuri: ";
				continue;
			}
			break;
		}
		if (z.nrMaximRanduri <= 0 || (z.nrLocuri % z.nrMaximRanduri != 0))
			cout << "Numar invalid! Mai incearca!\nIntrodu numarul de randuri: ";
	} while (z.nrMaximRanduri <= 0 || (z.nrLocuri % z.nrMaximRanduri != 0));
	cout << "Deci numarul de locuri pe rand va fi " << z.nrLocuri / z.nrMaximRanduri << "."<< endl;
	z.nrMaximLocuri = z.nrLocuri / z.nrMaximRanduri;
	if(z.bilete)
		delete[] z.bilete;
	z.bilete = new Bilet[z.nrMaximRanduri * z.nrMaximLocuri];
	return in;
}
void Zona::cumparaBilet()
{
	if (nrBilete == nrLocuri)
	{
		cout << "Nu mai sunt locuri disponibile in zona " << nume << "!\n";
		return;
	}
	string numeclient;
	cout << "Nume client: ";
	getline(cin, numeclient);
	cout << "Numar rand dorit: ";
	int rand;
	char cc, buf[UCHAR_MAX];
	do
	{
		while (true)
		{
			if (!fgets(buf, sizeof buf, stdin))
				break;
			if (sscanf(buf, "%d %c", &rand, &cc) != 1)
			{
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul randului: ";
				continue;
			}
			break;
		}
		if (rand <= 0)
			cout << "Numar invalid! Mai incearca!\nIntrodu numarul randului: ";
	} while (rand <= 0);
	if ((unsigned int)rand-1 <= nrMaximRanduri)
	{
		cout << "Numar loc dorit: ";
		int loc;
		do
		{
			while (true)
			{
				if (!fgets(buf, sizeof buf, stdin))
					break;
				if (sscanf(buf, "%d %c", &loc, &cc) != 1)
				{
					cout << "Numar invalid! Mai incearca!\nIntrodu numarul locului: ";
					continue;
				}
				break;
			}
			if (loc <= 0)
				cout << "Numar invalid! Mai incearca!\nIntrodu numarul locului: ";
		} while (loc <= 0);
		if ((unsigned int)loc-1 <= nrMaximLocuri)
		{
			if (bilete[(rand - 1) * nrMaximLocuri + loc - 1].getUID() == nullptr)
			{
				bilete[(rand - 1) * nrMaximLocuri + loc - 1] = Bilet(numeclient.c_str(), rand-1, loc-1);
				cout << "Bilet cumparat cu succes! Noteaza-ti UID-ul undeva, vei avea nevoie de el pentru a-ti verifica biletul!\n";
				int* UID = bilete[(rand - 1) * nrMaximLocuri + loc - 1].getUID();
				unsigned dimUID = bilete[(rand - 1) * nrMaximLocuri + loc - 1].getDimUID();
				cout << "UID: ";
				for (unsigned int i = 0; i < dimUID; i++)
					cout << UID[i];
				nrBilete++;
			}
			else
				cout << "Locul este deja ocupat!\n";
		}
		else
			cout << "Locul nu exista!\n";
	}
	else
		cout << "Randul nu exista!\n";
}
void Zona::verificaBilet()
{
	if (nrBilete == 0)
	{
		cout << "Nu exista bilete in zona " << nume << "!\n";
		return;
	}
	cout << "Introduceti UID-ul biletului: ";
	string UID;
	getline(cin, UID);
	for (unsigned int i = 0; i < nrMaximLocuri*nrMaximRanduri; i++)
		if (bilete[i].getUID() != nullptr)
			if (bilete[i].verificaBilet(UID.c_str()))
			{
				cout << "Biletul este valid!\n";
				return;
			}
	cout << "Biletul nu este valid!\n";
}