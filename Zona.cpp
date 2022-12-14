#include "Zona.h"
#include <regex>
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
bool verifica_mail(string email)
{
	regex pattern("[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?");
	return regex_match(email, pattern);
} 
string converteste_intArr_in_string(int* arr, unsigned int n)
{
	string s;
	for (unsigned int i = 0; i < n; i++)
		s += to_string(arr[i]);
	return s;
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
	bilete = new Bilet[z.nrMaximLocuri*z.nrMaximRanduri];
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
	bilete = new Bilet[z.nrMaximLocuri * z.nrMaximRanduri];
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
		out << "\n\t\tRand " << i + 1 << " ";
		for (unsigned int j = 0; j < z.nrMaximLocuri; j++)
		{
			if (z.bilete[i * z.nrMaximLocuri + j].getUID() != nullptr)
				out << "|_"<<char(1)<<"_|";
			else out << "|___|";
		}
		out << "\n\t\t\t ";
		for (unsigned int j = 0; j < z.nrMaximLocuri; j++)
			out << j + 1 << "    ";
		out << "\n";
	}
					
	out << "\n\t\tUnde "<<char(1)<<" reprezinta loc ocupat.\n"<<"\t\tNumar bilete disponibile : " << z.nrLocuri - z.nrBilete << endl;
	return out;
}
istream& operator>>(istream& in, Zona& z)
{
	char buf[UCHAR_MAX], cc;
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
int Zona::operator*(const Zona& z)
{
	return nrLocuri * z.nrLocuri;
}
float Zona::operator/(const Zona& z)
{
	return (float)nrLocuri / (float)z.nrLocuri * 100;
}
void Zona::cumparaBilet(const char* denumireEv, const char* data, const char* ora, string denumireLoc)
{
	////////// ARGUMENTE DE PASAT LA MAIN.PY //////////
	// denumireEv - denumirea evenimentului
	// data - data evenimentului
	// ora - ora evenimentului
	// denumireLoc - denumirea locatiei
	// nume - numele zonei
	// rand - randul biletului
	// loc - locul biletului
	// bilete[(rand-1) * nrMaximLocuri + (loc-1)].getUID() - UID-ul biletului (trebuie convertit de la int* la string)
	// sender_mail - adresa de email a expeditorului 
	// sender_pass - parola expeditorului
	// email - adresa de email a destinatarului (email-ul clientului)
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
				cout << "Bilet cumparat cu succes! Vrei sa ti-l trimitem pe mail? (Y/N): ";
				char c;
				cin >> c;
				if (c == 'Y' || c == 'y')
				{
					cout << "Introdu adresa de mail: ";
					string mail;
					cin >> mail;
					while (!verifica_mail(mail))
					{
						cout << "Adresa de mail invalida! Mai incearca!\nIntrodu adresa de mail: ";
						cin >> mail;
					}
					string sender_mail = ENC_MAIL;
					string sender_pass = ENC_PASS;
					string passkey;
					cout << "Introdu passkey-ul pentru decriptarea credentialelor de pe care vei primi mail: ";
					for (;;)
					{
						c = _getch();
						if (c == 13)
							break;
						if (c != '\b')
						{
							passkey += c;
							cout << "*";
						}
						else if (passkey.length() > 0 && c == '\b')
						{
							passkey.pop_back();
							cout << "\b \b";
						}
					}
					string cmd = "py main.py \"" + string(denumireEv) + "\" \"" + string(data) + "\" \"" + string(ora) + "\" \"" + denumireLoc + "\" \"" + nume + "\" \"" + to_string(rand) + "\" \"" + to_string(loc) + "\" \"" + converteste_intArr_in_string(bilete[(rand - 1) * nrMaximLocuri + loc - 1].getUID(), bilete[(rand - 1) * nrMaximLocuri + loc - 1].getDimUID()) + "\" \"" + sender_mail + "\" \"" + sender_pass + "\" \"" + mail + "\" \"" + passkey + "\"";
					cout << "\nAi Python instalat pe dispozitivul tau? (Y/N): ";
					cin >> c;
					if (c == 'Y' || c == 'y')
					{
						cout << "Instalare pachete necesare executarii script-ului...\n";
						system("py -m pip install -r req.txt");
						cout << "\nPachetele au fost instalate cu succes.\n";
						cout << "Executare main.py...\n";
						system(cmd.c_str());
						cout << "\nScriptul a fost executat. Verifica-ti mail-ul!";
						cin.ignore();
						cin.clear();
					}
					else
					{
						cout << "Instalare Python...\nAstept permisiunea de a instala Python...Uita-te in taskbar!\n";
						system("Python.exe /quiet PrependPath=1");
						cout << "Instalarea a fost efectuata cu succes!\n";
						cout << "Instalare pachete necesare executarii script-ului...\n";
						system("py -m pip install -r req.txt");
						cout << "\nPachetele au fost instalate cu succes.\n";
						cout << "Executare main.py...\n";
						system(cmd.c_str());
						cout << "Scriptul a fost executat. Verifica-ti mail-ul!\n";
						cout << "Vrei sa stergi Python de pe dispozitivul tau? Recomand sa n-o faci, e un limbaj de programare super! :) (Y/N): ";
						cin >> c;
						if (c == 'Y' || c == 'y')
						{
							cout << "Stergere Python... Urmeaza pasii din interfata grafica pentru a dezinstala Python!\n";
							system("Python.exe");
							cout << "Python a fost sters cu succes!\n";
						}
						cin.ignore();
						cin.clear();
					}
				}
				else
				{
					cout << "Bilet cumparat cu succes! Noteaza-ti UID-ul undeva, vei avea nevoie de el pentru a-ti verifica biletul!\n";
					int* UID = bilete[(rand - 1) * nrMaximLocuri + loc - 1].getUID();
					unsigned dimUID = bilete[(rand - 1) * nrMaximLocuri + loc - 1].getDimUID();
					cout << "UID: ";
					for (unsigned int i = 0; i < dimUID; i++)
						cout << UID[i];
					cin.ignore();
					cin.clear();
				}
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
void Zona::cumparaBilet(const char* denumireEv, const char* data, const char* ora, string denumireLoc, int rand, int loc, bool pe_mail, string mail, string nume)
{
	if(nrBilete == nrLocuri)
	{
		cout << "Nu mai sunt locuri disponibile in zona " << nume << "!\n";
		return;
	}
	if (rand - 1 > 0 && rand - 1 <= nrMaximRanduri)
		if (loc - 1 > 0 && loc - 1 <= nrMaximLocuri)
			if (bilete[(rand - 1) * nrMaximLocuri + loc - 1].getUID() == nullptr)
			{
				bilete[(rand - 1) * nrMaximLocuri + loc - 1] = Bilet(nume.c_str(), rand - 1, loc - 1);
				if (pe_mail)
				{
					if (!verifica_mail(mail))
					{
						cout << "Mail invalid!\n";
						return;
					}
					string passkey;
					cout << "Introdu passkey-ul pentru decriptarea credentialelor de pe care vei primi mail: ";
					char c;
					for (;;)
					{
						c = _getch();
						if (c == 13)
							break;
						if (c != '\b')
						{
							passkey += c;
							cout << "*";
						}
						else if (passkey.length() > 0 && c == '\b')
						{
							passkey.pop_back();
							cout << "\b \b";
						}
					}
					string cmd = "py main.py \"" + string(denumireEv) + "\" \"" + string(data) + "\" \"" + string(ora) + "\" \"" + denumireLoc + "\" " + to_string(rand) + " " + to_string(loc) + " " + converteste_intArr_in_string(bilete[(rand - 1) * nrMaximLocuri + loc - 1].getUID(), bilete[(rand - 1) * nrMaximLocuri + loc - 1].getDimUID()) + " \"" + ENC_MAIL + "\" \"" + ENC_PASS + "\" " + mail + " " + passkey;
					cout << "Instalare pachete necesare executarii script-ului...\n";
					system("py -m pip install -r req.txt");
					cout << "\nPachetele au fost instalate cu succes.\n";
					cout << "Executare main.py...\n";
					system(cmd.c_str());
					cout << "\nScriptul a fost executat. Verifica-ti mail-ul!";
					cin.ignore();
					cin.clear();
				}
				else
				{
					cout << "Bilet cumparat cu succes! Noteaza-ti UID-ul undeva, vei avea nevoie de el pentru a-ti verifica biletul!\n";
					int* UID = bilete[(rand - 1) * nrMaximLocuri + loc - 1].getUID();
					unsigned dimUID = bilete[(rand - 1) * nrMaximLocuri + loc - 1].getDimUID();
					cout << "UID: ";
					for (unsigned int i = 0; i < dimUID; i++)
						cout << UID[i];
				}
				nrBilete++;
			}
			else
				cout << "Loc deja ocupat!\n";
		else
			cout <<"Loc inexistent!\n";
	else
		cout << "Rand inexistent!\n";
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
void Zona::verificaBilet(string UID)
{
	for (int i = 0; i < nrMaximLocuri * nrMaximRanduri; i++)
		if (bilete[i].getUID())
			if (converteste_intArr_in_string(bilete[i].getUID(), bilete[i].getDimUID()) == UID)
				cout << "Biletul este valid!\n";
			else
				cout << "Biletul nu este valid!\n";
}
void Zona::salveazaInFisier(ofstream& out)
{
	int length = nume.length();
	out.write((char*)&length, sizeof(int));
	out.write(nume.c_str(), length + 1);
	out.write((char*)&nrLocuri, sizeof(int));
	out.write((char*)&nrMaximRanduri, sizeof(int));
	out.write((char*)&nrMaximLocuri, sizeof(int));
	out.write((char*)&nrBilete, sizeof(int));
	for (unsigned int i = 0; i < nrMaximLocuri * nrMaximRanduri; i++)
		if (bilete[i].getUID() != nullptr)
			bilete[i].salveazaInFisier(out);
}
void Zona::restaureazaDinFisier(ifstream& in)
{
	int length;
	in.read((char*)&length, sizeof(int));
	char* buffer = new char[length + 1];
	in.read(buffer, length + 1);
	nume = buffer;
	delete[] buffer;
	in.read((char*)&nrLocuri, sizeof(int));
	in.read((char*)&nrMaximRanduri, sizeof(int));
	in.read((char*)&nrMaximLocuri, sizeof(int));
	in.read((char*)&nrBilete, sizeof(int));
	if (bilete)
		delete[] bilete;
	bilete = new Bilet[nrMaximRanduri * nrMaximLocuri];
	for (unsigned int i = 0; i < nrBilete; i++)
	{
		in.read((char*)&length, sizeof(int));
		buffer = new char[length + 1];
		in.read(buffer, length + 1);
		unsigned int nrRand;
		in.read((char*)&nrRand, sizeof(unsigned int));
		unsigned int nrLoc;
		in.read((char*)&nrLoc, sizeof(unsigned int));
		unsigned int dimUID;
		in.read((char*)&dimUID, sizeof(unsigned int));
		int* UID = new int[dimUID];
		in.read((char*)UID, dimUID * sizeof(unsigned int));
		unsigned int id;
		in.read((char*)&id, sizeof(int));
		bilete[nrRand * nrMaximLocuri + nrLoc].restaureazaDinFisier(buffer, nrLoc, nrRand, dimUID, UID, id);
	}
}