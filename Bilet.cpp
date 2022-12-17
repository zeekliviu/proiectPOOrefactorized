#include "Bilet.h"
unsigned int Bilet::nrBilete = 0;
Bilet::Bilet() : nrLoc(0), nrRand(0), dimUID(0)
{
	nrBilete++;
	id = 0;
	numeClient = new char[strlen("Necunoscut") + 1];
	strcpy_s(numeClient, strlen("Necunoscut") + 1, "Necunoscut");
	UID = nullptr;
}
Bilet::Bilet(const char* numeClient, unsigned int nrLoc, unsigned int nrRand) : nrLoc(nrLoc), nrRand(nrRand)
{
	nrBilete++;
	id = nrBilete;
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
	this->dimUID = (unsigned int)log10(id) + (unsigned int)strlen(numeClient) + 1;
	this->UID = new int[dimUID];
	int copieId = id;
	int i = 0;
	while (copieId)
	{
		UID[i++] = copieId % 10;
		copieId /= 10;
	}
	for (int j = 0; j < strlen(numeClient); j++)
		UID[i++] = numeClient[j];
}
Bilet::Bilet(const Bilet& b) : nrLoc(b.nrLoc), nrRand(b.nrRand), dimUID(b.dimUID)
{
	nrBilete++;
	id = nrBilete;
	numeClient = new char[strlen(b.numeClient) + 1];
	strcpy_s(numeClient, strlen(b.numeClient) + 1, b.numeClient);
	UID = new int[dimUID];
	for (unsigned int i = 0; i < dimUID; i++)
		UID[i] = b.UID[i];
}
Bilet::~Bilet()
{
	if (numeClient)
		delete[] numeClient;
	if (UID)
		delete[] UID;
}
Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b)
	{
		if (numeClient)
			delete[] numeClient;
		if (UID)
			delete[] UID;
		nrLoc = b.nrLoc;
		nrRand = b.nrRand;
		dimUID = b.dimUID;
		numeClient = new char[strlen(b.numeClient) + 1];
		strcpy_s(numeClient, strlen(b.numeClient) + 1, b.numeClient);
		UID = new int[dimUID];
		for (unsigned int i = 0; i < dimUID; i++)
			UID[i] = b.UID[i];
	}
	return *this;
}
ostream& operator<<(ostream& out, const Bilet& b)
{
	out << "Nume client: " << b.numeClient << endl;
	out << "Numar loc: " << b.nrLoc << endl;
	out << "Numar rand: " << b.nrRand << endl;
	out << "UID: ";
	for (unsigned int i = 0; i < b.dimUID; i++)
		out << b.UID[i];
	out << endl;
	return out;
}
istream& operator>>(istream& in, Bilet& b)
{
	string buffer;
	cout << "Nume client: ";
	getline(in, buffer);
	if (b.numeClient)
		delete[] b.numeClient;
	b.numeClient = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(b.numeClient, strlen(buffer.c_str()) + 1, buffer.c_str());
	cout << "Numar loc: ";
	in >> b.nrLoc;
	cout << "Numar rand: ";
	in >> b.nrRand;
	if (b.UID)
		delete[] b.UID;
	b.dimUID = (unsigned int)log10(b.id) + (unsigned int)strlen(b.numeClient) + 1;
	b.UID = new int[b.dimUID];
	int copieId = b.id;
	int i = 0;
	while (copieId)
	{
		b.UID[i++] = copieId % 10;
		copieId /= 10;
	}
	for (int j = 0; j < strlen(b.numeClient); j++)
		b.UID[i++] = b.numeClient[j];
	return in;
}
bool Bilet::operator==(const Bilet& b)
{
	return (!strcmp(numeClient, b.numeClient));
}
bool Bilet::operator<(const Bilet& b)
{
	return dimUID < b.dimUID;
}
char* Bilet::getNumeClient()
{
	if (numeClient)
	{
		char* copieNumeClient = new char[strlen(numeClient) + 1];
		strcpy_s(copieNumeClient, strlen(numeClient) + 1, numeClient);
		return copieNumeClient;
	}
	return nullptr;
}
int Bilet::getId()
{
	return id;
}
int Bilet::getNrLoc()
{
	return nrLoc;
}
int Bilet::getNrRand()
{
	return nrRand;
}
int* Bilet::getUID()
{
	if(UID)
	{
		int* copieUID = new int[dimUID];
		for (unsigned int i = 0; i < dimUID; i++)
			copieUID[i] = UID[i];
		return copieUID;
	}
	return nullptr;
}
int Bilet::getDimUID()
{
	return dimUID;
}
void Bilet::setNumeClient(const char* numeClient)
{
	if (this->numeClient)
		delete[] this->numeClient;
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);
	if(UID)
		delete[] UID;
	dimUID = (unsigned int)log10(id) + (unsigned int)strlen(numeClient) + 1;
	UID = new int[dimUID];
	int copieId = id;
	int i = 0;
	while (copieId)
	{
		UID[i++] = copieId % 10;
		copieId /= 10;
	}
	for (int j = 0; j < strlen(numeClient); j++)
		UID[i++] = numeClient[j];
}
void Bilet::setNumarLoc(unsigned int nrLoc)
{
	if(nrLoc)
	this->nrLoc = nrLoc;
}
void Bilet::setNumarRand(unsigned int nrRand)
{
	if(nrRand)
	this->nrRand = nrRand;
}
bool Bilet::verificaBilet(string s)
{
	string UIDString;
	for (unsigned int i = 0; i < dimUID; i++)
		UIDString += to_string(UID[i]);
	return UIDString == s;
}
void Bilet::setNrBilete(int nrBilete)
{
	Bilet::nrBilete = nrBilete;
}