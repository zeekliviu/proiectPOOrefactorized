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
		if (nrEvenimente)
		{
			Eveniment* aux = new Eveniment[nrEvenimente];
			for (int i = 0; i < nrEvenimente; i++)
				aux[i] = evenimente[i];
			delete[] evenimente;
			evenimente = new Eveniment[nrEvenimente + 1];
			for (int i = 0; i < nrEvenimente; i++)
				evenimente[i] = aux[i];
			delete[] aux;
			nrEvenimente++;
			cin >> evenimente[nrEvenimente - 1];
		}
		else
		{
			nrEvenimente++;
			evenimente = new Eveniment[nrEvenimente];
			cin >> evenimente[nrEvenimente - 1];
		}
	}
}
void MaestruEveniment::stergeEveniment(unsigned int id)
{
	if (nume == "Admin")
	{
		if (nrEvenimente)
		{
			bool ok = false;
			for (int i = 0; i < nrEvenimente; i++)
				if (evenimente[i].getId() == id)
					ok = true;
			if(ok)
			{
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
			else cout << "Evenimentul nu exista\n";
		}
	}
}
void MaestruEveniment::modificaEveniment(unsigned int id)
{
	if (nume == "Admin")
	{
		if (nrEvenimente)
		{
			bool ok = false;
			for (int i = 0; i < nrEvenimente; i++)
				if (evenimente[i].getId() == id)
				{
					ok = true;
					cin >> evenimente[i];
				}
			if (!ok)
				cout << "Evenimentul nu exista\n";	
		}
	}
}
int MaestruEveniment::afiseazaEvenimente()
{
	if (nrEvenimente)
		for (int i = 0; i < nrEvenimente; i++)
			cout << evenimente[i];
	else return 0;
}