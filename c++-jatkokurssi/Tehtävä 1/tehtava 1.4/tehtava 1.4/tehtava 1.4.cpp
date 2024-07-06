// tehtava 1.4.cpp : Defines the entry point for the console application.
//Toteuta Piste-luokka, joka kuvaa XY-koordinaatiston pistettä 
// sekä sille operaattori ++, joka kasvattaa x- ja y-arvoa yhdellä.
// Heikki Siikavirta 17.05.2016

#include "stdafx.h"
#include <iostream>

using namespace std;

class Piste
{


public:

	Piste() {}; 

	Piste(int a, int b) { x = b;y = a; } 

	int palautaX() { return x; };
	int palautaY() { return y; };

	void tulostaTiedot() { cout << "(" << x << "," << y << ")" << endl; }
	void asetaX(int a) { x = a; };
	void asetaY(int b) { y = b; };

	
	Piste operator ++(int);
	Piste operator +=(int);

private:

	int x;

	int y;

};









Piste Piste::operator +=(int luku)
{

	x += luku;

	y += luku;

	return *this;

}


Piste Piste::operator++ (int)

{

	Piste apu(*this);

	(*this).x += 1; 
	(*this).y += 1;

	cout << "Korotettu yhdellä!" << endl;

	return apu; 

}



int main()
{
	Piste piste1(1, 1);
	piste1.tulostaTiedot();
	piste1++;
	piste1.tulostaTiedot();

	cin.get();

	return 0;
}

