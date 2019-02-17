#include "Wczytanie.h"
#include <iostream>

using namespace std;
void Wczytanie::operator >>(const string nazwa_pliku) //wczytuje do tablicy plik z nierozwi¹zanym sudoku
{
	int a;
	ifstream plik;
	plik.open(nazwa_pliku);

	if (!plik) {
		cout << "blad" << endl;
	}
	else
	{
		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				plik >> a; //wczytuje wartoœæ z pliku
				this->plansza[j][i] = a;
			}
		}
		plik.close();
	}
}
void Wczytanie::operator<<(const string nazwa_pliku)
{
	int a;
	ofstream plik;
	plik.open(nazwa_pliku);
	if (!plik) {
		cout << "blad" << endl;
	}
	else
	{
		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				a = plansza[j][i]; //pobiera wartosc z tablicy
				plik << a; //zapisuje j¹ w pliku
				plik << " ";
			}
			plik << endl;
		}
		cout << "zapisano"<<endl;
		plik.close();
	}

}
Wczytanie::Wczytanie()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			plansza[j][i] = 0; //uzupe³nia plansze zerami
		}
	}
	wsp[0] = 0; //wsp Y
	wsp[1] = 0; //wsp X
}

Wczytanie&Wczytanie::operator=(Wczytanie&other)
{
	if (this != &other)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				
				plansza[j][i] = other.plansza[j][i];
			}
		}
		wsp[0] = other.wsp[0];
		wsp[1] = other.wsp[1];
		
	
	}
	cout << "operator przeniesienia zosta wywo³any" << endl;
	return*this;
}
bool Wczytanie::operator==(const Wczytanie&other)
{
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (plansza[j][i] != other.plansza[j][i]) return false;
		}
	}
	return true;
}

void Wczytanie::setPlansza(int j, int i, int w)
{
	plansza[j][i] = w;
}
int Wczytanie::getPlansza(int j,int i)
{
	return plansza[j][i];
}