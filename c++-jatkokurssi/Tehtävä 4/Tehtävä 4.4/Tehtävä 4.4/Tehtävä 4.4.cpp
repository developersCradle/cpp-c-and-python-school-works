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




#define MAARA 500000

using namespace std;

int taulukko[MAARA];
// Ompa j‰nn‰, taulukkoa ei voi m‰‰ritell‰ koolla 500000 mainin sis‰ll‰ -> Vie liikaa tilaa pinosta, mutta globaalina toimii? 
// Todo -> voiko pinon kokoa kastattaa? voi antamalla k‰‰nt‰j‰lle omia atribuutteja. Luo taulukko heap muistiin miss‰ on enemm‰n tilaa.
int binarySearch(int taulukko[], int etsitty)	//Hakee arvon ja tyytyy ensimm‰iseen oikeeseen osumaan? Vaikka arvo ei ollut  loogisesti ensimm‰isess‰ taulukossa. 
{
	cout << "Bin‰‰ri haku aloitettu " << "haetaan lukua " << etsitty << endl;

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

void lajittele(int taulu[])	// shell lajittelu
{
	int k, valimatka, vaihto = 1;
	valimatka = MAARA / 2;
	cout << "Shell-lajittelu aloitettu" << endl;

	do
	{
		do
		{
			vaihto = 0;
			for (int k = 0; k < (MAARA - valimatka); k++)
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
	
	
	
	
	

	cout << "Ohjelma generoi " << MAARA <<  " satunnaisesti luotua lukua" << endl << "ja j‰rjest‰‰ luvut sek‰ etsii tietyn luvun" << endl;
	DWORD start, end;


	

	start = GetTickCount(); // GetTickCount Winukan oma ajan laskenta


	time_t alku, loppu;
	alku = time(NULL);



	srand((unsigned int)time(&alku)); //On hyv‰ kutsua vain kerran? Alustetaan satunnaislukugeneraattorin siemen luku. V‰ltet‰‰n k‰‰nt‰j‰n joku virhe kun cast‰t‰‰n unsigned int tyyppiseksi

	for (int i = 0; i < MAARA; i++)
	{

		taulukko[i] = (rand() % 100) + 1;


	}

	lajittele(taulukko);
	//  TULOSTUSTA VARTEN
	/*for (int i = 0; i < MAARA; i++)
	{
		cout << taulukko[i] << endl;
	}
	*/

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


	cin.get();
	cin.get();

	return 0;
}