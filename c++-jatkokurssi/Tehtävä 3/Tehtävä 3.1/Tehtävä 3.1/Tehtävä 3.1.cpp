// Tehtävä 3.1.cpp : Defines the entry point for the console application.
// 8.6.2016 Heikki Siikavirta
//Tee ohjelma, joka lukee kaikki rivit tiedostosta "eka.txt" ja tulostaa ne näytölle.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{


	ifstream input1("eka.txt", ios::in);

	if (!input1)
	{
		cout << "File not found!";
		exit(1);
	}

	char buff[15];
	
	while (!input1.eof())
	{
		input1 >> buff;
		cout << buff << endl;
	}

	cin.get();
	input1.close();

	return 0;

}
