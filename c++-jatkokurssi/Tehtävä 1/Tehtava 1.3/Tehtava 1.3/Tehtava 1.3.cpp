// Tehtava 1.3.cpp : Defines the entry point for the console application.
//	16.5.2016 Heikki Siikavirta
// Toteuta sama kuin edellä friend-funktioita käyttäen.
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

	int palautaJakaja();
	int palautaJaettava();

	friend Murtoluku operator /(Murtoluku c1, Murtoluku c2);	
	friend Murtoluku operator +(Murtoluku c1, Murtoluku c2);
	friend Murtoluku operator -(Murtoluku c1, Murtoluku c2);
	friend Murtoluku operator *(Murtoluku c1, Murtoluku c2);

private:

	int jakaja;
	int jaettava;

};

Murtoluku::Murtoluku()

{
	jakaja = 0;
	jaettava = 0;

}




Murtoluku operator *(Murtoluku c1, Murtoluku c2)
{

	Murtoluku tulos;

	tulos.jakaja = c1.jakaja * c2.jakaja;

	tulos.jaettava = c1.jaettava * c2.jaettava;

	cout << "Murtoluvun kertolasku suoritettu!" << endl;

	return tulos;

}


Murtoluku operator -(Murtoluku c1, Murtoluku c2)

{

	Murtoluku tulos;

	tulos.jakaja = c1.jakaja * c2.jakaja;

	tulos.jaettava = c1.jakaja * c2.jaettava - c1.jaettava * c2.jakaja;

	cout << "Murtolukujen vähennyslasku suoritettu!" << endl;

	return tulos;

}


Murtoluku operator +(Murtoluku c1, Murtoluku c2)
{

	Murtoluku tulos;

	tulos.jakaja = c1.jakaja * c2.jakaja;

	tulos.jaettava = c1.jaettava * c2.jakaja + c1.jakaja * c2.jaettava;

	cout << "Murtolukujen yhteenlasku suoritettu!" << endl;

	return tulos;

}

Murtoluku operator /(Murtoluku c1, Murtoluku c2)

{

	Murtoluku tulos;

	tulos.jakaja = c1.jaettava * c2.jakaja;
	tulos.jaettava = c2.jaettava * c1.jakaja;

	cout << "Murtoluvun jako suoritettu!" << endl;

	return tulos;

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

	cout << "Arvot ovat:" << endl;

	Murtoluku Luku1(2, 3);
	Murtoluku Luku2(5, 6);



	cout << "1. murtoluvun jakaja on " << Luku1.palautaJakaja() << "\n";
	cout << "1. murtoluvun jaettava on " << Luku1.palautaJaettava() << "\n" << endl;

	cout << "2. murtoluvun jakaja on " << Luku2.palautaJakaja() << "\n";
	cout << "2. murtoluvun jaettava on " << Luku2.palautaJaettava() << "\n" << endl;

	cout << "Näille luvuille tullaan suorittamaan seuraavat operaatiot:\n +, -, / ja *. " << endl << endl;

	Murtoluku Luku3 = Luku1 / Luku2;

	cout << "3. murtoluvun jakaja on " << Luku3.palautaJakaja() << "\n";
	cout << "3. murtoluvun jaettava on " << Luku3.palautaJaettava() << "\n" << endl << endl;

	Murtoluku Luku4 = Luku1 + Luku2;

	cout << "4. murtoluvun jakaja on " << Luku4.palautaJakaja() << "\n";
	cout << "4. murtoluvun jaettava on " << Luku4.palautaJaettava() << "\n" << endl << endl;

	Murtoluku Luku5 = Luku1 - Luku2;

	cout << "5. murtoluvun jakaja on " << Luku5.palautaJakaja() << "\n";
	cout << "5. murtoluvun jaettava on " << Luku5.palautaJaettava() << "\n" << endl << endl;

	Murtoluku Luku6 = Luku1 * Luku2;

	cout << "6. murtoluvun jakaja on " << Luku6.palautaJakaja() << "\n";
	cout << "6. murtoluvun jaettava on " << Luku6.palautaJaettava() << "\n" << endl << endl;

	cin.get();

	return 0;

}
