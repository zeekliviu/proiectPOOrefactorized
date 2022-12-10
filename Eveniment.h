#include <iostream>
#include "Bilet.h"
using namespace std;
#pragma once
class Eveniment
{
private:
	char* denumire;
	const int nrMaximLocuri;
	static int nrEvenimente;
	int id;
public:
	Eveniment();
	Eveniment(const char*, int);
	Eveniment(const Eveniment&);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
};

