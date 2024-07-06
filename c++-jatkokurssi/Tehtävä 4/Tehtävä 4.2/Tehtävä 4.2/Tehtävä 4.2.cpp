// Tehtävä 4.2.cpp  TEHTÄVÄSSÄ YHDISTETTY TEHTÄVÄ 4.3, koska binäärihaussa pitää olla järjestetyt alkiot ja tässä tehtävässä se tulee tehtyä
// Heikki Siikavirta 20.6.2016
//Ohjelma generoi satunnaislukuja taulukkoon ja hakee sitten tiettyä arvoa taulukosta binäärihaulla. Tehtävä 4.3 myös
//Laita taulukkoon a) 10000, b) 50000, c) 100000 alkiota ja hae tiettyä lukua. Ota hakuajat esille ja tee ajoista taulukko.
// Vaihda MAARA testataksesi muita lukuja. Prosessorina toimi Inter Cora 2 duo 2.80GHz
/*TAULUKKO vaihtolajittelulla ja samalla binäärihaku
a) kerta 1: 187 millisekuntia kerta 2: 203 millisekuntia kerta 3: 172 millisekuntia
b) kerta 1: 4384 millisekuntia kerta 2: 4134 millisekuntia kerta 3: 4181 millisekuntia
c) kerta 1: 16568 millisekuntia kerta 2: 16520 millisekuntia kerta 3: 16489 millisekuntia
*/
//ä = \x84 ja ö = \x94
#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <Windows.h>
#include <time.h>




#define MAARA 100000

using namespace std;

int binarySearch(int taulukko[], int etsitty)	//Hakee arvon ja tyytyy ensimmäiseen oikeeseen osumaan
{
	cout << "Bin\x84\x84ri haku aloitettu " << "haetaan lukua " << etsitty << endl;

	int yla = MAARA - 1;
	int ala = 0;
	int keski;
	int keskiAlkio;

	do
	{
		keski = (yla + ala) / 2;
		keskiAlkio = taulukko[keski];
		if (etsitty < keskiAlkio)
		{
			yla = keski - 1;
		}
		else
		{
			ala = keski + 1;
		}
	} while (!(etsitty == keskiAlkio || ala > yla));
	return (etsitty == keskiAlkio) ? keski : -1;
}

void lajittele(int taulu[])	// vaihto lajittelu
{
	cout << "Vaihto lajittelu aloitettu" << endl;

	for (int i = 0; i < MAARA - 1; i++)

		for (int k = i + 1; k < MAARA; k++)

			if (taulu[i] > taulu[k])

			{

				int temp = taulu[k];

				taulu[k] = taulu[i];

				taulu[i] = temp;

			}
}



int _tmain(int argc, _TCHAR* argv[])
{



	cout << "Ohjelma generoi " << MAARA << " satunnaisesti luotua lukua" << endl << "ja j\x84rjest\x84\x84 luvut sek\x84 etsii tietyn luvun" << endl;
	DWORD start, end;

	int taulukko[MAARA];
	int * tpointer = taulukko;

	start = GetTickCount(); // GetTickCount Winukan oma ajan laskenta


	time_t alku, loppu;
	alku = time(NULL);



	srand((unsigned int)time(&alku)); //Alustetaan satunnaislukugeneraattorin siemen luku, ÄLÄ KUTSU UUDESTAAN. Vältetään data hävikki("possible loss of data")
									  //kun castätään unsigned int tyyppiseksi.

	for (int i = 0; i < MAARA; i++)
	{

		taulukko[i] = (rand() % 100) + 1;


	}

	lajittele(taulukko);
	// Visualisointia varten
	/*
	for (int i = 0; i < MAARA; i++)
	{
		cout << taulukko[i] << endl;
	}
	*/ 
	int etsitty = binarySearch(taulukko, 39); // haetaan 39, binäärihaku

	if (etsitty != -1)
	{
		cout << "Luku l\x94ytyi kohdasta " << etsitty << endl;
	}
	else
	{
		cout << "error" << endl;
	}

	loppu = time(NULL);
	end = GetTickCount();

	cout << "K\x84ytetty aika " << (loppu - alku) << " k" << "\x84ytt\x84" << "en time.h toimintoa time() " << endl;
	//todo(heikki)  time.h josta saat sadasosat.
	cout << "K\x84ytetty aika " << (double)(end - start) << " millisekuntia k\x84yttaen windowsin toimintoa" << endl;



	cin.get();
	cin.get();

	return 0;
}