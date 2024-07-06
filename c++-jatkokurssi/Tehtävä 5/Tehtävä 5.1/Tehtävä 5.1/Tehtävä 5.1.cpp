// Tehtävä 5.1.cpp : Defines the entry point for the console application.*+-*-ö


// Heikki Siikavirta 6.7.2016
//Sijoita taulukkoon mahdollisimman monta satunnaista kokonaislukua ja lajittele taulukko 
//a) shell-lajittelulla ja 
//b) STL-kirjaston sort-funktiolla. Ota lajitteluajat ylös.
/*TAULUKKO
a) 1 kerta: 202844 millisekuntia kerta 2: 175359 millisekuntia kerta 3: 212015 millisekuntia
b) 1 kerta: 1812 millisekuntia kerta 2: 2078 kerta 3: 1922 millisekuntia

tehtävä 5.2
Etsi Helpin kautta jokin standardin C++-kirjaston luokka tai funktio ja käytä sitä ohjelmassa.
Käytin vectori luokkaa.
*/

#include "stdafx.h"
#include <algorithm>
#include <cstdlib> 
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <vector>

#define MAARA 500000

using namespace std;
vector<int> taul;
// Elementin lisäys/poisto vektorin loppusta on nopeaa.
// Elementin lisäys/posito vektorin alusta tai keskeltä on hidasta.
// Elementi etsiminen on hidasta.
void lajittele(vector<int> * taulu)	
{
	long k, valimatka, vaihto = 1;
	valimatka = MAARA / 2;
	cout << "Shell-lajittelu aloitettu" << endl;
	
	do
	{
		do
		{
			vaihto = 0;
			for (long k = 0; k < (MAARA - valimatka); k++)
			{
			
				
                if (taulu->at(k) > taulu->at(k + valimatka))
				{
					
				
					/* ei toimi
					int temp = (*taulu)[k];
					(*taulu)[k] = (*taulu)[k+ valimatka];
					(*taulu)[k+valimatka] = temp;
					*/

					iter_swap(taulu->begin() + k, taulu->begin() + (k + valimatka));
					//swap ei toimi suoraan samassa vectorissa olevaan kahteen elementtii, käytä iter_swap
					//swap((*taulu)[k], (*taulu)[k + valimatka]); ei toimi
					vaihto = 1;
				}

			}

		} while (vaihto);
	} while ((valimatka /= 2) > 0);

}

int main()
{

	cout << "Ohjelma generoi " << MAARA << " satunnaisesti luotua lukua" << endl;
	DWORD start, end;
	start = GetTickCount(); 
	time_t alku, loppu;
	alku = time(NULL);
	srand((unsigned int)time(&alku));

	for (int i = 0; i < MAARA; i++)
	{

		taul.push_back((rand() % 100) + 1);
	}

	

	

	// Ei toiminut ilman pointterin tekoa
	vector<int> * p = &taul;
	sort(taul.begin(), taul.end());
	//lajittele(p); poista kommentit, shell lajittelua testataksesi

	loppu = time(NULL);
	end = GetTickCount();

	



	// Nykyään kuulemma STL- kirjaston iteraattorit ovat paljon tehokkaampia kuin
	// "Random access" mikä ikinä oikea tuo termi on suomeksi
	//  cout << taul[i]

	//Tulostusta varten:
	//for (vector<int>::iterator itr = taul.begin() ; itr != taul.end(); ++itr)
	//{
	//	cout << *itr << " ";
	//}

	cout << endl;
	cout << "Käytetty aika " << (loppu - alku) << " käyttäen time.h toimintoa time() " << endl;
	cout << "Käyetty aika " << (double)(end - start) << " millisekuntia kayttaen windowsin toimintoa" << endl;

	cin.get();
	cin.get();


	
	return 0;

}
