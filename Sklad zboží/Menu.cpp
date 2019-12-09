#include "Menu.h"

	string* popis;
	char* volba;
	int polozekMenu;

	Menu::Menu(int pocetPolozekMenu) {
		polozekMenu = pocetPolozekMenu;
		popis = new string[polozekMenu];
		volba = new char[polozekMenu];

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


	void Menu::getPolozkuMenu(int pozice) {
		cout << " " << volba[pozice] << " - " << popis[pozice] << endl;
	}

	void Menu::getPopisPolozkyMenuDleVolby(char volbaPolozky) {
		for (int i = 0; i < polozekMenu; i++) {
			if (volba[i] == volbaPolozky) {
				getPopisPolozkyMenu(i);
				break;
			}
		}
	}

	void Menu::getPopisPolozkyMenu(int pozice) {
		cout << popis[pozice] << endl;
	}

	void Menu::ZobrazitPolozkyMenu() {
		cout << ("------------- MENU --------------\n");
		for (int i = 0; i < polozekMenu; i++) {
			if (popis[i] != "null")
				getPolozkuMenu(i);
		}
		cout << "---------------------------------\nZvolete moznost z menu:";
	}