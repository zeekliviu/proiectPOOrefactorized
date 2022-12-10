#include <iostream>
#include "Eveniment.h"
#include "MaestruEveniment.h"
using namespace std;
int main()
{
	MaestruEveniment m1;
	MaestruEveniment m2("Gigel", 1);
	MaestruEveniment m3(m2);
	MaestruEveniment m4;
	m4 = m3;
	cout << m1.getNume() << endl;
	cout << m2.getNume() << endl;
	cout << m3.getNume() << endl;
	cout << m4.getNume() << endl;
	return 0;
}
