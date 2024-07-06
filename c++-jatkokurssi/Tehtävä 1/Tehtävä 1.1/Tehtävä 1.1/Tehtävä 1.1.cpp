// Teht‰v‰ 1.1.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 14.6.2016
// Toteuta kompleksilukua esitt‰v‰ luokka ja ylim‰‰rittele sille operaatiot + ja *.

#include "stdafx.h"
#include <iostream>

using namespace std;


class kompleksi
{
private:

	double x, y;

public:
	
	kompleksi(double reaali, double imagi);
	friend kompleksi operator+(kompleksi a, kompleksi b);
	friend kompleksi operator*(kompleksi a, kompleksi b);

	double palautaReaali();
	double palautaImagi();
};

kompleksi operator+ (kompleksi a, kompleksi b)
{
	kompleksi vara(0, 0);

	vara.x = b.x + a.x;
	vara.y = b.y + a.y;

	cout << "Yhteenlaksu suoritettu!" << endl;

	return vara;
}


kompleksi operator *(kompleksi a, kompleksi b)
{

	kompleksi vara(0, 0);

	vara.x = b.x * a.x;
	vara.y = b.y * a.y;

	cout << "Kertolasku suoritettu!" << endl;

	return vara;

}



kompleksi::kompleksi(double reaali, double imagi)
{
	x = reaali;
	y = imagi;

}

double kompleksi::palautaReaali()
{
	return x;
}

double kompleksi::palautaImagi()
{
	return y;
}

int main()
{
	kompleksi kompleksi1(1.1, 2.2);
	kompleksi kompleksi2(2, 5);

	cout << "Kompleksi luvun 1 imagi on " << kompleksi1.palautaImagi() << endl;
	cout << "Kompleksi luvun 1 reaali on " << kompleksi1.palautaReaali() << endl << endl;

	cout << "Kompleksi luvun 2 imagi on " << kompleksi2.palautaImagi() << endl;
	cout << "Kompleksi luvun 2 reaali on " << kompleksi2.palautaReaali() << endl << endl;

	kompleksi kompleksi3 = kompleksi1 + kompleksi2;

	cout << "Kompleksi luvun 3 imagi on " << kompleksi3.palautaImagi() << endl;
	cout << "Kompleksi luvun 3 reaali on " << kompleksi3.palautaReaali() << endl << endl;

	kompleksi kompleksi4 = kompleksi1 * kompleksi2;

	cout << "Kompleksi luvun 4 imagi on " << kompleksi4.palautaImagi() << endl;
	cout << "Kompleksi luvun 4 reaali on " << kompleksi4.palautaReaali() << endl << endl;

	cin.get();
    return 0;
}

