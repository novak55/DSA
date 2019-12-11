#include "pch.h"
#include "Product.h"
#include <stddef.h>


Product::Product(int cislo, int cena, int pocet, string popis)
{
	this->cislo = cislo;
	this->cena = cena;
	this->pocet = pocet;
	this->popis = popis;
	this->pNext = NULL;
}

Product::~Product()
{
}
