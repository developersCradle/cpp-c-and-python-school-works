// tehtävä 2.4.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 26.5.2016
// Luo luokka, jossa on parametrisoitu taulukko jäsenmuuttujana.
// Sijoita taulukkoon kokonaislukuja ja desimaalilukuja ohjelmassasi.

#include "stdafx.h"
#include <iostream>


using namespace std;


template<class T>
class Taulu
{
	public:
		Taulu();
		void tulostataulu();
	private:
	int maara;
	T t[5];
};
template<class T>

Taulu<T>::Taulu()

{
	for (int k = 0; k < 3; k++)

	{

		cout << "Syötä solu " << k << endl;

		cin >> t[k];

	}

}
template<class T>
void Taulu<T>::tulostataulu()

{

	for (int k = 0; k < 3; k++)

		cout << t[k] << endl;

}



int main()
{

	

	Taulu<double> taulu1;


	taulu1.tulostataulu();

	

	cin.get();
	cin.get();
    return 0;
}

