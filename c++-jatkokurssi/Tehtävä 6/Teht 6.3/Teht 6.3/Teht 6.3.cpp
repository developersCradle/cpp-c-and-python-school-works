// Teht 6.3.cpp : Defines the entry point for the console application.
//Heikki Siikavirta 15.7.2016
//Periytä standardipoikkeusluokasta oma poikkeusluokka, joka heitetään, 
//kun ohjelmassa yritetään avata tiedostoa, jota ei ole olemassa.
// // ä = \x84 ja ö = \x94
#include "stdafx.h"
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

class omavirhe : public runtime_error

{

public:

	omavirhe(const char* huomautus, int k) :runtime_error(huomautus), koodi(k)
	{

	}

	int koodi;

};

int main() {

	
	

	try
	{
		ifstream sisaan("Teksti.txt");
		if (sisaan.fail())
		{
			throw omavirhe("T\x84m\x84 on eka omavirhe", 2);
		}

		cout << "Tiedosto l\x94ytyi!!!" << endl;
		
	}
	catch (omavirhe &e) // C++ stadartissa kehotetaan kaappaamaan poikkeukset referenssi arvona.(En oo ihan varma mutta, jotain tekemistä ylimäärittelyn/polyformauksen kanssa)
	{
		cout << "T\x84m\x84 kaapaa virheet tyypilt\x84\x84n omavirhe! " << endl;
		cout << "omavirhe itse m\x84\x84rittelem\x84ni j\x84senmuuttuja jonka \"koodi\" on  " << e.koodi << endl;
		if (e.koodi == 2)	// Koodi 2 tarkoittaa ongelmia tiedoston kanssa
		{
			cout << "Tiedoston luvussa oli jotain ongelmia" << endl;
		}
	}

	cin.get();
	cin.get();

	return 0;
}
