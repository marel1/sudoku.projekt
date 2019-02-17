#pragma once
#ifndef Lista_h
#define Lista_h
#include "ElementListy.h"
class Lista
{
	public:
		ElementL*head;
		void operator +(const string&); //operator dodaj¹cy do listy
		~Lista();
		void wypisz();
		void operator -(const string&); //operator usuwaj¹cy elem z listy
		Lista();
		Lista(ElementL*,string);
};
#endif