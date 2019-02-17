#pragma once
#ifndef Plansza_h
#define Plansza_h
#include <iostream>
#include "Wczytanie.h"

class Plansza :public Wczytanie
{

public:
	void wypisz();
	void wstaw(char );
	void ruch(char );
	//game logic
	bool can_insert(int x, int y, int value);
	//czy mozna wstawiæ
	Plansza();
	
};
#endif