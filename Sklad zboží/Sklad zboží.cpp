// Sklad zboží.cpp - ZADÁNÍ
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

/* - diskuse
	
*/

#include <iostream>
#include <string>
#include "Menu.h"
#include "Sklad.h"
#include "ProduktList.h"

using namespace std;

int main()
{
	const int POCET_POLOZEK_MENU = 14;
	bool konec = true;
	char volba;

	Menu* menu = new Menu(POCET_POLOZEK_MENU);
	Sklad* sklad = new Sklad();
	ProduktList* pList = new ProduktList();

	//	Sklad* sklad = new ....
	
	menu->addPolozkuMenu("Pridat polozku do skladu", 'P', 0);
	menu->addPolozkuMenu("Odebrat polozku ze skaldu", 'O', 1);
	menu->addPolozkuMenu("Zruseni polozky s danym klicem", 'Z', 2);
	menu->addPolozkuMenu("Vypis prvku s danym klicem", 'V', 3);
	menu->addPolozkuMenu("zoBrazit sklad", 'B', 4);
	menu->addPolozkuMenu("Cena zbozi na skladu", 'C', 5);
	menu->addPolozkuMenu("zmenit Sklad", 'S', 5);
	menu->addPolozkuMenu("Konec SW", 'K', 10);
	
	while (konec) {

		system("CLS");

		cout << "********** Sklad zbozi **********" << endl << "  pracujete ve skladu: " << sklad->GetNazev() << endl << endl;
		menu->ZobrazitPolozkyMenu();
		cin >> volba;
		menu->getPopisPolozkyMenuDleVolby(volba);
		cout << "---------------------------------" << endl;

		switch (volba) {
			case 'k':
			case 'K':
				konec = false;
				break;
			case 'p':
			case 'P':
				pList->ZadatNovouPolozku();
				break;
			case 'o':
			case 'O':
				break;
			case 'b':
			case 'B':
				pList->ZobrazitPolozky();
				break;
			case 'z':
			case 'Z':
				break;
			case 'c':
			case 'C':
				pList->ZobrazitHodnotuSkladu();
				break;
			case 's':
			case 'S':
				sklad->ZmenitSklad();
				break;
			case 'v':
			case 'V':
				break;
			default:
				cout << "Vase volba nebyla rozpoznana!" << endl;
		}
		system("PAUSE");
	}
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
