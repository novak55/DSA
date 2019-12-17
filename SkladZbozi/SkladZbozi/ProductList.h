#pragma once
#include "Product.h"

class ProductList
{
private:
	Product* pHead; // ukazatel na hlavu seznamu
	int cislo;
	int cena;
	int pocet;
	string popis;

	// zadani hodnot polozky seznamu
	void InsertItemValues();


public:
	ProductList();
	~ProductList();

	//import udaju z parametru
	void SetData(int cislo, int cena, int pocet, string popis);

	// prida prvek s cislem produktu
	bool Add(int cislo, int cena, int pocet, string popis);

	// odstrani prvek seznamu s cislem produktu
	bool Remove(int value);

	// upravi hodnoty vybraneho produktu
	bool EditProduct();

	// vyhleda informace o vybranem produktu
	bool FindProduct(int cislo);

	// vytiskne seznam na standardni vystup
	void PrintList();

	// spocita celkovou hodnotu zbozi na sklade
	int CountSummary();

	// seradi seznam zbozi vzestupne podle ev. cisla
	void SortByKeyAsc();

	// seradi seznam zbozi sestupne podle ev. cisla
	void SortByKeyDes();

	// naimportuje data z externiho souboru
	bool ImportData();

	//ulo�en� dat do souboru
	bool ExportData();

	// zad�n� a kontrola vstupn�ch dat pro cel� ��sla v�t�� nebo rovna ne� po�adovan� minimum 
	int ReadNumericValue(int min);

};

