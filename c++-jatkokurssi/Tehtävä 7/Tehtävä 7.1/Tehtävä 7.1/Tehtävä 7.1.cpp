// Tehtävä 7.1.cpp : Defines the entry point for the console application.
// Heikki  Siikavirta 17.7.2016
/*
Luo yhteen suuntaan ketjutettu lista, jonka alkio pitää sisällään henkilöiden nimiä.

Lisää listaan 5 jäsentä ja tulosta lista.

*/

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct HENKILO
{
	char nimi[15];
	struct HENKILO * seur;
}solu;


void tulostalista(solu *li)
{
	solu * apu;
	cout << "\nListan tulostus: \n";
	for (apu = li; apu != NULL;apu = apu->seur)
	{
		cout << apu->nimi << "\n";
	}
}
int main()
{


	solu * li;
	solu * merkki;

	merkki = new(solu);
	merkki->seur = NULL;
	li = merkki;

	cout << "Anna ensimmaisen ihmisen nimi ";
	cin >> merkki->nimi;
	



	solu * uusiIhminen;

	for (int i = 0; i < 5; i++)
	{
		uusiIhminen = new(solu);
		uusiIhminen->seur = merkki->seur;
		merkki->seur = uusiIhminen;
		merkki = uusiIhminen;
		cout << "Anna uuden auton nimi \n";
		cin >> uusiIhminen->nimi;
	}

	tulostalista(li);

	cin.get();
	cin.get();

	return 0;
}

