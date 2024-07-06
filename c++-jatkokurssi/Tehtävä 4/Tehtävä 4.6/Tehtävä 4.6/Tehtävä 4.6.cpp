// Tehtävä 4.6.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 5.7.2016
//Laita taulukkoon 10 henkilön nimeä ja lajittele taulukko.
//Vinkki: jos käytät merkkijonojen tietotyyppinä char - taulukkoa tai - osoitinta, voit vertailla merkkijonoja strcmp() - funktiolla, jonka esittely sijaitsee string.h - otsikkotiedostossa;muutoin voit käyttää string - olioita, joiden käsittely on yksinkertaisempaa.


#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cout << "============================================" << endl;
	cout << "Ohjemla järjestelee string typpisen taulokon" << endl;
	cout << "============================================" << endl;



	
	string nimet[] = { "Rea", "Anssi", "Ritva",
		"Heikki", "Kauko", "Sirpa",
		"Tiina", "Rea", "Ahmed",
		"Taneli"};
	

	
	int z = sizeof(nimet) / sizeof(nimet[0]); // Palauttaa string- taulukon koon jotenkin. Ei toimi Heap muistissa kun käytetään pointtereita

	sort(nimet, nimet + z); // C++11 tukee



	for (int y = 0; y < z; y++) {
		cout << nimet[y] << endl;
	}

	cin.get();
    return 0;
}

