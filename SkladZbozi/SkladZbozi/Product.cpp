#include "pch.h"
#include "Product.h"
#include <stddef.h>


/**
 * Konstruktor produktu na skladì
 * @param cislo Evidenèní (identifikaèní) èíslo zboží
 * @param cena  je cena daného kusu zboží na skladì
 * @param pocet zobrazuje poèet kusù zboží na skladì
 * @param popis textový popis daného zboží
 */
Product::Product(int cislo, int cena, int pocet, string popis)
{
	this->cislo = cislo;
	this->cena = cena;
	this->pocet = pocet;
	this->popis = popis;
	this->pNext = NULL;
}

/**
 * Destruktor produktu na skladì
 */
Product::~Product()
{
}
