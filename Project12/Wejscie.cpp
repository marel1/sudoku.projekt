#include "Wejscie.h"

bool Wejscie::jestcyfra(char c) //sprawdza czy wprowadzony znak jest cyfr¹
{
	if (c >= 48 && c<= 57)return true;
	else return false;
}
bool Wejscie::jestkierunek(char c)
{
	if (c == 'w' || c == 'a' || c == 's' || c == 'd') return true;
	else return false;
}
bool Wejscie::jestrozwiazanie(char c)
{
	if (c == 'p') return true;
	else return false;
}
bool Wejscie::reset(char c)
{
	if (c == 'o') return true;
	else return false;
}