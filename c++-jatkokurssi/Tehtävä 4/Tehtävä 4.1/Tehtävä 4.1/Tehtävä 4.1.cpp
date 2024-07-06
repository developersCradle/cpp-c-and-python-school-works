// Tehtävä 4.1.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 20.6.2016
//Ohjelma generoi satunnaislukuja taulukkoon ja hakee sitten tiettyä arvoa taulukosta lineaarihaulla.

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 

using namespace std;

int linhaku(int taulukko[], int haettava)

{

	int i;

	for (i = 0; i<10; i++)

	{

		if (taulukko[i] == haettava)

			return (i);

	}

	return 999;

}



int _tmain(int argc, _TCHAR* argv[])
{
	int taulukko[10];
	int * tpointer = taulukko;

	for (int i = 0; i < 10; i++)
	{
		taulukko[i] = (rand() % 100) + 1;

		cout << taulukko[i] << endl;
	}

	if ((linhaku(tpointer, 42) != 999))
	{
		cout << "luku loityi listasta" << endl;
	}
	else
	{
		cout << "luku ei ollut listassa" << endl;
	}


	cin.get();
	return 0;
}

