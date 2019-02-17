#include "Plansza.h"
#include <windows.h>
#include <cstdlib>
using namespace std;
void Plansza::wypisz()
{
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); //czyszczenie konsoli
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0;j < 9; j++)
		{
			if (wsp[0] == i && wsp[1] == j)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << plansza[j][i] << " ";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				cout << plansza[j][i] << " ";
			}
			if ((j + 1) % 3 == 0) cout << "  ";    // odziela kolumny kwadrat�w
			if (j == 8) cout << endl;            // na ko�cu daje now� linie
			if (j == 8 && (i + 1) % 3 == 0) cout << endl; // odziela wiersze kwadrat�w
		}
	}
}
void Plansza::wstaw(char w)
{
	w -= 48;
	if (w >=1&&w<=9) //jesliwarto�ci� wstawian� nie jest zero
	{
		if (can_insert(wsp[1],wsp[0],w)) //sprawdza logike gry
		{
			plansza[wsp[1]][wsp[0]] = w; //jesli zadza se za�ozeniami to wstawia warto��
			wypisz();
		}
		else
		{
			wypisz();
		}
	}
	else if (w==0)
	{
		plansza[wsp[1]][wsp[0]] = w; //wstawia warto�� 0
		wypisz();
	}
	else
	{
		wypisz();
	}
}
void Plansza::ruch(char kierunek)
{
	switch (kierunek)
	{
	case 'w': //g�ra
		if (wsp[0] > 0)
		{
			--wsp[0]; //zmiejszenie warto�ci y
			wypisz();
		}
		break;
	case 's'://d�
		if (wsp[0] < 8)
		{
			++wsp[0]; //zwi�kszenie wartosci y
			wypisz();
		}
		break;
	case 'a': //lewo
		if (wsp[1] > 0)
		{
			--wsp[1]; //zmiejszenie warto�ci X
			wypisz();
		}
		break;
	case 'd': //prawo
		if (wsp[1] <8)
		{
			++wsp[1]; //zmiejszenie warto�ci X
			wypisz();
		}
		break;
	default:
		wypisz();
		break;
	}
}
Plansza::Plansza()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			plansza[j][i] = 0; //uzupe�nia plansze zerami
		}
	}
	wsp[0] = 0; //wsp Y
	wsp[1] = 0; //wsp X
}
bool Plansza::can_insert(int x, int y, int value) {
	for (int i = 0; i < 9; i++) {
		if (value == plansza[x][i] || value == plansza[i][y] ||
			value == plansza[x / 3 * 3 + i % 3][y / 3 * 3 + i / 3]) return false; //jesli warto�� juz sie znajduje (w pionie/poziomie/danym kwadracie) to zwraca false
	} return true;
} //czy mozna wstawi�
