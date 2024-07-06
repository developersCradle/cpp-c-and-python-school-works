// Tehtävä 7.7.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 4.8.2016
//Toteuta oppimateriaalissa esitetyn puuohjelmaan funktio, jossa haetaan puusta tiettyä arvoa.
#include "stdafx.h"
#include <iostream>
#define TOSI 1
#define EITOSI 0
#define TYHJA '\0' // sama kuin NULL, NULL on nollan makro


typedef struct binpuu
{
	int luku;
	struct binpuu *oikeasolmu;
	struct binpuu *vasensolmu;
}puu;

puu *juuri, *nyk_solmu = NULL, *uusi_solmu = NULL;
void tulostapuu(puu *solmu);
int ota_luku();
int ota_alkuluku();

using namespace std;


bool Etsi(puu * juuri, int luku)
{
	if (juuri == NULL)
	{
		return false;
	}
	else if (juuri->luku == luku)
	{
		return true;
	}
	else if (luku <= juuri->luku)
	{
		return Etsi(juuri->vasensolmu, luku);
	}
	else
	{
		return Etsi(juuri->oikeasolmu, luku);
	}
}


int main()
{
	int antoluku;
	int lkm;
	int i;
	int ei_paikkaa;
	lkm = ota_alkuluku();


	juuri = new puu;	// Alustetaan juuri

	if (lkm > 0)       /* ensimmäinen arvo */
	{
		nyk_solmu = juuri;
		nyk_solmu->luku = ota_luku();
		nyk_solmu->oikeasolmu = TYHJA;
		nyk_solmu->vasensolmu = TYHJA;
	}



	for (i = 2; i <= lkm; i++)
	{
		antoluku = ota_luku();
		nyk_solmu = juuri;
		ei_paikkaa = TOSI;

		uusi_solmu = new (puu);

		uusi_solmu->luku = antoluku;
		uusi_solmu->oikeasolmu = TYHJA;
		uusi_solmu->vasensolmu = TYHJA;

		/* haetaan arvon sijainti puussa*/

		while (ei_paikkaa)
		{
			if (antoluku < nyk_solmu->luku)
			{
				if (nyk_solmu->vasensolmu == TYHJA)
					ei_paikkaa = EITOSI;
				else
				{
					nyk_solmu = nyk_solmu->vasensolmu;
				}
			}
			else if (nyk_solmu->oikeasolmu == TYHJA)
			{
				ei_paikkaa = EITOSI;
			}
			else
			{
				nyk_solmu = nyk_solmu->oikeasolmu;
			}
		}
		/* asetetaan uusi solmu omalle paikalleen*/
		if (antoluku < nyk_solmu->luku)
		{
			nyk_solmu->vasensolmu = uusi_solmu;
		}
		else
		{
			nyk_solmu->oikeasolmu = uusi_solmu;
		}
	}

	int numero;
	cout << "Anna numero mitä estitään\n";
	cin >> numero;
	if (Etsi(juuri, numero) == true)
	{
		cout << "Löytyi\n";
	}
	else
	{
		cout << "Ei löytynyt\n";
	}



	tulostapuu(juuri);

	cin.get();
	cin.get();
}

int ota_luku()
{
	int apu;
	cout << "anna luku puuhun \n";
	cin >> apu;
	return apu;
}
int ota_alkuluku()
{
	int apu;
	cout << "Kuinka monta lukua haluat? \n";
	cin >> apu;
	return apu;
}
void tulostapuu(puu * solmu)
{
	if (solmu->vasensolmu != TYHJA)
	{
		tulostapuu(solmu->vasensolmu);	// Rekursiivinen, muista varovaisuus->Stackki voi tulla täyteen!
	}
	cout << solmu->luku << "\n";
	if (solmu->oikeasolmu != TYHJA)
	{
		tulostapuu(solmu->oikeasolmu);
	}
}


