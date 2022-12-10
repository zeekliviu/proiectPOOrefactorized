#pragma once
#include <iostream>
using namespace std;
class MaestruEveniment
{
private:
	string nume;
	int cod;
public:
	MaestruEveniment();
	MaestruEveniment(const string&, int);
	MaestruEveniment(const MaestruEveniment&);
	~MaestruEveniment();
	MaestruEveniment& operator=(const MaestruEveniment&);
	string getNume();
	int getCod();
};