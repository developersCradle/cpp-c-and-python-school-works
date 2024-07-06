// Tehtävä 3.9.cpp : Defines the entry point for the console application.
//Heikki Siikavirta 19.6.2016
//Tee ohjelma, joka lukee rivin tekstiä käyttäjältä, salaa sitten merkit ja laittaa salatun sanoman tiedostoon.
//Tee sitten funktio, joka lukee tiedoston ja purkaa salatun viestin.


#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string XOR(string data, char key[]) // XOR salaus :P
{
	string XorStr = data;
	for (int  i = 0; i < XorStr.size(); i++)
	{
		XorStr[i] = data[i] ^ key[i % (sizeof(key) / sizeof(char))];
	}

	return XorStr;
}


int main()
{
	char Avain[5] = { 'A', 'V', 'A', 'I','N' };

	string teksti;
	ifstream sisaan("Salattu.txt", ios::in);
	sisaan >> teksti;
	cout << XOR(teksti, Avain) << endl; // Tulostetaan edellinen salattu teksti

	cout << "Anna salattava teksti: " << endl;

	cin >> teksti;

	
	string salattuTeksti = XOR(teksti, Avain);

	ofstream ulos("Salattu.txt", ios::out);

	ulos << salattuTeksti;

	sisaan.close();
	ulos.close();
	cin.get();

    return 0;
}

