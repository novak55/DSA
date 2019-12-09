#include "Menu.h"


	string* popis;
	char* volba;

	Menu::Menu(int pocetPolozekMenu) {
		popis = new string[pocetPolozekMenu];
		volba = new char[pocetPolozekMenu];
		SetPopisNaNull();
	}

	Menu::~Menu() {
		delete[] popis;
		delete[] volba;
	}

	void Menu::addPolozkuMenu(string popisPolozky, char volbaPolozky, int pozice) {
		if (pozice < 0 || pozice >= polozekMenu) {
			cout << "Polozku se do menu nepodarilo pridat" << endl;
		}
		else {
			popis[pozice] = popisPolozky;
			volba[pozice] = volbaPolozky;
		}
	}

	void Menu::SetPopisNaNull() {
		for (int i = 0; i < polozekMenu; i++) {
			addPolozkuMenu("null", ' ', i);
		}
	}


	string Menu::getPolozkuMenu(int pozice) {
		return volba[pozice] + " - " + popis[pozice];
	}

	void Menu::ZobrazitPolozkyMenu() {
		cout << ("------------- MENU --------------\n");
		for (int i = 0; i < polozekMenu; i++) {
			if (popis[i] != "null" )
				cout << getPolozkuMenu(i) << endl;
		}
		cout << "---------------------------------\nZvolete moznost z menu:";
	}