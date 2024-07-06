// hakasulje ylimaarittelu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

class Vektori {

public:

	Vektori(int alku, int lkm);

	Vektori(const Vektori& v);

	~Vektori();

	int operator [](int ind);

	friend ostream& operator<< (ostream& oo, const Vektori& c);
	friend istream& operator>> (istream& ii, const Vektori& c);

private:

	int *v;

	const int eka;

	int maara;

};
Vektori::Vektori(int alku, int lkm)
{
	eka = alku;
	maara = lkm;
}

int Vektori::operator [](int ind)
{

	if ((ind >= eka) && (ind < maara))
		
		return v[ind];

}

ostream& operator<< (ostream& oo, const Vektori& c)
{
	cout << "Alkiot ovat " << endl;

	for (int k = 0; k < c.maara; k++)

		oo << c.v[k] << "\n";

	return oo;
}

istream& operator>> (istream& ii, const Vektori& c)
{
	cout << "Vektoriin menee " << c.maara << " alkiota" << endl;

	cout << "Anna arvot" << endl;

	for (int k = 0; k < c.maara; k++)

	{

		ii >> c.v[k];

	}

	return ii;
}



int main()
{


	Vektori v1(0, 3);

	cin >> v1;

	cout << v1;

	Vektori v2(0, 3);

	cin >> v2;

	cout << v2;


	cin.get();
    return 0;
}

