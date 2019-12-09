// Sklad zboží.cpp
// Napište program pro vedení a sledování skladu zboží.
// Sklad bude reprezentován jako tabulka, jejíž prvky budou obsahovat:
//	identifikační číslo zboží, název zboží, cenu zboží a počet kusů na skladě.
// Klíčem je identifikační číslo zboží.
// Zvolte vhodnou reprezentaci tabulky za předpokladu, že budou často do seznamu zařazovány nové skladové zásoby
// a odebírány již neplatné zásoby, počet zásob není předem znám.
// Operace:
//  -výpis prvku s daným klíčem 
//  - zrušení prvků s daným klíčem 
//  - výpis všech prvků seřazený podle identifikačního čísla 
//  - výpočet celkové ceny zboží
//

#include <iostream>
#include "menu.h"

using namespace std;

int main()
{
	const int POCET_POLOZEK_MENU = 14;
	bool konec = true;
	char volba;

	Menu* menu = new Menu(POCET_POLOZEK_MENU);

	menu->addPolozkuMenu("Pridat polozku do skladu", 'p', 0);
	menu->addPolozkuMenu("Odebrat polozku ze skaldu", 'o', 1);
	menu->addPolozkuMenu("Zruseni polozky s danym klicem", 'z', 2);
	menu->addPolozkuMenu("Vypis prvku s danym klicem", 'v', 3);
	menu->addPolozkuMenu("Konec", 'k', 4);
	

	while (konec) {
		cout << "********** Sklad zbozi **********" << endl;
		menu->ZobrazitPolozkyMenu();
		cin >> volba;
		cout << "---------------------------------" << endl;

		switch (volba) {
			case 'k':
			case 'K':
				konec = false;
				break;
			default:
				cout << "Vase volba nebyla rozpoznana!" << endl;
		}
		system("CLS");
	}
	cout << "Konec SW";
	delete menu;
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
