// SkladZbozi.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "ProductList.h"
#include <string>

using namespace std;

ProductList* pList = new ProductList();

int menu()
{
	printf("1 ... Nacti seznam produktu\n");
	printf("2 ... Vlozit novy zaznam\n");
	printf("3 ... Upravit zaznam\n");
	printf("4 ... Odebrat zaznam\n");
	printf("5 ... Najit zbozi\n");
	printf("6 ... Vytisknou seznam produktu\n");
	printf("7 ... Spocitat celkovou cenu zbozi\n");
	printf("8 ... Seradit produkty podle Ev. cisla VZESTUPNE\n");
	printf("9 ... Seradit produkty podle Ev. cisla SESTUPNE\n");
	printf("10 .. Nacist data z CSV\n");
	cout << "11 .. Ulozit sklad do souboru" << endl;
	printf("0 ... KONEC\n\n");

	int volba;
	do
	{
		printf("Zadej volbu: ");
		scanf_s("%d", &volba);
	} while (volba != 0 && volba != 1 && volba != 2 && volba != 3 && volba != 4 && volba != 5 && volba != 6 && volba != 7 && volba != 8 && volba != 9 && volba != 10 && volba != 11);
	return volba;
}



int main()
{
	bool seznamNacten = false;

//	 int pole[][3] = { {2, 20, 1}, {4, 40, 1}, {1, 10, 1},{3, 30, 1},{5, 50, 1} }; // pole vstupnich udaju
	 int n = 5; // pocet produktu ve vstupnim poli 

	int volba;
	int cislo;

	do
	{
		volba = menu();
		switch (volba)
		{
		case 1:
			// nacist seznam
/*			{
				if (!seznamNacten) {
					pList->MakeList(pole, n);
					seznamNacten = true;
					printf("Seznam produktu byl uspesne nacten. \n\n");
				}
				else {
					printf("Seznam produktu nelze nacist podruhe! \n\n");
				}

			}
			break;
*/
		case 2:
			// vlozit zbozi do skladu
			pList->Add(0, 0, 0, "0") ?
				cout << "Produkt vlozen do skladu." << endl
				:
				cout << "Chyba! Produkt se nepodarilo ulozit do kladu" << endl;
			break;

		case 3:
			// upravit zaznam
			pList->EditProduct() ?
				cout << "Produkt byl uspesne upraven." << endl
				:
				cout << "Chyba! Produkt se nepodarilo upravit" << endl;
			break;

		case 4:
			// odstranit zaznam
			cout << "Zadejte cislo odebiraneho produktu: ";
			scanf_s("%d", &cislo);
			pList->Remove(cislo) ?
				printf("Produkt byl odebran! \n\n")
				:
				printf("Produkt nebyl odebran! \n\n");
			break;

		case 5:
			// vyhledat zbozi cislo
		{
			printf("Zadejte cislo hledaneho produktu: \n");
			scanf_s("%d", &cislo);
			printf("Vysledek hledani: \n");
			if (!pList->FindProduct(cislo)) {
				printf("Hledane zbozi nebylo nalezeno! \n");
			}

			printf("\n\n");
		}
		break;

		case 6:
			// tisk seznamu zbozi
		{
			printf("\nSEZNAM ZBOZI \n");
			pList->PrintList();
			printf("\n\n");
		}
		break;

		case 7:
			// vypocet celkove ceny zbozi
		{
			printf("Celkova suma ceny zbozi na sklade:\n");
			printf("SUMA: %d Kc\n", pList->CountSummary());
			printf("\n\n");
		}
		break;
		case 8:
			// serazeni zbozi podle ...
		{
			pList->SortByKeyAsc();
		}
		break;
		case 9:
			// serazeni zbozi podle ...
		{
			pList->SortByKeyDes();
		}
		break;
		case 10:
			// import dat z CSV souboru ...
			if (!seznamNacten) {
				pList->ImportData();
				seznamNacten = true;
				printf("Seznam produktu byl uspesne nacten. \n\n");
			}
			else {
				printf("Seznam produktu nelze nacist podruhe! \n\n");
			}
			break;
		case 11:
			//todo uložit do souboru CSV :)
			break;
		}
	} while (volba != 0);


	delete pList;





	//return 0;
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
