// yhdistetty ylimaarittelu.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>


using namespace std;

class Murtoluku

{

public:

	Murtoluku();

	Murtoluku(int a, int b) { jakaja = b;jaettava = a; }

	int palautaJakaja();

	int palautaJaettava();

	Murtoluku& operator +=(Murtoluku& c1);

private:

	int jakaja;

	int jaettava;

};

Murtoluku::Murtoluku()

{

	jakaja = 0;

	jaettava = 0;

}



Murtoluku& Murtoluku::operator +=(Murtoluku& c1)

{

	jaettava = c1.jaettava * jakaja + c1.jakaja * jaettava;

	jakaja = c1.jakaja * jakaja;

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

	Murtoluku Luku2(5, 6);

	Luku1 += Luku2; // 2/3 + 5/6 = 27/18

	cout << "1. murtoluvun jakaja on " << Luku1.palautaJakaja() << "\n";

	cout << "1. murtoluvun jaettava on " << Luku1.palautaJaettava() << "\n";

	cin.get();

	return 0;

}
