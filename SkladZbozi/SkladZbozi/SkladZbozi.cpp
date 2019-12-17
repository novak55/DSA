#include "pch.h"
#include <iostream>
#include <fstream>
#include "ProductList.h"
#include <string>

using namespace std;

ProductList* pList = new ProductList();

/**
* Zobrazení položek a hodnot voleb menu
* @return Zadanou hodnotu menu na vsd. vstupu
*/
int menu()
{
	printf("1 ... Nacist data z CSV\n");
	printf("2 ... Vlozit novy zaznam\n");
	printf("3 ... Upravit zaznam\n");
	printf("4 ... Odebrat zaznam\n");
	printf("5 ... Najit zbozi\n");
	printf("6 ... Vytisknout seznam produktu\n");
	printf("7 ... Spocitat celkovou cenu zbozi\n");
	printf("8 ... Seradit produkty podle Ev. cisla vzestupne\n");
	printf("9 ... Seradit produkty podle Ev. cisla sestupne\n");
	cout << "10 .. Ulozit sklad do souboru" << endl;
	printf("0 ... KONEC\n\n");

	int volba;
	do
	{
		printf("Zadej volbu: ");
		volba = pList->ReadNumericValue(0);
	} while (volba != 0 && volba != 1 && volba != 2 && volba != 3 && volba != 4 && volba != 5 && volba != 6 && volba != 7 && volba != 8 && volba != 9 && volba != 10);
	return volba;
}


/**
* Řídí běh programu dle zvoleného menu
*/
int main()
{
	bool seznamNacten = false;
	int volba;
	int cislo;

	do
	{
		volba = menu();
		switch (volba)
		{
		case 1:
			// import dat z CSV souboru ...
			if (!seznamNacten) {
				seznamNacten = pList->ImportData();
				if (seznamNacten) printf("Seznam produktu byl uspesne nacten. \n\n");
			}
			else {
				printf("Seznam produktu nelze nacist podruhe! \n\n");
			}
			break;
		case 2:
			// vlozit zbozi do skladu
			pList->Add(0, 0, 0, "0") ?
				cout << "Produkt vlozen do skladu.\n" << endl
				:
				cout << "Chyba! Produkt se nepodarilo ulozit do skladu.\n" << endl;
			break;

		case 3:
			// upravit zaznam
			pList->EditProduct() ?
				cout << "Produkt byl uspesne upraven.\n" << endl
				:
				cout << "Chyba! Produkt se nepodarilo upravit.\n" << endl;
			break;

		case 4:
			// odstranit zaznam
			cout << "Zadejte cislo odebiraneho produktu: ";
			cislo = pList->ReadNumericValue(1);
			pList->Remove(cislo) ?
				printf("Produkt byl odebran! \n\n")
				:
				printf("Produkt nebyl odebran! \n\n");
			break;

		case 5:
			// vyhledat zbozi cislo
		{
			printf("Zadejte cislo hledaneho produktu: \n");
			cislo = pList->ReadNumericValue(1);
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
			printf("\nZbozi bylo serazeno vzestupne podle klice.\n\n");
		}
		break;
		case 9:
			// serazeni zbozi podle ...
		{
			pList->SortByKeyDes();
			printf("\nZbozi bylo serazeno sestupne podle klice.\n\n");
		}
		break;
		case 10:
			// uložení do souboru CSV :)
			pList->ExportData();
			break;
		}
	} while (volba != 0);

	// uloží všechna data do souboru při opuštění programu
	pList->ExportData();

	delete pList;

	return 1;
}