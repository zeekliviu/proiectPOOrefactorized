#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Abstract
{
public:
	virtual void citesteFisier(ifstream&) = 0;
	virtual void salveazaInFisier(ofstream&) = 0;
};

