/*
29.6.2016 Heikki Siikavirta
Ohjelma generoi satunnaislukuja taulukkoon ja lajittelee sitten taulukon shell-lajittelulla.
Laita taulukkoon a) 50000, b) 500000  alkiota ja ja ota lajitteluajat esille ja tee ajoista taulukko.
Kokeile viel‰ suuremmillakin alkio m‰‰rill‰ (ehk‰ taulukko on silloin luotava dynaamisesti!). Prosessorina toimi Inter Cora 2 duo 2.80GHz
TAULUKKO shell-lajittelulla
a) kerta 1: 156 millisekuntia kerta 2: 157 millisekuntia kerta 3: 156 millisekuntia
b) kerta 1: 2156 millisekuntia kerta 2: 2438 millisekuntia kerta 3: 2234 millisekuntia


*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib> 
#include <Windows.h>
#include <time.h>



using namespace std;



void lajittele(int taulu[], int koko)	// shell lajittelu
{
	int k, valimatka, vaihto = 1;
	valimatka = koko / 2;
	cout << "Shell-lajittelu aloitettu" << endl;

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
				}

			}

		} while (vaihto);
	} while ((valimatka /= 2) > 0);

}



int _tmain(int argc, _TCHAR* argv[])
{
	// DYNAAMISESTI
	int koko;

	cin >> koko;

	int *taulukkoDyn = new int[koko];


	cout << "Ohjelma generoi " << koko << " satunnaisesti luotua lukua" << endl << "ja j‰rjest‰‰ luvut sek‰ etsii tietyn luvun" << endl;





	DWORD start, end;




	start = GetTickCount(); // GetTickCount Winukan oma ajan laskenta


	time_t alku, loppu;
	alku = time(NULL);



	srand((unsigned int)time(&alku)); //On hyv‰ kutsua vain kerran? Alustetaan satunnaislukugeneraattorin siemen luku. V‰ltet‰‰n k‰‰nt‰j‰n joku virhe kun cast‰t‰‰n unsigned int tyyppiseksi

	for (int i = 0; i < koko; i++)
	{

		taulukkoDyn[i] = (rand() % 100) + 1;


	}

	lajittele(taulukkoDyn, koko);

	//  TULOSTUSTA VARTEN
	
	for (int i = 0; i < koko; i++)
	{
	cout << taulukkoDyn[i] << endl;
	}
	

	/* TEHTƒVƒSSƒ EI KƒSKETƒ ETSIMƒƒN MITƒƒN
	int etsitty = binarySearch(taulukko, 50);

	if (etsitty != -1)
	{
	cout << "Luku lˆytyi kohdasta " << etsitty << endl;
	}
	else
	{
	cout << "error" << endl;
	}
	*/

	loppu = time(NULL);
	end = GetTickCount();

	cout << "K‰ytetty aika " << (loppu - alku) << " k‰ytt‰en time.h toimintoa time() " << endl;
	//todo(heikki)  josta saat sadasosat.
	cout << "K‰yetty aika " << (double)(end - start) << " millisekuntia kayttaen windowsin toimintoa" << endl;


	delete[] taulukkoDyn; // Koska se sijaitsee heapissa, pit‰‰ muistaa tuhota

	cin.get();
	cin.get();

	return 0;
}