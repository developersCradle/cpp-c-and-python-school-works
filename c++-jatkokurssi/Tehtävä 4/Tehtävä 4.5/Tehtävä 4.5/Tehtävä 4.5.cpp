// Tehtävä 4.5.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 1.7.2016
//Simuloi manuaalisesti vaihto- ja shell-lajittelua noin 6 alkion taulukolla. 
//Piirrä aina välitaulukko jokaisen muutoksen jälkeen. Katso mallia oppimateriaalista.

#include "stdafx.h"
#include <iostream>


using namespace std;


void vaihto(int * arvo1, int * arvo2)
{
	int temp;
	temp = *arvo1;
	*arvo1 = *arvo2;
	*arvo2 = temp;
}

int linhaku(string kaupungit[], string nimi)

{

	int i;

	for (i = 0; i<5; i++)

	{

		if (kaupungit[i] == nimi)

			return (i);

	}

	return 999;

}




void tulosta(int luvut[], int koko)
{
	for (int i = 0; i < koko; i++)
	{
		cout << luvut[i] << " ";
	}
		
	cout << endl;
}

void lajittele(int taulu[], int koko) // vaihto- lajittelu

{

	for (int i = 0; i < koko - 1; i++)

		for (int k = i + 1; k < koko; k++)

			if (taulu[i] > taulu[k])
			{

				vaihto(&taulu[i], &taulu[k]);
				tulosta(taulu, koko);

			}

}
void shellLajittelu(int taulu[], int koko) // shell- lajittelu
{
		int k, valimatka, vaihto = 1;
		valimatka = koko / 2;
		

		do
		{
			do
			{
				vaihto = 0;
				for (int k = 0; k < (koko - valimatka); k++)
				{
					if (taulu[k] > taulu[k + valimatka])
					{
						swap(taulu[k], taulu[k + valimatka]);
						vaihto = 1;
						tulosta(taulu, koko);
					}

				}

			} while (vaihto);
		} while ((valimatka /= 2) > 0);

}

int main()
{
	cout << "=========================================================" << endl;
	cout << "Ohejelma simuloi vaihto- ja shell-lajittelun askeleittain" << endl;
	cout << "=========================================================" << endl;

	int taulukko1[6] = { 9,6,5,8,2,4 };
	int taulukko2[6] = { 4,8,1,3,2,1 };
	cout << "Simuloidaan vaihto- lajittelu askeleittain " << endl;
	lajittele(taulukko1, 6);
	tulosta(taulukko1, 6);
	cin.get();
	system("cls");
	cout << "Simuloidaan shell- lajittelu askeleittan" << endl;
	shellLajittelu(taulukko2, 6);

	cin.get();

    return 0;
}

