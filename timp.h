#pragma once
#include <iostream>
using namespace std;
class timp
{
private:
	int ora, minut;
	bool flag;
public:
	timp();
	timp(int);
	timp(int, int);
	timp(const timp&);
	timp& operator=(const timp&);
	friend ostream& operator<<(ostream&, timp);
	friend istream& operator>>(istream&, timp&);
	timp& operator-(const timp&); // ca sa scadem 2 timpi
	bool operator<=(const timp&); // ca sa verificam daca un timp este mai mic sau egal cu alt timp
	bool getFlag();
	bool verificaOra();
	bool verificaMinut();
	bool verificaTimp();
};

