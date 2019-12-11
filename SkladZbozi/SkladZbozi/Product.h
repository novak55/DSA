#pragma once
#pragma once
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

class Product
{
private:
	int cislo;
	int cena;
	int pocet;
	string popis;
	Product *pNext; // ukazatel na nasledujici prvek


public:
	Product(int cislo, int cena, int pocet, string popis);
	~Product();

	friend class ProductList;
};

