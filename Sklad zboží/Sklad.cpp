#include "Sklad.h"

Sklad::Sklad()
{
	if (this->nazev == "") {
		ZmenitNazevSkladu();
		//todo na��st data ze souboru
	}
}

Sklad::~Sklad()
{
}

void Sklad::ZmenitNazevSkladu() {
	cout << "Zadejte nazev skladu: ";
	getline(cin >> ws, nazev);
}

string Sklad::GetNazev() {
	return this->nazev;
}

void Sklad::SetNazev(string nazev) {
	this->nazev = nazev;
}

void Sklad::ZmenitSklad() {
	ZmenitNazevSkladu();
	//todo na��st data ze souboru
}
