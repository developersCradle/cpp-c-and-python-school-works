// teht‰v‰ 3.6.cpp : Defines the entry point for the console application.
// 13.6.2016 Heikki Siikavirta
//Tee ohjelma, joka tallentaa Henkilo-olion tiedot tiedostoon.

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

class olio
{
public:
	int ika;
	char kirjain;
};

int main()
{

	ofstream kirjoitus("teksti.txt", ios::out); // Vied‰‰n muistista ulos jotain

	olio testi;

	int olionKoko = sizeof(olio);

	int a;
	char b;

	while (true)
	{
		cout << "Anno oliolle ika" << endl;
			
			if (!(cin >> a))	// Jos lukua EI voitu laittaa muutujaan a
			{
				break;
			}

		testi.ika = a;
		cout << "Anna oliolle kirjain" << endl;

		cin >> b;
		testi.kirjain = b;

		kirjoitus.write((char *)&testi, olionKoko);
	}

	kirjoitus.close();

	
	
	cin.get();
    return 0;
}

