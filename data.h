#pragma once
#include <iostream>
using namespace std;
class data
{
private:
	int zi, luna, an;
public:
	data();
	data(const char*);
	data(char);
	data(int);
	data(int, const char*);
	data(int, const char*, const char*);
	data(int, char);
	data(int, char, char);
	data(int, int);
	data(int, int, int);
	data(const data&);
	data& operator=(const data&);
	friend ostream& operator<<(ostream&, data);
	friend istream& operator>>(istream&, data&);
	data& operator+(const data&); // ca sa adunam doua date calendaristice
	data operator--(); // ca sa scadem o zi dintr-o data calendaristica pre-incrementare
	data operator--(int); // ca sa scadem o zi dintr-o data calendaristica post-incrementare
	int getZi();
	int getLuna();
	int getAn();
	void setZi(int);
	void setLuna(int);
	void setAn(int);
	bool verificaData();
	bool isBisect(int);
};

