#include "solver.h"
#include <iostream>
using namespace std;



bool Solver::can_insert(int x, int y, int value) {
	for (int i = 0; i < 9; i++) {
		if (value == planszaRozwiazana[x][i] || value == planszaRozwiazana[i][y] ||
			value == planszaRozwiazana[x / 3 * 3 + i % 3][y / 3 * 3 + i / 3]) return false; //jesli wartoœæ juz sie znajduje (w pionie/poziomie/danym kwadracie) to zwraca false
	} return true;
} //czy mozna wstawiæ

bool Solver::next(int x, int y) { //przejscie do kolejnego
	if (x == 8 && y == 8) return true; //koniec wstawiania
	else if (x == 8) return solve(0, y + 1); //przechodzi do kolejnej kolumny
	else return solve(x + 1, y); //przechodzi do kolejnego wiersza
}
bool Solver::solve(int x, int y) {
	if (zachowajPlanszeWczytana[x][y] == 0) { //jeœli pole jest puste
		for (int i = 1; i <= 9; i++) {
			if (can_insert(x, y, i)) { //sprawdz czy mozna wstawic wartoœci od 1 do 9
				planszaRozwiazana[x][y] = i; //ustaw t¹ wartoœæ
				if (next(x, y)) return true; //wstaw i przejdz do nastepnego
			}
		} planszaRozwiazana[x][y] = 0; return false; //jesli nie mozna wstawic, pozostaw 0
	} return next(x, y); //jesli nie 0 przejdz do nastepnego
}
void Solver::rozwiazanie()
{
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			planszaRozwiazana[j][i] = zachowajPlanszeWczytana[j][i];
			
		}
	}

	if (solve(0, 0)) //wywo³anie funkcji  
	{
		cout << "znaleziono rozwiazanie" << endl;
		system("cls"); //wyczyszczenie konsoli
		for (int i = 0; i < 9; i++) { //wypisanie planszyRozwiazanej
			for (int j = 0; j < 9; j++) {
				cout << planszaRozwiazana[j][i] << " ";
			if ((j + 1) % 3 == 0) cout << "  ";    // odziela kolumny kwadratów
			if (j == 8) cout << endl;            // na koñcu daje now¹ linie
			if (j == 8 && (i + 1) % 3 == 0) cout << endl; // odziela wiersze kwadratów
			} 
		}
	}
	else {
		cout << "rozwiazanie niemozliwe \n";
	}
}
void Solver::zapiszPlansze()
{
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			zachowajPlanszeWczytana[j][i] = sudoku.getPlansza(j,i);

		}
	}
}
void Solver::resetuj()
{
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			sudoku.setPlansza(j, i, (zachowajPlanszeWczytana[j][i]));
		}
	}
}