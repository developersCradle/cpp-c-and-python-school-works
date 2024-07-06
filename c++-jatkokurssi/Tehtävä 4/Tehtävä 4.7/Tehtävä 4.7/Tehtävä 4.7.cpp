// Tehtävä 4.7.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 5.7.2016
// Seuraavassa on Quicksort-funktio, jonka sanotaan olevan kaikkein nopeimman lajittelumenetelmän: Kokeile sitä!
// a)500000 alkiota, kerta 1: 360 millisekuntia kerta 2: 344 millisekuntia kerta 3: 453 millisekuntia
// MISSÄ TEHTÄVÄSSÄ  4.4 Shell- lajittelulla saatiin kun alkiot olivat suuruudeltaan samat
// kerta 1: 2156 millisekuntia kerta 2 : 2438 millisekuntia kerta 3 : 2234 millisekuntia
// https://www.youtube.com/watch?v=ZZuD6iUe3Pc Quicksort näyttäisi olevan hyvä vaihtoehto, tehokkuus näytti riippuvan järjesteltävästä datasta.

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

#define MAARA 500000

int taulukko[MAARA];

using namespace std;

void vaihda(int * arvo1, int * arvo2)
{
	int temp;
	temp = *arvo1;
	*arvo1 = *arvo2;
	*arvo2 = temp;
}


void lajittele(int eka, int viime, int luvut[]) // quicksort

{

	int alku, vasen, oikea, temp;

	vasen = eka;

	oikea = viime;

	alku = luvut[(eka + viime) / 2];

	do

	{

		while (luvut[vasen] < alku)

			vasen = vasen + 1;

		while (alku < luvut[oikea])

			oikea = oikea - 1;

		if (vasen <= oikea)

		{

			vaihda(&(luvut[vasen]), &(luvut[oikea]));

			vasen = vasen + 1;

			oikea = oikea - 1;

		}
		
	}

	while ((oikea > vasen));

	if (eka < oikea) lajittele(eka, oikea, luvut);

	if (vasen < viime) lajittele(vasen, viime, luvut);

}


int main()
{
	cout << "====================================================" << endl;
	cout << "Testataan Quicsort- functiota ja otetaan ajat ylös" << endl;
	cout << "====================================================" << endl;


	cout << "Ohjelma generoi " << MAARA << " satunnaisesti luotua lukua" << endl;
	DWORD start, end;
	start = GetTickCount(); // GetTickCount Winukan oma ajan laskenta
	time_t aika;
	aika = time(NULL);



	srand((unsigned int)time(&aika));

	for (int i = 0; i < MAARA; i++)
	{

		taulukko[i] = (rand() % 100) + 1;


	}

	lajittele(0, MAARA - 1, taulukko);


	end = GetTickCount();

	
	cout << "Käyetty aika " << (double)(end - start) << " millisekuntia kayttaen windowsin toimintoa" << endl;


	

	cin.get();
    return 0;
}

