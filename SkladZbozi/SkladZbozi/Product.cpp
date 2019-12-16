#include "pch.h"
#include "Product.h"
#include <stddef.h>


/**
 * Konstruktor produktu na sklad�
 * @param cislo Eviden�n� (identifika�n�) ��slo zbo��
 * @param cena  je cena dan�ho kusu zbo�� na sklad�
 * @param pocet zobrazuje po�et kus� zbo�� na sklad�
 * @param popis textov� popis dan�ho zbo��
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
 * Destruktor produktu na sklad�
 */
Product::~Product()
{
}
