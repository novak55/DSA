#include "pch.h"
#include "Product.h"
#include <stddef.h>


Product::Product(int cislo, int cena, int pocet)
{
	this->cislo = cislo;
	this->cena = cena;
	this->pocet = pocet;
	this->pNext = NULL;
}

Product::~Product()
{
}
