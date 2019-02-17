#pragma once
#ifndef solver_h
#define solver_h
#include "Plansza.h"
class Solver
{
	
	protected:
	int planszaRozwiazana[9][9]; //tablica która przechowa rozwi¹zane sudoku
	int zachowajPlanszeWczytana[9][9]; //tablica stworzona na potrzeby przechowywania nierozwi¹zanej tablicy sudoku (bez zmian wprowadzanych przez gracza)
	public:
	Plansza sudoku;
	void zapiszPlansze();
	bool can_insert(int, int, int); //sprawdzanie czy mzona rozwi¹zaæ
	bool next(int, int); //przejscie do kolejnego
	bool solve(int, int); //rozwi¹zanie
	void rozwiazanie(); //wywo³anie rozwi¹zania i sprawdzenie czy mo¿na rozwi¹zaæ
	void resetuj(); //plansza przyjmuje wartoœci zachowanej planszy
};
#endif