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
	printf("1 ... Nacist data z CSV\n");
	printf("2 ... Vlozit novy zaznam\n");
	printf("3 ... Upravit zaznam\n");
	printf("4 ... Odebrat zaznam\n");
	printf("5 ... Najit zbozi\n");
	printf("6 ... Vytisknou seznam produktu\n");
	printf("7 ... Spocitat celkovou cenu zbozi\n");
	printf("8 ... Seradit produkty podle Ev. cisla VZESTUPNE\n");
	printf("9 ... Seradit produkty podle Ev. cisla SESTUPNE\n");
	cout << "10 .. Ulozit sklad do souboru" << endl;
	printf("0 ... KONEC\n\n");

	int volba;
	do
	{
		printf("Zadej volbu: ");
		scanf_s("%d", &volba);
	} while (volba != 0 && volba != 1 && volba != 2 && volba != 3 && volba != 4 && volba != 5 && volba != 6 && volba != 7 && volba != 8 && volba != 9 && volba != 10);
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
			// uložení do souboru CSV :)
			pList->UlozitDataDoSoboru();
			break;
		}
	} while (volba != 0);

	// uloží všechna data do souboru při opuštění programu
	pList->UlozitDataDoSoboru();

	delete pList;
}