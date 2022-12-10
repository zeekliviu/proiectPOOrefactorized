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
	for (int i = 0; i < dimUID; i++)
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
		for (int i = 0; i < dimUID; i++)
			UID[i] = b.UID[i];
	}
	return *this;
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
		for (int i = 0; i < dimUID; i++)
			copieUID[i] = UID[i];
		return copieUID;
	}
	return nullptr;
}
int Bilet::getDimUID()
{
	return dimUID;
}