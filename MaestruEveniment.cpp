#include "MaestruEveniment.h"
void split_str(string const& str, const char delim, vector<string>& out)
{
	stringstream s(str);
	string s2;
	while (getline(s, s2, delim))
	{
		if (s2.find('"') != string::npos)
		{
			s2.erase(s2.find('"'), 1);
			string aux;
			while (getline(s, aux, delim) && s2[s2.length()] != '"')
			{
				if (aux.find('"') != string::npos)
					aux.erase(aux.find('"'), 1);
				s2 = s2 + " " + aux;
			}
		}
		out.push_back(s2);
	}
}
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
ostream& operator<<(ostream& out, const MaestruEveniment& m)
{
	out << m.nume << endl;
	return out;
}
istream& operator>>(istream& in, MaestruEveniment& m)
{
	cout << "Nume: ";
	in >> m.nume;
	cout << "Parola: ";
	in >> m.parola;
	cout << "Nr. evenimente: ";
	in >> m.nrEvenimente;
	m.evenimente = new Eveniment[m.nrEvenimente];
	for (int i = 0; i < m.nrEvenimente; i++)
	{
		cout << "Eveniment " << i + 1 << endl;
		in >> m.evenimente[i];
	}
	return in;
}
bool MaestruEveniment::operator>(const MaestruEveniment& m)
{
	return nume > m.nume;
}
bool MaestruEveniment::operator>=(const MaestruEveniment& m)
{
	return parola >= m.parola;
}
string MaestruEveniment::getNume()
{
	return nume;
}
int MaestruEveniment::getNrEvenimente()
{
	return nrEvenimente;
}
Eveniment* MaestruEveniment::getEvenimente()
{
	return evenimente;
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
	if (nume == "Admin")
	{
		if (!evenimente)
		{
			evenimente = new Eveniment[1];
			cin >> evenimente[0];
			for (int i = 0; i < evenimente[0].getNrZone(); i++)
				cin >> evenimente[0].getZone()[i];
			nrEvenimente++;
		}
		else
		{
			Eveniment* aux = new Eveniment[nrEvenimente + 1];
			for (int i = 0; i < nrEvenimente; i++)
				aux[i] = evenimente[i];
			cin >> aux[nrEvenimente];
			for (int i = 0; i < aux[nrEvenimente].getNrZone(); i++)
				cin >> aux[nrEvenimente].getZone()[i];
			delete[] evenimente;
			evenimente = aux;
			nrEvenimente++;
		}
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
	cout << "=========================== LISTA EVENIMENTE ==========================\n\n";
	for (int i = 0; i < nrEvenimente; i++)
		cout << evenimente[i];
	cout << "=========================== LISTA EVENIMENTE ==========================\n\n";
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
void MaestruEveniment::cumparaBilet(int id, string zona, int rand, int loc, bool pe_mail, string email, string nume)
{
	if (nrEvenimente == 0)
		return;
	bool ok = false;
	for (int i = 0; i < nrEvenimente; i++)
		if (evenimente[i].getId() == id)
		{
			ok = true;
			evenimente[i].cumparaBilet(nume, zona, rand, loc, pe_mail, email);
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
void MaestruEveniment::verificaBilet(int id, string zona, string UID)
{
	if (nrEvenimente == 0)
		return;
	bool ok = false;
	for (int i = 0; i < nrEvenimente; i++)
		if (evenimente[i].getId() == id)
		{
			ok = true;
			evenimente[i].verificaBilet(zona, UID);
			break;
		}
	if (!ok)
		cout << "Evenimentul nu exista\n";
}
void MaestruEveniment::salveazaInFisier(ofstream& out)
{
	int length = nume.length();
	out.write((char*)&length, sizeof(length));
	out.write(nume.c_str(), length + 1);
	length = parola.length();
	out.write((char*)&length, sizeof(length));
	out.write(parola.c_str(), length + 1);
	out.write((char*)&nrEvenimente, sizeof(nrEvenimente));
	for (int i = 0; i < nrEvenimente; i++)
		if (evenimente[i].getNrZone() != 0)
			this->evenimente[i].salveazaInFisier(out);
}
void MaestruEveniment::restaureazaDinFisier(ifstream& in)
{
	int length;
	in.read((char*)&length, sizeof(length));
	char* aux = new char[length + 1];
	in.read(aux, length + 1);
	nume = aux;
	delete[] aux;
	in.read((char*)&length, sizeof(length));
	aux = new char[length + 1];
	in.read(aux, length + 1);
	parola = aux;
	delete[] aux;
	in.read((char*)&nrEvenimente, sizeof(nrEvenimente));
	if (evenimente)
		delete[] evenimente;
	evenimente = new Eveniment[nrEvenimente];
	for (int i = 0; i < nrEvenimente; i++)
		evenimente[i].restaureazaDinFisier(in);
}
void MaestruEveniment::citesteFisier(ifstream& f)
{
	string linie;
	vector<vector<string>> comenzi;
	while (getline(f, linie))
	{
		vector<string> comanda;
		split_str(linie, ' ', comanda);
		comenzi.push_back(comanda);
	}
	int k = 0;
	int l = 0;
	string nume;
	string parola;
	string c_eveniment;
	string v_eveniment;
	string zona;
	string mail{};
	string UID;
	int rand, loc;
	bool cumpara = false;
	bool verifica = false;
	bool vede = false;
	bool pe_mail = false;
	for (auto const& i : comenzi)
	{
		++k;
		l = 0;
		for (auto const& j : i)
		{
			l++;
			if (k == 1 && l == 1)
				if (j == "ADMIN")
					nume = "Admin";
			if (k == 1 && l == 3)
				nume = j;
			if (k == 2)
				parola = j;
			if (k == 3 && l == 1)
				if (j == "VREAU")
					continue;
				else {
					cout << "Fisier invalid!"; break;
				}
			if (k == 3 && l == 2)
				if (j == "BILET")
				{
					c_eveniment = i[3];
					cumpara = true;
				}
				else if (j == "SA")
					continue;
				else {
					cout << "Fisier invalid!"; break;
				}
			if (k == 3 && l == 3)
				if (j == "VAD")
					vede = true;
				else if (j == "VERIFIC")
				{
					v_eveniment = i[5];
					verifica = true;
				}
				else if (j == "LA")
					continue;
				else
				{
					cout << "Fisier invalid!"; break;
				}
			if (k == 4)
				zona = i[1];
			if (k == 5)
				if (i[0] == "RAND")
					rand = stoi(i[1]);
				else
					UID = i[0];
			if (k == 6)
				loc = stoi(i[1]);
			if (k == 7)
				if (i[0] == "VREAU" && i[1] == "BILETUL" && i[2] == "PE" && i[3] == "MAIL")
					pe_mail = true;
				else if (i[0] == "NU" && i[1] == "VREAU" && i[2] == "BILETUL" && i[3] == "PE" && i[4] == "MAIL")
					continue;
				else
				{
					cout << "Fisier invalid!"; break;
				}
			if (k == 8)
				mail = i[0];
		}
	}
	if (vede)
	{
		int r = afiseazaEvenimente();
		if (!r)
			cout << "Nu exista evenimente!";
	}
	else if (cumpara)
	{
		bool ok = false;
		for (int i = 0; i < nrEvenimente; i++)
			if (evenimente[i].getDenumire() == c_eveniment)
			{
				ok = true;
				cumparaBilet(evenimente[i].getId(), zona, rand, loc, pe_mail, mail, nume);
				break;
			}
		if (!ok)
			cout << "Nu exista evenimentul " << c_eveniment << "!\n";
	}
	else if (verifica)
	{
		bool ok = false;
		for (int i = 0; i < nrEvenimente; i++)
			if (evenimente[i].getDenumire() == v_eveniment)
			{
				ok = true;
				verificaBilet(evenimente[i].getId(), zona, UID);
				break;
			}
		if (!ok)
			cout << "Nu exista evenimentul " << v_eveniment << "!\n";
	}
}