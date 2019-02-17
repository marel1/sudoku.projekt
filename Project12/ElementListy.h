#ifndef ElementListy_h
#define ElementListy_h
#include<iostream>
#include <string>
using namespace std;
class ElementL
{
	
	
public:
	string nazwa;
	ElementL*next;
	ElementL(); //konstruktor bezargumentowy
	ElementL(string); //konstruktor jednoargumentowy
	ElementL(ElementL*, string); //konstruktor wieloargumentowy
};
#endif
//element listy stworzony do przechowywania nazwy pliku txt