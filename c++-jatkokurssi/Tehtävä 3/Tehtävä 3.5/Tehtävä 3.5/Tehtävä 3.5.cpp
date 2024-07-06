// Tehtävä 3.5.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 10.6.2016
// Tee ohjelma, joka tallentaa syötetyt merkit suoraan tiedostoon.
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ofstream sisaan("eka.txt", ios::app);
	
	char asd[20];

	cout << "Lopetus: Ctrl-Z" << endl;

	while (cin >> setw(20) >> asd)
	{
		sisaan << asd << endl;
	}
	

		

	sisaan.close();

	cin.get();
    return 0;
}

