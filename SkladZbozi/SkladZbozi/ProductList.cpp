#include "pch.h"
#include "ProductList.h"
#include <stddef.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * Konstruktor spojovan�ho seznamu
 */
ProductList::ProductList()
{
	pHead = NULL;
}


/**
 * Destruktor spojovan�ho seznamu
 */
ProductList::~ProductList()
{
	while (pHead != NULL)
	{
		Product *pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp; pTmp = NULL;
	}
}

/**
 * Provede nastaven� vlo�en�ch �daj� pro polo�ku zbo�� na sklad�
 * @param cislo Eviden�n� (identifika�n�) ��slo zbo��
 * @param cena  je cena dan�ho kusu zbo�� na sklad�
 * @param pocet zobrazuje po�et kus� zbo�� na sklad�
 * @param popis textov� popis dan�ho zbo��
 */
void ProductList::NacistUdaje(int cislo, int cena, int pocet, string popis)
{
	this->cislo = cislo;
	this->cena = cena;
	this->pocet = pocet;
	this->popis = popis;
}

/**
 * Provede p�id�n� z�znamu o zbo�� na sklad�
 * @param cislo Eviden�n� (identifika�n�) ��slo zbo��
 * @param cena  je cena dan�ho kusu zbo�� na sklad�
 * @param pocet zobrazuje po�et kus� zbo�� na sklad�
 * @param popis textov� popis dan�ho zbo��
 * @return Informace o �sp�chu p�id�n� z�znamu o zbo��
 */
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

/**
 * Provede odebr�n� z�znamu o zbo�� na sklad� podle jeho eviden�n�ho ��sla
 * @param cislo Eviden�n� (identifika�n�) ��slo zbo��
 * @return Informace o �sp�chu odebr�n� z�znamu o zbo��
 */
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

/**
 * Provede editaci z�znamu o zbo�� na sklad�
 * @return Informace o �sp�chu proveden� �pravy z�znamu
 */
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

/**
 * Provede vyhled�n� a zobrazen� informac� o zbo�� na sklad� podle jeho eviden�n�ho ��sla
 * @param cislo Eviden�n� (identifika�n�) ��slo zbo��
 * @return Informace o existenci z�znamu o zbo��
 */
bool ProductList::FindProduct(int cislo)
{
	Product *pTmp = pHead; // ukazatel na aktualni (nasledujici) prvek
	while ((pTmp != NULL))
	{
		if (pTmp->cislo == cislo) {
			cout << "Zbozi: " << pTmp->popis << ", cislo: " << pTmp->cislo << ", cena: " << pTmp->cena << "Kc, kusu: " << pTmp->pocet << endl;
			return true;
		}
		pTmp = pTmp->pNext;
	}
	return false;
}

/**
 * Provede v�pis informac� o v�ech polo�k�ch zbo�� na sklad�
 * Zobraz� n�zev zbo��, eviden�n� ��slo, cenu za kus a po�et kus�
 */
void ProductList::PrintList()
{
	Product *pTmp = pHead;
	while (pTmp != NULL)
	{
		cout << "Zbozi: " << pTmp->popis << ", cislo: " << pTmp->cislo << ", cena: " << pTmp->cena << "Kc, kusu: " << pTmp->pocet << endl;
		pTmp = pTmp->pNext;
	}
}

/**
 * Provede v�po�et celkov� sumy ceny zbo�� na sklad�
 * @return Celkov� suma ceny zbo�� na sklad�
 */
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

/**
 * Provede se�azen� produkt� ve spojovan�m seznamu vzestupn� podle hodnoty kl��e
 */
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

/**
 * Provede se�azen� produkt� ve spojovan�m seznamu sestupn� podle hodnoty kl��e
 */
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

/**
 * Provede import dat z extern�ho souboru do spojovan�ho seznamu
 * @return Informace o �sp�chu proveden� importu dat
 */
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
		
		try
		{
			Add(stoi(cisloS), stoi(cenaS), stoi(pocetS), popisS);
		}
		catch (exception)
		{
			dataInput.close();
			cout << "Sklad je prazdny, neni mozne nacist zadna data.\n" << endl;
			return false;
		}
	}
	PrintList();
	dataInput.close();
	return true;
}

/**
 * TODO
 *
 */
int ProductList::ZadatCiselnouHodnotu(int min = 0) {
	string s;
	int i;
	while (true)
	{
		try
		{
			cin >> s;
			i = stoi(s);
			if (i >= min)
				return i;
			else cout << "Zadana hodnota musi byt cele cislo vetsi nebo rovno " << min << ". Zadejte prosim znovu: ";
		}
		catch (invalid_argument & exception)
		{
			cout << "Nebylo zadano cislo. Zadejte prosim znovu: ";
		}
		catch (out_of_range & exception)
		{
			cout << "Cislo je prilis velke (nebo prilis male). Zadejte prosim znovu:  ";
		}
	}

}


/**
 * TODO
 */
void ProductList::VlozitUdaje() {
	cout << "Zadejte cislo produktu: ";
	this->cislo = ZadatCiselnouHodnotu(1);
	cout << "Zadejte cenu produktu: ";
	this->cena = ZadatCiselnouHodnotu(1);
	cout << "Zadejte pocet kusu produktu: ";
	this->pocet = ZadatCiselnouHodnotu(1);
	cout << "Zadejte popis produktu: ";
	getline(cin >> ws, this->popis);
}


/**
 * Provede export dat ze spojovan�ho seznamu zbo�� na sklad� do extern�ho souboru
 * @return Informace o �sp�chu proveden� exportu dat
 */
bool ProductList::ExportData() {
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