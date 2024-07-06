// Teht 6.2.cpp : Defines the entry point for the console application.
//Heikki Siikavirta 13.7.2016
//Tee ohjelma, jossa silmukassa syˆtet‰‰n jakajan ja jaettavan arvoja ja tulostetaan osam‰‰r‰. 
//Jos k‰ytt‰j‰ antaa jakajaksi nollan, heitet‰‰n poikkeus.

#include "stdafx.h"

#include <iostream>
using namespace std;

int main() {
	while (true)
	{


		try
		{
			int numero1;
			cout << "Anna jaettava: " << endl;
			cin >> numero1;

			int numero2;
			cout << "Anna jakaja: " << endl;
			cin >> numero2;

			if (numero2 <= 0)
			{
				throw 0;
			}

			cout << "Osam‰‰r‰ on: " << numero1 / numero2 << endl;

			break;
		}
		catch (int x)// C++ stadartissa kehotetaan kaappaamaan poikkeukset referenssi arvona.(En oo ihan varma mutta, jotain tekemist‰ polyformauksen kanssa) 
		{
			cout << "Jakaja ei voi olla < " << x << " tai == " << x << endl;
		}
		catch (...)// vakio poikkeus
		{
			cout << "Ohjelmassa tapahtui odottamaton virhe!" << endl;
		}
	}

	cin.get();
	cin.get();
	return 0;
}