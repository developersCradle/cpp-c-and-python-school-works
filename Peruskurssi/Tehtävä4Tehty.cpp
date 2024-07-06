
/*
Kirjoita luokka Kirja, jolla on metodit tulosta(), kysy_tiedot() ja
rakentajafunktio, jolla  alustetaan  Kirja  –luokan  arvot
string  nimi=”Ohjelmointi”,
string tekija = ”omanimi”,
int maara = 1
ja double hinta = 12.50. 

Tee myöspääohjelma,  jolla  testataan  kolmen  Kirjan  tulostus
(joko  erillisinä  kirjoina  tai taulukkona kirjoista).

Heikki Siikavirta 14.12.2015


		Code page 865 (Nordic languages)
       \x84 = ä
	   \x94 = ö
*/

#include "stdafx.h"	// Visual studion omia juttuja?


#include <iostream>
#include <cstdlib> // tarvitaan rand() -funktiolle
#include <ctime> // tarvitaan time -funktiolle

using namespace std;






class Kirja
{
		public:
		char nimi[100]; 
		char tekija[100];
		int maara; 
		double hinta;

	Kirja()	// Oletus rakentaja
	{
		
		strcpy_s(nimi, "Ohjelmointi");
		strcpy_s(tekija, "Heikki Siikavirta");	// Visual Studio haluaa käyttää "turvallisempaa" _s (safe) kopiointia.
		maara = 1;
		hinta = 12.50;
	}
	
	
	
	void kysy_tiedot(void); // prototyyppi
	void tulosta(void); // prototyyppi
};



void Kirja::kysy_tiedot(void)
{

	cout << "Annetussa tiedoissa ei saa olla tyhji\x84 v\x84lej\x84! "; // Ohjelma lukee tyhjän välin "lopetus merkiksi", eikä poista painettua välilyöntiä muistista, josta seuraa ohjelma skippaa muut toiminpiteet.
	cout << endl << "----------------------------------------------" << endl << endl;
	cout << "Anna tuotteelle nimi: ";
	cin >> nimi;
	cout << endl;

	cout << "Montako kyseist\x84 tuotetta laitetaan: ";
	cin >> maara;
	cout << endl;

	cout << "Paljonko tahdot tuotteesta? ";
	cin >> hinta;
	cout << endl;

}

void Kirja::tulosta(void)
{
	
	cout << "Tuotteen nimi on : " << nimi << endl;
	
	cout << "Tuotteen tekij\x84 on : " << tekija << endl;
	
	cout << "Tuotteiden m\x84\x84r\x84 on: " << maara << endl;

	cout << "Tuotteen hinta on : " << hinta << endl << endl;
}




int main(void)
{
	Kirja kirja1, kirja2, kirja3;


	kirja1.kysy_tiedot();

	kirja1.tulosta();
	kirja2.tulosta();
	kirja3.tulosta();

	system("PAUSE");
	return 0;
}
