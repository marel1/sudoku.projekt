#include "Lista.h"
#include <iostream>
#include <string>
using namespace std;
Lista::Lista()
{
	head = nullptr;
}
void Lista:: operator +(const string &n) //operator dodania do listy
{
	ElementL*element = new ElementL(n);
	if (!head) head = element;
	else
	{
		ElementL*help = head;
		while (help->next != nullptr)
		{
			help = help->next;
		}
		help -> next = element;
	}
}
Lista::~Lista()
{
	while(head!=nullptr)
	{
		ElementL*help = head;
		delete head;
		help = help->next;
		head = help;

	}
}
void Lista::operator -(const string &n)
{
	if (head->nazwa == n)
	{
		ElementL*help = head;
		head = head->next;
		delete help;
		
	}
	else
	{
		ElementL*help = head;
		while (help->next->nazwa != n) help = help->next;
		ElementL*help2 = help->next;
		help->next = help->next->next;
		delete help2;
	}
}
void Lista::wypisz()
{
	if (head)
	{
		ElementL*help = head;
		while (help != nullptr)
		{
			cout << help->nazwa << endl;
			help = help->next;
		}
	}
}
Lista::Lista(ElementL*next, string n) :head(new ElementL(next, n)) {}
