#include "pch.h"
#include "ProductList.h"
#include <stddef.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ProductList::ProductList()
{
	pHead = NULL;
}


ProductList::~ProductList()
{
	while (pHead != NULL)
	{
		Product *pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp; pTmp = NULL;
	}
}

// Místo tohoto naèítání dat ze souboru
/* 
void ProductList::MakeList(int p [][3], int cnt)
{
	Product *pTmp, *pLast;
	pLast = pHead;
	for (int i = 0; i < cnt; i++)
	{
		pTmp = new Product(p[i][0], p[i][1], p[i][2]);
		if (pHead == NULL)
			pHead = pLast = pTmp;
		else
		{
			pLast->pNext = pTmp;
			pLast = pTmp;
		}
	}
}
*/
void ProductList::NacistUdaje(int cislo, int cena, int pocet, string popis)
{
	this->cislo = cislo;
	this->cena = cena;
	this->pocet = pocet;
	this->popis = popis;
}

bool ProductList::Add(int cislo, int cena, int pocet, string popis)
{
	cislo == 0 ? VlozitUdaje() : NacistUdaje(cislo, cena, pocet, popis);

	Product *pNovyProdukt = new Product(this->cislo, this->cena, this->pocet, this->popis);

	Product *pPred = NULL; // ukazatel na predchazejici prvek

	Product *pTmp = pHead; // ukazatel na aktualni (nasledujici) prvek
	if (pHead == NULL)
	{
		// prazdny seznam
		pHead = pNovyProdukt;
		return true;
	}
	else
	{
		while (pTmp->pNext != NULL) {

			if (pTmp->cislo > this->cislo) {
				printf("%d\n", pTmp->cislo);
				break;
			}
			pPred = pTmp;
			pTmp = pTmp->pNext;
		}

		if (pPred == NULL && pTmp->pNext == NULL) { // pouze jeden druh zbozi zatim vlozeny

			if (pTmp->cislo < this->cislo) {
				pTmp->pNext = pNovyProdukt;
				pNovyProdukt->pNext = NULL;
			}
			else {
				pNovyProdukt->pNext = pTmp;
				pHead = pNovyProdukt;
			}
			return true;
		}
		if (pTmp->pNext == NULL) { // davame cislo na konec
			if (pTmp->cislo < this->cislo) {
				pTmp->pNext = pNovyProdukt;
				pNovyProdukt->pNext = NULL;
			}
			else {
				pPred->pNext = pNovyProdukt;
				pNovyProdukt->pNext = pTmp;
			}
			return true;
		}
		if (pPred == NULL) { // davame cislo na zacatek
			pNovyProdukt->pNext = pTmp;
			pHead = pNovyProdukt;
			return true;
		}
		// prvek je vkladan mezi jine prvky
		pPred->pNext = pNovyProdukt;
		pNovyProdukt->pNext = pTmp;
		return true;
	}
	return false;
}

bool ProductList::Remove(int cislo)
{
	Product *pPred = NULL; // ukazatel na predchazejici prvek
	Product *pTmp = pHead; // ukazatel na aktualni (nasledujici) prvek

	while ((pTmp != NULL) && (pTmp->cislo != cislo))
	{
		pPred = pTmp;
		pTmp = pTmp->pNext;
	}

	if (pTmp != NULL)
	{
		if (pTmp == pHead)	
			pHead = pTmp->pNext;
		else
			pPred->pNext = pTmp->pNext;

		delete pTmp;
		return true;
	}
	else
		return false;
}

bool ProductList::EditProduct()
{ 
	VlozitUdaje();
	Product *pTmp = pHead; // ukazatel na aktualni (nasledujici) prvek
	while ((pTmp != NULL))
	{
		if (pTmp->cislo == cislo) {
			pTmp->cena = cena;
			pTmp->pocet = pocet;
			pTmp->popis = popis;
			return true;
		}
		pTmp = pTmp->pNext;
	}
	return false;
}

