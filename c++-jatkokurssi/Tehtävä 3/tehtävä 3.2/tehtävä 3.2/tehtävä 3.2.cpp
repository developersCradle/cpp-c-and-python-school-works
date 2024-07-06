// tehtävä 3.2.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 8.6.2016
// Tee ohjelma, joka lukee kaikki rivit tiedostosta "eka.txt" ja tekee varmuuskopion "eka.bak".

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{



	
	char c;
	ifstream f1("eka.txt", ios::in); 

	if (!f1)
	{
		cout << "Could not find a file!";
		exit(1);
	}

	ofstream f2("eka.bak", ios::ate);

	while (f1.get(c))
	{

		f2 << f1.rdbuf();
	
		
	}
	

	cin.get();

	return 0;

}
