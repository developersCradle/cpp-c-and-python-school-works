// Tehtävä 6.4.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 16.7.2016
// Toteuta ohjelma, jossa poikkeusolion argumenttina heitetään virhekoodi. 
//Virhekoodien selitykset ja toipumisohjeet ovat 2-ulotteisessa taulukossa.
//Catch-lohkossa tulostetaan virheen selitys ja toipumisohje.
// ä = \x84 ja ö = \x94

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class omavirhe : public runtime_error
{

public:

	omavirhe(const char* huomautus, int k, int i) :runtime_error(huomautus), koodi(k), apu(i)
	{

	}

	int koodi;
	int apu;

};

int luku1, luku2;

string kaksiDtaul[3][2] = {
	{"Luku 1 ei ollut m\x84\x84riteltujen rajojen sis\x84ll\x84.","Anna luvulle 1 arvo joka on 0 - 10 v\x84lill\x84"},	// taulukko 1 jossa ensin tulee selitys, seuraavana toipumis ohje.
	{"Luku 2 ei ollut m\x84\x84riteltujen rajojen sis\x84ll\x84.","Anna luvulle 2 arvo joka on 0 - 10 v\x84lill\x84" },
	{"Odottamaton virhe!","T\x84t\x84 ei haluta tapahtuvan" }
};


int main()
{
	cout << "==========================================================================" << endl;
	//cout << "==================Sy\x94t\x84 t\x84h\x84n ohjelmaan iso kirjain=======================" << endl;
	cout << "==== Anna kaksi lukua jotka ynn\x84t\x84\x84n. Luvut pit\x84\x84 olla v\x84lilt\x84 0 - 10 ====" << endl;
	cout << "==========================================================================" << endl;


	while (true)
	{
		try
		{
			cout << "Anna luku 1: ";
			cin >> luku1;

			if (luku1 < 0 || luku1 > 10)
			{
				throw omavirhe("Luvussa 1 virhe", 1, luku1);
			}

			cout << "Anna luku 2: ";
			cin >> luku2;

			if (luku2 < 0 || luku2 > 10)
			{
				throw omavirhe("Luvussa 2 virhe", 2, luku2);
			}
		} 
		catch (omavirhe &e)// otetaan koppi referenssinä, C++ stadartissa kehotetaan kaappaamaan poikkeukset referenssinä.
		{
			if (e.koodi == 1)
			{
				cout << "Luku 1 oli " <<  e.apu << endl;
				cout << kaksiDtaul[0][0] << endl;
				cout << kaksiDtaul[0][1] << endl;
				break;
			}

			if (e.koodi == 2)
			{
				cout << "Luku 2 oli " << e.apu << endl;
				cout << kaksiDtaul[1][0] << endl;
				cout << kaksiDtaul[1][1] << endl;
				break;
			}
		}
		catch (...)	// Odottamaton virhe
		{
			
			cout << kaksiDtaul[2][0] << endl;
			cout << kaksiDtaul[2][1] << endl;
			break;
		}

		cout << "Lasku onnistui: " << luku1+luku2 << endl;
		break;
	}

	cin.get();
	cin.get();

    return 0;
}

