#include "MaestruEveniment.h"
#include "AdminPassword.h"
#pragma warning(disable:4996)
#pragma warning(disable:6262)
using namespace std;
int main(int argc, char** argv)
{
	// PLAYGROUND //	
	
	// START PROGRAM //
	// restaurare date din fisier
	if (argc > 1)
	{
		MaestruEveniment m;
		// citire din fisier
		m.citireFisier(argv[1]);
	}
	else
	{
		MaestruEveniment m;
		cout << "Bun venit la The Ticketing App !\n";
		cout << "Autor: Liviu-Ioan Zecheru\n";
		cout << "Seria E, Grupa 1061\n";
		cout << "Versiunea: 1.0\n\n";
		cout << "Logare ca: user/admin\n";
		cout << "1. User\n";
		cout << "2. Admin\nAlegerea ta: ";
		int optiune;
		char cc, buf[USHRT_MAX];
		do
		{
			while (true)
			{
				if (!fgets(buf, sizeof buf, stdin))
					break;
				if (sscanf(buf, "%d %c", &optiune, &cc) != 1)
				{
					cout << "Optiune invalida! Mai incearca!\nAlegerea ta: ";
					continue;
				}
				break;
			}
			if (optiune != 1 && optiune != 2)
				cout << "Optiune invalida! Mai incearca!\nAlegerea ta: ";
		} while (optiune != 1 && optiune != 2);
		if (optiune == 2)
		{
			cout << "Introduceti parola: ";
			string parola{};
			char c;
			for (;;)
			{
				c = _getch();
				if (c == 13)
					break;
				if (c != '\b')
				{
					parola += c;
					cout << "*";
				}
				else if (parola.length() > 0 && c == '\b')
				{
					parola.pop_back();
					cout << "\b \b";
				}
			}
			if (parola == ADM_PWD)
			{
				cout << "\nParola corecta! Bine ai venit, Administrator!\n";
				m.setNume("Admin");
				m.setParola(parola);
			}
			else
			{
				cout << "\nParola incorecta! Te logam ca user.\n";
				m.setNume("User");
			}
		}
		else
		{
			cout << "Te-ai logat ca user!\n";
			m.setNume("User");
		}
		do
		{
			if (m.getNume() == "Admin")
			{
				cout << "\n============================== OPTIUNI PENTRU ADMIN ==============================\n";
				cout << "1. Adauga eveniment\n";
				cout << "2. Sterge eveniment\n";
				cout << "3. Modifica eveniment\n";
				cout << "============================== OPTIUNI PENTRU ADMIN ==============================\n\n";
			}
			cout << "\n============================== OPTIUNI PENTRU USER ==============================\n";
			cout << "4. Afiseaza evenimente\n";
			cout << "5. Cumpara bilet\n";
			cout << "6. Verifica bilet\n";
			cout << "============================== OPTIUNI PENTRU USER ==============================\n\n";
			cout << "0. Iesire\n\nAlegerea ta: ";
			do
			{
				while (true)
				{
					if (!fgets(buf, sizeof buf, stdin))
						break;
					if (sscanf(buf, "%d %c", &optiune, &cc) != 1)
					{
						system("cls");
						cout << "Optiune invalida! Mai incearca!\nAlegerea ta: ";
						continue;
					}
					break;
				}
				if (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 4 && optiune != 5 && optiune != 6 && optiune != 7 && optiune != 0)
					cout << "Optiune invalida! Mai incearca!\nAlegerea ta: ";
			} while (optiune != 1 && optiune != 2 && optiune != 3 && optiune != 4 && optiune != 5 && optiune != 6 && optiune != 7 && optiune != 0);
			if (optiune == 1)
				if (m.getNume() == "Admin")
					system("cls"), m.adaugaEveniment();
				else
					cout << "Nu ai dreptul sa adaugi evenimente!\n";
			else if (optiune == 2)
				if (m.getNume() == "Admin")
				{
					system("cls");
					if (m.afiseazaEvenimente())
					{
						cout << "Introduceti id-ul evenimentului pe care doriti sa-l stergeti: ";
						int id = 0;
						do
						{
							while (true)
							{
								if (!fgets(buf, sizeof buf, stdin))
									break;
								if (sscanf(buf, "%d %c", &id, &cc) != 1)
								{
									cout << "Id invalid! Mai incearca!\nId: ";
									continue;
								}
								break;
							}
							if (id < 0)
								cout << "Id invalid! Mai incearca!\nId: ";
						} while (id < 0);
						m.stergeEveniment(id);
					}
					else
						cout << "Nu exista evenimente!\n";
				}
				else
					cout << "Nu ai dreptul sa stergi evenimente!\n";
			else if (optiune == 3)
				if (m.getNume() == "Admin")
				{
					system("cls");
					if (m.afiseazaEvenimente())
					{
						cout << "Introduceti id-ul evenimentului pe care doriti sa-l modificati: ";
						int id;
						do
						{
							while (true)
							{
								if (!fgets(buf, sizeof buf, stdin))
									break;
								if (sscanf(buf, "%d %c", &id, &cc) != 1)
								{
									cout << "Id invalid! Mai incearca!\nId: ";
									continue;
								}
								break;
							}
							if (id < 0)
								cout << "Id invalid! Mai incearca!\nId: ";
						} while (id < 0);
						m.modificaEveniment(id);
					}
					else
						cout << "Nu exista evenimente!\n";
				}
				else
					cout << "Nu ai dreptul sa modifici evenimente!\n";
			else if (optiune == 4)
			{
				system("cls");
				if (!m.afiseazaEvenimente())
					cout << "Nu exista evenimente!\n";
			}
			else if (optiune == 5)
			{
				system("cls");

				if (!m.afiseazaEvenimente())
					cout << "Nu exista evenimente!\n";
				else
				{
					cout << "Introduceti id-ul evenimentului: ";
					int id;
					do
					{
						while (true)
						{
							if (!fgets(buf, sizeof buf, stdin))
								break;
							if (sscanf(buf, "%d %c", &id, &cc) != 1)
							{
								cout << "Id invalid! Mai incearca!\nId: ";
								continue;
							}
							break;
						}
						if (id < 0)
							cout << "Id invalid! Mai incearca!\nId: ";
					} while (id < 0);
					m.cumparaBilet(id);
				}
			}
			else if (optiune == 6)
			{
				system("cls");
				if (!m.afiseazaEvenimente())
					cout << "\t\t\tNu exista evenimente!\n\n";
				else
				{
					cout << "Introduceti id-ul evenimentului: ";
					int id;
					do
					{
						while (true)
						{
							if (!fgets(buf, sizeof buf, stdin))
								break;
							if (sscanf(buf, "%d %c", &id, &cc) != 1)
							{
								cout << "Id invalid! Mai incearca!\nId: ";
								continue;
							}
							break;
						}
						if (id < 0)
							cout << "Id invalid! Mai incearca!\nId: ";
					} while (id < 0);
					m.verificaBilet(id);
				}
			}
			else if (optiune == 0)
				system("cls"), cout << "Multumim ca ati apelat la serviciile noastre de ticketing. La revedere!\nMade with <3 by Zeek Liviu for Zeth Ticketing.\n";
		} while (optiune != 0);
	}
	return 0;
}
