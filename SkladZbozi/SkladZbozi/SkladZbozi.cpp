// SkladZbozi.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>

#include "ProductList.h"



int menu()
{
	printf("1 ... Nacti seznam produktu\n");
	printf("2 ... Vlozit novy zaznam\n");
	printf("3 ... Upravit zaznam\n");
	printf("4 ... Vytisknou seznam produktu\n");
	printf("5 ... Seradit produkty podle ...\n");
	printf("6 ... Seradit produkty podle ...\n");
	printf("0 ... KONEC\n\n");

	int volba;
	do
	{
		printf("Zadej volbu: ");
		scanf_s("%d", &volba);
	} while (volba != 0 && volba != 1 && volba != 2 && volba != 3 && volba != 4 && volba != 5 && volba != 6);
	return volba;
}



int main()
{
	ProductList * pList = new ProductList();
	 int pole[][3] = { {1, 10, 1},{2, 20, 1},{3, 30, 1},{4, 40, 1},{5, 50, 1} }; // pole vstupnich udaju
	 int n = 5; // pocet produktu ve vstupnim poli 

//	int pole[][3] = { {1, 10, 1} }; // pole vstupnich udaju
//	int n = 1; // pocet produktu ve vstupnim poli 

	int cislo;
	int cena;
	int pocet;

/*
		ProductList mList;
	int pole[][3] = { {1, 10, 1},{2, 20, 1},{3, 30, 1},{4, 40, 1},{5, 50, 1} };
	mList.MakeList(pole, 5);

	printf("Vypis puvodniho seznamu:\n");
	mList.PrintList();
	printf("\n\n");

	printf("Vypis po pridani do seznamu:\n");
	mList.Add(6, 60, 1);
	mList.PrintList();
	printf("\n\n");


	printf("Vypis po odebrani ze seznamu:\n");
	mList.Remove(7);
	mList.PrintList();
	printf("\n\n");

	printf("Celkova suma ceny zbozi na sklade:\n");
	printf("SUMA: %d Kc\n", mList.CountSummary());
	printf("\n\n");
*/



	int volba;
	do
	{
		volba = menu();
		switch (volba)
		{
		case 1:
			// nacist seznam
		{
			pList->MakeList(pole, n);
		}
			break;

		case 2:
			// vlozit zbozi do skladu
		{
			printf("Zadejte cislo produktu: \n");
			scanf_s("%d", &cislo);
			printf("Zadejte cenu produktu: \n");
			scanf_s("%d", &cena);
			printf("Zadejte pocet kusu produktu: \n");
			scanf_s("%d", &pocet);
			pList->Add(cislo, cena, pocet);
			printf("Produkt zadan. \n");
		}
			break;

		case 3:
			// upravit zaznam
		{
			printf("Zadejte cislo upravovaneho produktu: \n");
			scanf_s("%d", &cislo);
			printf("Zadejte novou cenu produktu: \n");
			scanf_s("%d", &cena);
			printf("Zadejte novy pocet kusu produktu: \n");
			scanf_s("%d", &pocet);

			if (pList->EditProduct(cislo, cena, pocet)) {
				printf("Produkt byl uspesne upraven. \n\n");
			}
			else {
				printf("Produkt nebyl upraven!! \n\n");
			}
		}
		break;

		case 4:
			// tisk seznamu zbozi
		{
			printf("\nSEZNAM ZBOZI \n");
			pList->PrintList();
			printf("\n\n");
		}
			
			break;

		case 5:
			// sort
			break;

		case 6:
			// sort
			break;

		}

	} while (volba != 0);


	//delete mList;





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
