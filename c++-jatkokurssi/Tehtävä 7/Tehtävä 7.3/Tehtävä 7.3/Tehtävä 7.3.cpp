// Teht‰v‰ 7.3.cpp : Defines the entry point for the console application.
//Lis‰‰ teht‰viin 1 ja 2 alkioiden lis‰ys alkuun, loppuun ja keskelle.
// Heikki Siikavirta 26.7.2016
// ‰ = \x84 ja ˆ = \x94 

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct HENKILO
{
	char nimi[15];
	struct HENKILO * seur;
	struct HENKILO * edell;

}solu;

struct HENKILO * alku;





void Print()
{
	HENKILO * temp = alku;
	while (temp != NULL)
	{
		printf("%s ", temp->nimi);
		temp = temp->seur;
	}
	printf("\n");
}
void Insert(int data, int n)
{
	HENKILO  * temp1 = new HENKILO();
	sprintf(temp1->nimi, "Nimi %d", data);
	temp1->seur = NULL;
	if (n == 1)
	{
		temp1->seur = alku;
		alku = temp1;
		return;
	}

	HENKILO * temp2 = alku;

	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->seur;
	}

	temp1->seur = temp2->seur;
	temp2->seur = temp1;
}


int main()
{
	alku = NULL;
	// Luodaan viiden ihmisen lista
	Insert(1, 1);
	Insert(2, 2);
	Insert(3, 3);
	Insert(4, 4);
	Insert(5, 5); // Nimi 1, Nimi 2, Nimi 3, Nimi 4, Nimi 5

				  // List‰t‰‰n nimi alkuun
	Insert(6, 1); // Nimi 6 laitetaan kohtaan 1
				  // List‰t‰‰n nimi keskelle
	Insert(7, 3); // Nimi 7 lis‰t‰‰n keskelle kohtaan 3
				  // List‰t‰‰n nimi loppuun
	Insert(8, 8); // Nimi 8 lis‰t‰‰n loppuun kohtaan 8

	Print();
	tulostalistaK(alku);

	std::cin.get();
	std::cin.get();

	return 0;
}


