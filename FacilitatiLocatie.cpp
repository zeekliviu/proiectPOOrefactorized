#include "FacilitatiLocatie.h"
FacilitatiLocatie::FacilitatiLocatie() : Locatie()
{
	areBar = false;
	areRestaurant = false;
	areToaleta = false;
	areParcare = false;
}
FacilitatiLocatie::FacilitatiLocatie(const string& nume, int nrPersoane, bool areBar, bool areRestaurant, bool areToaleta, bool areParcare) : Locatie(nume, nrPersoane)
{
	this->areBar = areBar;
	this->areRestaurant = areRestaurant;
	this->areToaleta = areToaleta;
	this->areParcare = areParcare;
}
FacilitatiLocatie::FacilitatiLocatie(const FacilitatiLocatie& f) : Locatie(f)
{
	areBar = f.areBar;
	areRestaurant = f.areRestaurant;
	areToaleta = f.areToaleta;
	areParcare = f.areParcare;
}
FacilitatiLocatie::~FacilitatiLocatie()
{
}
FacilitatiLocatie& FacilitatiLocatie::operator=(const FacilitatiLocatie& f)
{
	if (this != &f)
	{
		Locatie::operator=(f);
		areBar = f.areBar;
		areRestaurant = f.areRestaurant;
		areToaleta = f.areToaleta;
		areParcare = f.areParcare;
	}
	return *this;
}
ostream& operator<<(ostream& out, const FacilitatiLocatie& f)
{
	out << (Locatie)f;
	out << "Are bar: " << f.areBar << endl;
	out << "Are restaurant: " << f.areRestaurant << endl;
	out << "Are toaleta: " << f.areToaleta << endl;
	out << "Are parcare: " << f.areParcare << endl;
	return out;
}
istream& operator>>(istream& in, FacilitatiLocatie& f)
{
	in >> (Locatie&)f;
	cout << "Are bar: ";
	in >> f.areBar;
	cout << "Are restaurant: ";
	in >> f.areRestaurant;
	cout << "Are toaleta: ";
	in >> f.areToaleta;
	cout << "Are parcare: ";
	in >> f.areParcare;
	return in;
}
bool FacilitatiLocatie::getAreBar()
{
	return areBar;
}
bool FacilitatiLocatie::getAreRestaurant()
{
	return areRestaurant;
}
bool FacilitatiLocatie::getAreToaleta()
{
	return areToaleta;
}
bool FacilitatiLocatie::getAreParcare()
{
	return areParcare;
}
void FacilitatiLocatie::setAreBar(bool areBar)
{
	this->areBar = areBar;
}
void FacilitatiLocatie::setAreRestaurant(bool areRestaurant)
{
	this->areRestaurant = areRestaurant;
}
void FacilitatiLocatie::setAreToaleta(bool areToaleta)
{
	this->areToaleta = areToaleta;
}
void FacilitatiLocatie::setAreParcare(bool areParcare)
{
	this->areParcare = areParcare;
}
void FacilitatiLocatie::salveazaInFisier(ofstream& out)
{
	Locatie::salveazaInFisier(out);
	out << areBar << endl;
	out << areRestaurant << endl;
	out << areToaleta << endl;
	out << areParcare << endl;
}
void FacilitatiLocatie::restaureazaDinFisier(ifstream& in)
{
	Locatie::restaureazaDinFisier(in);
	in >> areBar;
	in >> areRestaurant;
	in >> areToaleta;
	in >> areParcare;
}