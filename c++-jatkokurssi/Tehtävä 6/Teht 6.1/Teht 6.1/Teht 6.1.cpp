
// Teht 6.1.cpp : Defines the entry point for the console application.
//	Heikki Siikavirta 13.7.2016
//Tee ohjelma, jossa käyttäjän tulee syöttää merkkimuuttujaan iso kirjain.
//Jos merkki on jokin muu, heitetään poikkeus, joka hoidetaan.
// ä = \x84 ja ö = \x94
// Hoidetaan?
#include "stdafx.h"
#include <iostream>
#include <ctype.h>

using namespace std;

void kokeilu();

int main()

{
	cout << "==========================================================================" << endl;
	cout << "==================Sy\x94t\x84 t\x84h\x84n ohjelmaan iso kirjain=======================" << endl;
	cout << "==========================================================================" << endl;

	char t;
	
	try
	{
		cout << "Sy\x94t\x84 jokin iso kijain: ";
		cin >> t;

		if ((!isupper(t)) || (!isalpha(t))) //Jos syötetty merkki EI ollut, iso tai aakkonen heitetään virhe. Ääkköset ei nähtävästi toimi.
		{
			throw 0;
		}
		
	}
	catch (int x)
	{
		if (x == 0) // Merkki ei ollu iso kirjain 
		{
			cout << "Merkki ei ollut iso kirjain " << t << endl;
		}

	}
	catch (...)	// Vakio catch
	{
		cout << "Ohjelmassa tapahtui odottamaton virhe" << endl;
	}



	cin.get();
	cin.get();


}