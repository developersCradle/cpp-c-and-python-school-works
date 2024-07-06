// operaattorin ylimaarittelu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


class Piste
{

public:

	Piste operator + (Piste c1); // Ylim‰‰rittely esittely

	Piste()
	{
	}; // oletusmuodostin

	Piste(int a, int b)
	{ 
		x = b;
		y = a;
	} // parametrisoitu muodostin

	int palautaX() 
	{ 
		return x; 
	};

	int palautaY() 
	{ 
		return y; 
	};

	void tulostaTiedot() 
	{ 
		cout << "(" << x << "," << y << ")" << endl; 
	}

	void asetaX(int a)
	{ 
		x = a; 
	};

	void asetaY(int b)
	{
		y = b; 
	};

	

private:

	int x;

	int y;


};

Piste Piste:: operator+(Piste c1)	//Ylim‰‰rittely
{
	Piste p;

	p.x = x + c1.x;

	p.y = y + c1.y;
	
	return p;
}





int main()
{
	Piste p1(10, 10);

	p1.tulostaTiedot();

	Piste p2(2, 3);

	p2.tulostaTiedot();

	Piste p3 = p1 + p2;

	Piste p4 = p1.operator+(p2);

	p3.tulostaTiedot();
	p4.tulostaTiedot();

	cin.get();

    return 0;
}

