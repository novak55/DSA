#pragma once
#include "Product.h"

class ProductList
{
private:
	Product *pHead; // ukazatel na hlavu seznamu

public:
	ProductList();
	~ProductList();


	// vytvori seznam z hodnot ulozenych v zadanem poli
	void MakeList(int p[][3], int cnt);

	// prida prvek s cislem produktu
	bool Add(int cislo, int cena, int pocet);

	// odstrani prvek seznamu s cislem produktu
	bool Remove(int value);

	// upravi hodnoty vybraneho produktu
	bool EditProduct(int cislo, int cena, int pocet);

	// vytiskne seznam na standardni vystup
	void PrintList() const;

	// spocita celkovou hodnotu zbozi na sklade
	int CountSummary();
};

