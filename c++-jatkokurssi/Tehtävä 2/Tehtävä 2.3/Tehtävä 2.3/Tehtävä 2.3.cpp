// Tehtävä 2.3.cpp : Defines the entry point for the console application.
//Heikki Siikavirta 25.5.2016
//Luo lajittelufunktio, joka lajittelee eri tyyppisiä taulukoita (int-, char- ja float-taulukoita).

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template<class T>
T lajitteleTaul(T num)
{
	
	
	int i, j, flag = 1;    // set flag to 1 to start first pass
	int temp;             // holding variable
	int numLength = num.length();
	for (i = 1; (i <= numLength) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (numLength - 1); j++)
		{
			if (num[j + 1] > num[j])      // ascending order simply changes to <
			{
				temp = num[j];             // swap elements
				num[j] = num[j + 1];
				num[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}

	return num;   //arrays are passed to functions by address; nothing is returned
	
}
int main()
{	
	string num = "42254334";
	string num2 = lajitteleTaul(num);

	cout << num2 << endl;

	/*
	int taulukko1[] = { 7,9,3,4 };
	int taulukko = lajitteleTaul(taulukko1);
	*/
	//lajitteleTaul()
	
	cin.get();
    return 0;
}

