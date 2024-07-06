// yhteenlasku ylimaarittelu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

class Murtoluku
{
public:
	Murtoluku();
	Murtoluku(int a, int b) { jakaja = b;jaettava = a; }
	Murtoluku operator+ (Murtoluku& c1);


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


Murtoluku Murtoluku::operator+ (Murtoluku& c1)
{
	Murtoluku tulos;

	tulos.jakaja = c1.jakaja * jakaja;
	tulos.jaettava = c1.jaettava * jakaja + c1.jakaja * jaettava;

	return tulos;

}

int main()
{
	Murtoluku Luku1(2, 3);

	Murtoluku Luku2(5, 6);

	Murtoluku Luku3 = Luku1 + Luku2; // 2/3 + 5/6 = 12/18 + 15/18 = 27/18

	cout << "Luku 3 " << Luku3.palautaJaettava() << " " << Luku3.palautaJakaja() << "\n";
	cin.get();

    return 0;
}

