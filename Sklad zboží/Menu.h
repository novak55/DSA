#pragma once
#include <string>
#include <iostream>

using namespace std;

class Menu {
private:
	string* popis;
	char* volba;
	int polozekMenu;

public:
	Menu(const int pocetPolozekMenu);
	~Menu();
	string getPolozkuMenu(int pozice);
	void SetPopisNaNull();
	void addPolozkuMenu(string popisPolozky, char volbaPolozky, int pozice);
	void ZobrazitPolozkyMenu();
};