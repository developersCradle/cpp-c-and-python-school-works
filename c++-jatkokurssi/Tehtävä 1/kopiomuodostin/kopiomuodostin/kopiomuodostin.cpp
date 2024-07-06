// kopiomuodostin.cpp : Defines the entry point for the console application.
//

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



Murtoluku& Murtoluku:: operator+=(int luku)

{

	jakaja += luku;

	jaettava += luku;

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

	Luku1 += 2;

	cout << "Lisäyksen jälkeen murtoluku:\n";

	cout << "1. murtoluvun jakaja on " << Luku1.palautaJakaja() << "\n";

	cout << "1. murtoluvun jaettava on " << Luku1.palautaJaettava() << "\n";

	// Kopiomuodostimen käyttö seuraavissa lauseissa

	Murtoluku luku2 = Luku1;

	Murtoluku luku3(Luku1);

	cin.get();

	return 0;

}
