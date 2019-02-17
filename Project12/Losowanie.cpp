#include"Losowanie.h"
#include <cstdlib>
#include <ctime>
void Losowanie::dodajDoListy()
{
	
	lista + "latwe.txt";
	lista + "latwe2.txt";
	lista + "latwe3.txt";
	lista + "latwe4.txt";
	lista + "latwe5.txt";
	lista + "latwe6.txt";
	lista + "srednie.txt";
	lista + "srednie2.txt";
	lista + "srednie3.txt";
	lista + "srednie4.txt";
	lista + "srednie5.txt";
	lista + "srednie6.txt";
	lista + "trudne.txt";
	lista + "trudne2.txt";
	lista + "trudne3.txt";
	lista + "trudne4.txt";
	lista + "trudne5.txt";
	lista + "trudne6.txt";
	licznik += 18;


}
string Losowanie::random()
{
	dodajDoListy();
	start();
	int wylosowana_liczba;
	srand(time(NULL));
	wylosowana_liczba = (std::rand() % (licznik)) + 1;
	int input;
	input = getchar();
	ElementL*help = lista.head;
	
	for (int i = 0; i < wylosowana_liczba; i++)
		{
			help = help->next;
		}


	return help->nazwa;
}
Losowanie::Losowanie()
{
	licznik==0;
}
void Losowanie::dodaj(string nazwa)
{
	lista + nazwa;
	licznik++;
}
void Losowanie::usun(string nazwa)
{
	lista - nazwa;
	licznik--;
}
void Losowanie::start()
{
	
	char input;
	
	do
	{
	cout << "jesli chcesz dodaæ plansze wybierz 1 i wpisz nazwe pliku textowego: " << endl;
	cout << "jesli chcesz usunac plansze wybierz 2 i wpisz nazwe pliku textowego: " << endl;
	cout << "by zaczac wcisnij 3" << endl;
		input = getchar();
		if (input == 1)
		{
			string nazwa;
			cin >> nazwa;
			dodaj(nazwa);
		}
		else if (input == 2)
		{
			string nazwa;
			cin >> nazwa;
			usun(nazwa);
		}
	} while (input != '3');
}