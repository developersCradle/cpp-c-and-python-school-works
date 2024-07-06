// Tehtävä 3.8.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 15.6.2016
//Tee ohjelma, joka lukee henkilötiedot tiedostosta(nimi ja sotutunnus) ja tutkii sitten, onko jollakulla henkilöllä tänään syntymäpäivä.
//ä = \x84 ja ö = \x94
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

#include <stdlib.h>

using namespace std;

int main()
{
	time_t t = time(0);  
	struct tm * now = localtime(&t);

	/*
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;
		*/

	string a, b;
	ifstream sisaan("henk.txt",ios::in);

	while (sisaan >> a >> b)
	{
		

		string day, month, year;
		
		
		day = b.substr(0, 2);
		
		month = b.substr(2, 2);
		year = "19";	// Oletetaan vuosi on 1900, vuosi tieto on hyödytön
		year += b.substr(4, 2);
		
		
		if (to_string(now->tm_mon + 1) == month)
		{
			cout << "kuukausi on sama";

			if (to_string(now->tm_mday) == day)
			{
				cout << "Paljon onnea " << a;
			}
		}
		cout << "Henkil\x94n " << a << " p\x84iv\x84 on " << day << " kuukausi on " << month << " vuosi on " << year << endl;

	}

	cin.get();

	return 0;

}