bool ProductList::FindProduct(int cislo)
{
	Product *pTmp = pHead; // ukazatel na aktualni (nasledujici) prvek
	while ((pTmp != NULL))
	{
		if (pTmp->cislo == cislo) {
//			printf("Zbozi c.%d; cena: %d Kc; kusu: %d ks\n", pTmp->cislo, pTmp->cena, pTmp->pocet);
			cout << "Zbozi: " << pTmp->popis << ", cislo:" << pTmp->cislo << ", cena: " << pTmp->cena << "Kc, kusu: " << pTmp->pocet << endl;
			return true;
		}
		pTmp = pTmp->pNext;
	}
	return false;
}

void ProductList::PrintList() const
{
	Product *pTmp = pHead;
	while (pTmp != NULL)
	{
		cout << "Zbozi: " << pTmp->popis << ", cislo:" << pTmp->cislo << ", cena: " << pTmp->cena << "Kc, kusu: " << pTmp->pocet << endl;
		pTmp = pTmp->pNext;
	}
}


int ProductList::CountSummary()
{
	int summary = 0; // celkova cena zbozi na sklade
	Product * pTmp = pHead;
	while (pTmp != NULL) {
		summary += pTmp->cena * pTmp->pocet;
		pTmp = pTmp->pNext;
	}

	return summary;
}

void ProductList::SortByKeyAsc()
{
	Product * j;
	Product * i = pHead;

	for (i = pHead; i != NULL; i = i->pNext) {
		for (j = i->pNext; j != NULL; j = j->pNext) {
			if (i->cislo > j->cislo) {
				swap(i->cislo, j->cislo);
				swap(i->cena, j->cena);
				swap(i->pocet, j->pocet);
			}
		}
	}
}

void ProductList::SortByKeyDes()
{
	Product * j;
	Product * i = pHead;

	for (i = pHead; i != NULL; i = i->pNext) {
		for (j = i->pNext; j != NULL; j = j->pNext) {
			if (i->cislo < j->cislo) {
				swap(i->cislo, j->cislo);
				swap(i->cena, j->cena);
				swap(i->pocet, j->pocet);
			}
		}
	}
}

bool ProductList::ImportData()
{
	ifstream dataInput("data.csv");
	if (!dataInput.is_open()) {
		cout << "Chyba: Soubor neotevren!" << '\n';
		return false;
	}
	string cisloS;
	string cenaS;
	string pocetS;
	string popisS;
	while (dataInput.good()) {
		int soucet = 0;
		getline(dataInput, cisloS, ';');
		getline(dataInput, cenaS, ';');
		getline(dataInput, pocetS, ';');
		getline(dataInput, popisS, '\n');

/*		cout << "CISLO: " << cisloS << '\n';
		cout << "CENA: " << cenaS << '\n';
		cout << "POCET: " << pocetS << '\n';
		cout << "NAZEV: " << popisS << endl;
		soucet = stoi(cenaS) * stoi(pocetS);
		cout << "SOUCET: " << soucet << '\n';
		cout << "---------------" << '\n';*/
		Add(stoi(cisloS), stoi(cenaS), stoi(pocetS), popisS);
//		PrintList();
	}
	dataInput.close();
	return true;
}

void ProductList::VlozitUdaje() {
	cout << "Zadejte cislo produktu: ";
	cin >> cislo;
	//scanf_s("%d", &cislo);
	cout << "Zadejte cenu produktu: ";
	scanf_s("%d", &cena);
	cout << "Zadejte pocet kusu produktu: ";
	scanf_s("%d", &pocet);
	cout << "Zadejte popis produktu: ";
	getline(cin >> ws, popis);
}

bool ProductList::UlozitDataDoSoboru() {
	fstream soubor("data.csv", ios::out);
	if (!soubor.is_open()) {
		cout << "Chyba: Soubor neotevren!" << '\n';
		return false;
	}
	Product* pTmp = pHead;
	bool novyRadek = false;
	while (pTmp != NULL) {
		if (novyRadek)
			soubor << endl; 
		else novyRadek = true;
		soubor << pTmp->cislo <<";" << pTmp->cena << ";" << pTmp->pocet << ";" << pTmp->popis;
		pTmp = pTmp->pNext;
	}

	soubor.close();
	cout << "\nData jsou ulozena\n" << endl;
	return true;
}