// Teht‰v‰ 3.4.cpp : Defines the entry point for the console application.
// Heikki Siikavirta  9.6.2016
//Tee ohjelma, joka laskee tiedoston "eka.txt" rivien ja merkkien m‰‰r‰n.


#include "stdafx.h"
#include <iostream>
#include <fstream>
#

using namespace std;

int main()
{
	char c;
	int l = 0;
	int m = 0;
	ifstream luku("eka.txt", ios::in);

	while (luku.get(c))
	{
		

		if (c == '\n')
		{
			l++;
		}
		else // V‰li‰ ei lasketa merkiksi
		{
			m++;
		}

		cout << c;
	}

	cout << "Merkkia " << m << endl;
	cout << "Valia " << l;

	cin.get();
	luku.close();
    return 0;
}

