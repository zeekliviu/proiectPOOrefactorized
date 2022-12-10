#include <iostream>
#include "Eveniment.h"
#include "MaestruEveniment.h"
#include "AdminPassword.h"
using namespace std;
int main()
{
	// Construire meniu
	Eveniment e;
	cin >> e;
	cout << e;
	/*
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
			if (sscanf_s(buf, "%d %c", &optiune, &cc) != 1)
			{
				cout << "Optiune invalida! Mai incearca!\nAlegerea ta: ";
				continue;
			}
			break;
		}
		if (optiune != 1 && optiune != 2)
			cout << "Optiune invalida! Mai incearca!\nAlegerea ta: ";
	}while(optiune != 1 && optiune != 2);
	if (optiune == 2)
	{
		cout << "Introduceti parola: ";
		string parola {};
		char c;
		for (;;)
		{
			c = _getch();
			if (c == 13)
				break;
			if (c!='\b')
			{
				parola += c;
				cout << '*';
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
		cout << "\n============================== OPTIUNI PENTRU ADMIN ==============================\n";
		cout << "1. Adauga eveniment\n";
		cout << "2. Sterge eveniment\n";
		cout << "3. Modifica eveniment\n";
		cout << "========================================================================\n\n";
		cout << "============================== OPTIUNI PENTRU USER ==============================\n";
		cout << "4. Cumpara bilet\n";
		cout << "5. Afiseaza bilete\n";
		cout << "6. Afiseaza evenimente\n";
		cout << "7. Verifica bilet\n";
		cout << "========================================================================\n\n";
		cout << "0. Iesire\n\nAlegerea ta: ";
		do
		{
			while (true)
			{
				if (!fgets(buf, sizeof buf, stdin))
					break;
				if (sscanf_s(buf, "%d %c", &optiune, &cc) != 1)
				{
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
				m.adaugaEveniment();
			else
				cout << "Nu ai dreptul sa adaugi evenimente!\n";
	} while (optiune != 0);*/
	return 0;
}
