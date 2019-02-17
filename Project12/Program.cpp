#include "Program.h"
#include <string>
#include <iostream>
void Program::uzupelnianie()
{
		s.sudoku >> losowanie.random();
		s.sudoku.wypisz();
		s.zapiszPlansze(); //zapisuje nierozwiazane sudoku
		wskazowki();
}
void Program::gra()
{
	char input;
	do
	{
		input = getchar();
		if (wej.jestcyfra(input))
		{
			s.sudoku.wstaw(input);
			wskazowki();

		}
		else if (wej.jestkierunek(input))
		{
			s.sudoku.ruch(input);
			wskazowki();

		}
		else if (wej.jestrozwiazanie(input))
		{

			s.rozwiazanie();
			cout << "by wrocic do rozwiazania uzyj w a s d" << endl;
		}
		else if (wej.reset(input))
		{
			s.resetuj();
			s.sudoku.wypisz();
			wskazowki();

		}
		else if (input == 'z') //zapisuje do pliku
		{
			cout << "wprowadz nazwe pliku tekstowego" << endl;
			string nazwa;
			cin >> nazwa;
			s.sudoku << nazwa;
		}
		else if (input == 'x') //odczytuje z pliku
		{
			cout << "wprowadz nazwe pliku tekstowego" << endl;
			string nazwa;
			cin >> nazwa;
			s.sudoku >> nazwa;
			s.sudoku.wypisz();
		}
	} while (input != 'q');

}
void Program::wskazowki()
	{
	cout << "do poruszania sie po planszy uzywaj klawiszy w a s d" << endl
		<< "w-gora" << endl
		<< "s-dol" << endl
		<< "a-lewo" << endl
		<< "d-prawo" << endl
		<< "z-zapisz gre" << endl
		<< "x-wczytaj gre" << endl
		<< "q-wyjscie z gry" << endl 
		<< "p-pokaz rozwiazanie" << endl
		<< "o-resetuj gre" << endl;
	}
