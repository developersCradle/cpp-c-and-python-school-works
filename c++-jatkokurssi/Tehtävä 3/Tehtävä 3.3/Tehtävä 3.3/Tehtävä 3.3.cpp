// Tehtävä 3.3.cpp : Defines the entry point for the console application.
//Heikki Siikavirta 8.6.2016
//Tee ohjelma, joka lukee kaikki rivit tiedostosta "nimet.txt" taulukkoon nimitaulu[].

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	ifstream file("nimet.txt");

	if (file.is_open())
	{
		string myArray[5];

		for (int i = 0; i < 5; ++i)
		{
			file >> myArray[i];

			
		}


		for (int i = 0; i < 5; i++)
		{
			cout << myArray[i] << endl;
		}
		
	}

	cin.get();

	file.close();
    return 0;
}

