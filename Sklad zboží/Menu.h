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
	void getPolozkuMenu(int pozice);
	void getPopisPolozkyMenu(int pozice);
	void getPopisPolozkyMenuDleVolby(char volbaPolozky);
	void SetPopisNaNull();
	void addPolozkuMenu(string popisPolozky, char volbaPolozky, int pozice);
	void ZobrazitPolozkyMenu();
};