#pragma once
#include <string>
#include <iostream>

using namespace std;

class Sklad
{
public:
	Sklad();
	~Sklad();

	string GetNazev();
	void SetNazev(string nazev);
	void ZmenitSklad();

private:
	string nazev = "";
	void ZmenitNazevSkladu();

};
