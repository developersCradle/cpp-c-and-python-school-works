// Tehtävä 2.1.cpp : Defines the entry point for the console application.
// Luo funktio, joka hakee vaihteluvälin käyttäjän antaessa arvoiksi kokonaislukuja tai desimaalilukuja.
// Heikki Siikavirta 23.5.2016

#include "stdafx.h"
#include <iostream>

using namespace std;



template <class T, class T2>
T isompi(T a, T2 b)
{
	return (a > b ? a : b); //palauttaa isom.
}


template <class T, class T2>
T pienenpi(T a, T2 b)
{
	return (a < b ? a : b); //palauttaa pien.
}

template <class T, class T2>
void vaihteluvali(T a, T2 b)
{
	T suur = isompi(a,b);
	T pien = pienenpi(a, b);

	cout << "Vaihteluvali on " << suur - pien << endl;
	
	return;

}

int main()
{
	double eka;
	double toka;

	cout << "Anna eka luku: " << endl;
	cin >> eka;

	cout  << "Anna toka luku " << endl;
	cin >> toka;

	vaihteluvali(eka, toka);

	cin.get();
	cin.get();
    return 0;
}



