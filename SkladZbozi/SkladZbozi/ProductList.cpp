#include "pch.h"
#include "ProductList.h"
#include <stddef.h>
#include <iostream>


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

bool ProductList::Add(int cislo, int cena, int pocet)
{
	Product *pNovyProdukt = new Product(cislo, cena, pocet);

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

			if (pTmp->cislo > cislo) {
				printf("%d\n", pTmp->cislo);
				break;
			}
			pPred = pTmp;
			pTmp = pTmp->pNext;
		}

		if (pPred == NULL && pTmp->pNext == NULL) { // pouze jeden druh zbozi zatim vlozeny

			if (pTmp->cislo < cislo) {
				pTmp->pNext = pNovyProdukt;
				pNovyProdukt->pNext = NULL;
			}
			else {
				pNovyProdukt->pNext = pTmp;
				pHead = pNovyProdukt;
			}
			printf("Produkt byl vlozen\n");
			return true;
		}
		if (pTmp->pNext == NULL) { // davame cislo na konec
			if (pTmp->cislo < cislo) {
				pTmp->pNext = pNovyProdukt;
				pNovyProdukt->pNext = NULL;
			}
			else {
				pPred->pNext = pNovyProdukt;
				pNovyProdukt->pNext = pTmp;
			}
			printf("Produkt byl vlozen\n");
			return true;
		}
		if (pPred == NULL) { // davame cislo na zacatek
			pNovyProdukt->pNext = pTmp;
			pHead = pNovyProdukt;
			printf("Produkt byl vlozen\n");
			return true;
		}
		// prvek je vkladan mezi jine prvky
			pPred->pNext = pNovyProdukt;
			pNovyProdukt->pNext = pTmp;
			printf("Produkt byl vlozen\n");
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

bool ProductList::EditProduct(int cislo, int cena, int pocet)
{ 
	Product *pTmp = pHead; // ukazatel na aktualni (nasledujici) prvek
	while ((pTmp != NULL))
	{
		if (pTmp->cislo == cislo) {
			pTmp->cena = cena;
			pTmp->pocet = pocet;
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
			printf("Zbozi c.%d; cena: %d Kc; kusu: %d ks\n", pTmp->cislo, pTmp->cena, pTmp->pocet);
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
		printf("Zbozi c.%d; cena: %d Kc; kusu: %d ks\n", pTmp->cislo, pTmp->cena, pTmp->pocet);
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
