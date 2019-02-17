#pragma once
#ifndef Program_h
#define Program_h
#include "Wejscie.h"
#include "Wczytanie.h"
#include "solver.h"
#include "Lista.h"
#include "Losowanie.h"
using namespace std;
class Program
{
	Losowanie losowanie;
	Solver s;
	Wejscie wej;
	public:
	void uzupelnianie();
	void gra();
	void wskazowki();
};
#endif Program_h
