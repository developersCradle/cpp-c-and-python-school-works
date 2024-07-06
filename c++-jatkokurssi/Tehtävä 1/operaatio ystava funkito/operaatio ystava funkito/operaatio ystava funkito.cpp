// operaatio ystava funkito.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Piste

{

public:

	Piste() {}; // oletusmuodostin

	Piste(int a, int b) { x = b;y = a; } // parametrisoitu muodostin

	int palautaX() { return x; };

	int palautaY() { return y; };

	void tulostaTiedot() { cout << "(" << x << "," << y << ")" << endl; }

	void asetaX(int a) { x = a; };

	void asetaY(int b) { y = b; };

	friend Piste operator+(Piste c1, Piste c2); // ylimäärittelyn esittely

private:

	int x;

	int y;

};



Piste operator+(Piste c1, Piste c2) // ylimäärittelyn esittely

{

	Piste p;

	p.x = c1.x + c2.x;

	p.y = c1.y + c2.y;

	return p;

}




int main()

{

	Piste p1(10, 10);

	p1.tulostaTiedot();

	Piste p2(2, 3);

	p2.tulostaTiedot();

	Piste p3 = p1 + p2;

	p3.tulostaTiedot();

	cin.get();

	return 0;

}
