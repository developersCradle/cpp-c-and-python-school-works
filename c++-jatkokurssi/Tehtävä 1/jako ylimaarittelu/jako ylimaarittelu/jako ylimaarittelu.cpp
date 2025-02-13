// jako ylimaarittelu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


class Murtoluku
{

public:
	
	Murtoluku();


	Murtoluku(int a, int b)
	{
		jakaja = b;
		jaettava = a;
	}

	Murtoluku operator / (Murtoluku& c1); // Ylimäärittelyn esittely

	int palautaJakaja();

	int palautaJaettava();

private:

	int jakaja;

	int jaettava;
};

Murtoluku::Murtoluku()
{
	jakaja = 0;
	jaettava = 0;
}

int Murtoluku::palautaJakaja()
{
	return jakaja;
}

int Murtoluku::palautaJaettava()
{
	return jaettava;
}

Murtoluku Murtoluku::operator /(Murtoluku& c1)
{
	Murtoluku tulos;

	tulos.jakaja = c1.jaettava * jakaja;
	tulos.jaettava = jaettava * c1.jakaja;

	return tulos;
}

int main()
{
	int p;

	Murtoluku Luku1(2, 3);
	Murtoluku Luku2(5, 6);
	Murtoluku Luku3 = Luku1 / Luku2; // tulos: 12/15

	cout << "3. murtoluvun jakaja on " << Luku3.palautaJakaja() << "\n";

	cout << "3. murtoluvun jaettava on " << Luku3.palautaJaettava() << "\n";

	cin.get();
    return 0;
}

