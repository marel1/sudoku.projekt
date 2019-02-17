#include "ElementListy.h"
#include <iostream>
using namespace std;
ElementL::ElementL()
{
	nazwa = "";
	next = nullptr;
}

ElementL::ElementL(string n)
{
	nazwa = n;
	next = nullptr;
}
ElementL::ElementL(ElementL*head, string n)
{
	head->nazwa = n;
	head->next = nullptr;
}
