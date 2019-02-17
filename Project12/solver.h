#pragma once
#ifndef solver_h
#define solver_h
#include "Plansza.h"
class Solver
{
	
	protected:
	int planszaRozwiazana[9][9]; //tablica kt�ra przechowa rozwi�zane sudoku
	int zachowajPlanszeWczytana[9][9]; //tablica stworzona na potrzeby przechowywania nierozwi�zanej tablicy sudoku (bez zmian wprowadzanych przez gracza)
	public:
	Plansza sudoku;
	void zapiszPlansze();
	bool can_insert(int, int, int); //sprawdzanie czy mzona rozwi�za�
	bool next(int, int); //przejscie do kolejnego
	bool solve(int, int); //rozwi�zanie
	void rozwiazanie(); //wywo�anie rozwi�zania i sprawdzenie czy mo�na rozwi�za�
	void resetuj(); //plansza przyjmuje warto�ci zachowanej planszy
};
#endif