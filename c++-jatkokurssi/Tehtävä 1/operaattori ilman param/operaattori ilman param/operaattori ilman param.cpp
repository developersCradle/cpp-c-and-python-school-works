// operaattori ilman param.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"

#include <iostream>


using namespace std;

class Murtoluku
{

public:

	Murtoluku();

	Murtoluku(int a, int b) { jakaja = b;jaettava = a; }

	Murtoluku(const Murtoluku& m);

	int palautaJakaja();

	int palautaJaettava();

	Murtoluku& operator-();
	Murtoluku operator++(int);
	Murtoluku& operator++();
	Murtoluku& operator+=(int luku);

private:

	int jakaja;

	int jaettava;

};

Murtoluku::Murtoluku()

{

	jakaja = 0;

	jaettava = 0;

}

Murtoluku::Murtoluku(const Murtoluku & m)

{

	cout << "Luon kopion\n";

	jakaja = m.jakaja;

	jaettava = m.jaettava;

}



Murtoluku& Murtoluku::operator++ ()

{

	return (*this) += 1;

}


Murtoluku Murtoluku::operator++ (int)

{

	Murtoluku apu(*this);

	(*this) += 1; // Kasvatetaan kyllä alkuperäistä

	return apu; // Palautetaan vanha arvo

}



Murtoluku& Murtoluku:: operator+=(int luku)

{

	jakaja += luku;

	jaettava += luku;

	return *this;

}


Murtoluku& Murtoluku:: operator-()

{

	int apu;

	apu = jakaja;

	jakaja = jaettava;

	jaettava = apu;

	return *this;

}



int Murtoluku::palautaJakaja()

{

	return jakaja;

}

int Murtoluku::palautaJaettava()

{

	return jaettava;

}




int main()
{

	int p;

	Murtoluku Luku1(2, 3);
	


	cout << "Alkuperäinen murtoluku:\n";

	cout << "1. murtoluvun jakaja on " << Luku1.palautaJakaja() << "\n";

	cout << "1. murtoluvun jaettava on " << Luku1.palautaJaettava() << "\n";

	++Luku1;

	cout << "Inkrementoinnin jälkeinen murtoluku:\n";

	cout << "1. murtoluvun jakaja on " << Luku1.palautaJakaja() << "\n";

	cout << "1. murtoluvun jaettava on " << Luku1.palautaJaettava() << "\n";

	Murtoluku Luku2 = ++Luku1;

	cout << "Luku2 :\n";

	cout << "2. murtoluvun jakaja on " << Luku2.palautaJakaja() << "\n";

	cout << "2. murtoluvun jaettava on " << Luku2.palautaJaettava() << "\n";

	Murtoluku Luku3 = Luku1++;

	cout << "Luku3 :\n";

	cout << "3. murtoluvun jakaja on " << Luku3.palautaJakaja() << "\n";

	cout << "3. murtoluvun jaettava on " << Luku3.palautaJaettava() << "\n";

	cout << "Vielä inkrementoinnin jälkeinen murtoluku:\n";

	cout << "1. murtoluvun jakaja on " << Luku1.palautaJakaja() << "\n";

	cout << "1. murtoluvun jaettava on " << Luku1.palautaJaettava() << "\n";

	// Kopiomuodostimen käyttö seuraavissa lauseissa sekä aina oliokopioiden

	// syntyessä ohjelmassa

	Murtoluku luku2 = Luku1;

	Murtoluku luku3(Luku1);

	cin.get();

	return 0;
}


