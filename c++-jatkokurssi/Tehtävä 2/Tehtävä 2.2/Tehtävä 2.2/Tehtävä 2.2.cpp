// Tehtävä 2.2.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 24.5.2016
//Luo funktio, joka hakee pienimmän kolmesta kokonaisluvusta ja kolmesta merkistä.

#include "stdafx.h"
#include <iostream>


using namespace std;





template <class T, class T2, class T3, class T4, class T5, class T6>
void  pienenpi(T a, T2 b, T3 c, T4 d, T5 e, T6 f)
{
	if (a < b && a < b && a < c && a < (int)d && a < (int)e && a < (int)f )
	{
		cout << "Smallest is number a";
		
	}
	else if (b < c && b < (int)d && b < (int)e && b < (int)f)
	{
		cout << "Smallest is number b";

	}
	else if ( c < (int)d && c < (int)e && c < (int)f)
	{
		cout << "Smallest is number c";

	}
	else if (d < (int)e && d < (int)f)
	{
		cout << "Smallest is number d";

	}
	else if (e < (int)f)
	{
		cout << "Smallest is number e";

	}
	else
	{
		cout << "Smallest is number f";
		
	}
	
	return;
}

int main()
{
	int eka = 100, toka = 200, kolmas = 332;
	char cEka = 'a', cToka = 't', cKolmas = 'o';

	cout << "Arvot ovat a " << eka << endl;
	cout << "Arvot ovat b " << toka << endl;
	cout << "Arvot ovat c " << kolmas << endl;
	cout << "Arvot ovat d " << (int)cEka << endl;
	cout << "Arvot ovat e " << (int)cToka << endl;
	cout << "Arvot ovat f " << (int)cKolmas << endl << endl;
	
	
	pienenpi(eka, toka, kolmas, cEka, cToka, cKolmas);

	

	cin.get();
    return 0;
}

