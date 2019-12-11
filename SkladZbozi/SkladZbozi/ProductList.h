#pragma once
#include "Product.h"

class ProductList
{
private:
	Product *pHead; // ukazatel na hlavu seznamu
	int cislo;
	int cena;
	int pocet;
	string popis;

	// zadani hodnot polozky seznamu
	void VlozitUdaje();



public:
	ProductList();
	~ProductList();

	// vytvori seznam z hodnot ulozenych v zadanem poli
	//void MakeList(int p[][3], int cnt);

	//import udaju z parametru
	void NacistUdaje(int cislo, int cena, int pocet, string popis);

	// prida prvek s cislem produktu
	bool Add(int cislo, int cena, int pocet, string popis);

	// odstrani prvek seznamu s cislem produktu
	bool Remove(int value);

	// upravi hodnoty vybraneho produktu
	bool EditProduct();

	// vyhleda informace o vybranem produktu
	bool FindProduct(int cislo);

	// vytiskne seznam na standardni vystup
	void PrintList() const;

	// spocita celkovou hodnotu zbozi na sklade
	int CountSummary();

	// seradi seznam zbozi vzestupne podle ev. cisla
	void SortByKeyAsc();

	// seradi seznam zbozi sestupne podle ev. cisla
	void SortByKeyDes();

	// naimportuje data z externiho souboru
	bool ImportData();
};

