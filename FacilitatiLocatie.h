#pragma once
#include "Locatie.h"
class FacilitatiLocatie :
    public Locatie
{
private:
	bool areBar;
	bool areRestaurant;
	bool areToaleta;
	bool areParcare;
public:
	FacilitatiLocatie();
	FacilitatiLocatie(const string&, int, bool, bool, bool, bool);
	FacilitatiLocatie(const FacilitatiLocatie&);
	~FacilitatiLocatie();
	FacilitatiLocatie& operator=(const FacilitatiLocatie&);
	friend ostream& operator<<(ostream&, const FacilitatiLocatie&);
	friend istream& operator>>(istream&, FacilitatiLocatie&);
	bool getAreBar();
	bool getAreRestaurant();
	bool getAreToaleta();
	bool getAreParcare();
	void setAreBar(bool);
	void setAreRestaurant(bool);
	void setAreToaleta(bool);
	void setAreParcare(bool);
	void salveazaInFisier(ofstream&);
	void restaureazaDinFisier(ifstream&);
};

