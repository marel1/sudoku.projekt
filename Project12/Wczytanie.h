#pragma once
#ifndef Wczytanie_h
#define Wczytanie_h
#include <iostream>
#include <fstream>

using namespace std;
class Wczytanie
{	
	protected:
	int plansza[9][9];
	int wsp[2]; //wsp�rz�dne lokalizacji "kursora"

	public:
	
	void setPlansza(int , int , int );
	int getPlansza(int,int);
	Wczytanie();
	bool operator ==(const Wczytanie&); //operator por�wnania
	Wczytanie&operator=(Wczytanie&); //operator przypisania
	void  operator >>(const string ); //wczytanie do tablicy pliku
	void operator << (const string); //wypisanie tablicy do pliku
	
};

#endif