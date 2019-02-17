#pragma once
#ifndef Losowanie_h
#define Losowanie_h
#include "Lista.h"
class Losowanie
{
	Lista lista;
	int licznik;
public:
	void dodajDoListy();
	string random();
	Losowanie();
	void dodaj(string);
	void usun(string);
	void start();
};
#endif