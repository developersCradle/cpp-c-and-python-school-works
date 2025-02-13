// Teht�v� 7.3 yhteenSuun.cpp : Defines the entry point for the console application.
/*
Luo yhteen suuntaan ketjutettu lista, jonka alkio pit�� sis�ll��n henkil�iden nimi�.
Lis�� teht�viin 1 ja 2 alkioiden lis�ys alkuun, loppuun ja keskelle.
Lis�� listaan 5 j�sent� ja tulosta lista.
6.8.2016
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct HENKILO
{
	char nimi[15];
	struct HENKILO * seur;
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
void ReversePrint(struct HENKILO * p)
{
	if (p == NULL)
	{
		return;
	}
	
	ReversePrint(p->seur); // Recursive call
	printf("%s ", p->nimi);
	
}

void Delete(int n)
{
	struct HENKILO * temp1 = alku;
	if (n == 1)
	{
		alku = temp1->seur;
		delete(temp1);
		return;
	}

	int i;
	for (i = 0; i < n - 2; i++)
	{
		temp1 = temp1->seur;
	}

	struct HENKILO * temp2 = temp1->seur;
	temp1->seur = temp2->seur;
	delete temp2;
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
	

	// List�t��n nimi alkuun
	Insert(6, 1); // Nimi 6 laitetaan kohtaan 1
	// List�t��n nimi keskelle
	Insert(7, 3); // Nimi 7 lis�t��n keskelle kohtaan 3
	// List�t��n nimi loppuun
	Insert(8, 8); // Nimi 8 lis�t��n loppuun kohtaan 8
	

	Print();
	Delete(1); // Poistetaan paikasta 1
	Delete(4); // Poistetaan paiaksta 4

	Print();
	cout << "Nurinkurin" << endl;
	ReversePrint(alku);
	std::cin.get();
	std::cin.get();

	return 0;
}

