#include "MaestruEveniment.h"
MaestruEveniment::MaestruEveniment()
{
	nume = "";
	parola = "";
	evenimente = nullptr;
	nrEvenimente = 0;
}
MaestruEveniment::MaestruEveniment(const string& nume, const string& parola)
{
	this->nume = nume;
	this->parola = parola;
}
MaestruEveniment::MaestruEveniment(const MaestruEveniment& m)
{
	nume = m.nume;
	parola = m.parola;
}
MaestruEveniment::~MaestruEveniment()
{
}
MaestruEveniment& MaestruEveniment::operator=(const MaestruEveniment& m)
{
	if (this != &m)
	{
		nume = m.nume;
		parola = m.parola;
	}
	return *this;
}
string MaestruEveniment::getNume()
{
	return nume;
}
void MaestruEveniment::setNume(const string& nume)
{
		this->nume = nume;
}
void MaestruEveniment::setParola(const string& parola)
{
	if (nume == "Admin")
		this->parola = parola;
}
void MaestruEveniment::adaugaEveniment()
{
	if(nume=="Admin")
	{
			Eveniment* newEvenimente = new Eveniment[nrEvenimente + 1];
			for (int i = 0; i < nrEvenimente; i++)
				newEvenimente[i] = evenimente[i];
			delete[] evenimente;
			evenimente = newEvenimente;
			cin >> evenimente[nrEvenimente];
			for (int i = 0; i < evenimente[nrEvenimente].getNrZone(); i++)
				cin >> evenimente[nrEvenimente].getZone()[i];
			nrEvenimente++;
	}
}
void MaestruEveniment::stergeEveniment(int id)
{
	if (nume != "Admin") 
		return;
	

	if (nrEvenimente == 0) 
		return;
	

	bool ok = false;
	for (int i = 0; i < nrEvenimente; i++) 
		if (evenimente[i].getId() == id) 
		{
			ok = true;
			break;
		}
	

	if (!ok) 
	{
		cout << "Evenimentul nu exista\n";
		return;
	}

	Eveniment* aux = new Eveniment[nrEvenimente - 1];
	int j = 0;
	for (int i = 0; i < nrEvenimente; i++) 
		if (evenimente[i].getId() != id) 
			aux[j++] = evenimente[i];
		
	delete[] evenimente;
	nrEvenimente--;
	evenimente = new Eveniment[nrEvenimente];
	for (int i = 0; i < nrEvenimente; i++) 
		evenimente[i] = aux[i];
	delete[] aux;
}

void MaestruEveniment::modificaEveniment(int id)
{
	if (nume != "Admin") 
		return;

	if (nrEvenimente == 0)
		return;
	
	bool ok = false;
	for (int i = 0; i < nrEvenimente; i++) 
		if (evenimente[i].getId() == id) 
		{
			ok = true;
			cin >> evenimente[i];
			break;
		}

	if (!ok) 
		cout << "Evenimentul nu exista\n";
}
int MaestruEveniment::afiseazaEvenimente()
{
	if (!nrEvenimente) 
		return 0;
	for (int i = 0; i < nrEvenimente; i++) 
		cout << evenimente[i];
	return 1;
}
void MaestruEveniment::cumparaBilet(int id)
{
	if (nrEvenimente == 0) 
		return;
	bool ok = false;
	for (int i = 0; i < nrEvenimente; i++) 
		if (evenimente[i].getId() == id) 
		{
			ok = true;
			evenimente[i].cumparaBilet();
			break;
		}
	if (!ok) 
		cout << "Evenimentul nu exista\n";
}
void MaestruEveniment::verificaBilet(int id)
{
	if (nrEvenimente == 0)
		return;
	bool ok = false;
	for (int i = 0; i < nrEvenimente; i++)
		if (evenimente[i].getId() == id)
		{
			ok = true;
			evenimente[i].verificaBilet();
			break;
		}
	if (!ok)
		cout << "Evenimentul nu exista\n";
}
