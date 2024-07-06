// UML_elukka.cpp : Defines the entry point for the console application.
//Heikki Siikavirta 22.7.2016
//  Elukka, josta periytyy luokka Kotielukka.
//
//Kuvaa suhde myös koodilla ja toimivalla ohjelmalla!

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
/*
ELUKKA
*/
class Elukka 
{
public:
	Elukka();
	void asetaTiedot(int p, string n);
	int haePaino();
	string haeNimi();
	void tulosta();
private:
	int paino;
	string nimi;

};
Elukka::Elukka()
{
	paino = 0;
	nimi = "vakio nimi";
}
int Elukka::haePaino()
{
	return paino;
}

string Elukka::haeNimi()
{
	return nimi;
}

void Elukka::tulosta()
{
	cout << "Elukan nimi on " << Elukka::haeNimi() << "\n";
	cout << "Elukan paino on  " << Elukka::haePaino() << "\n";
}
void Elukka::asetaTiedot(int p, string s)
{
	paino = p;
	nimi = s;
}
/*
PVM
*/
class Pvm
{
public:
	void asetaTiedot(int p, int k, int v);
	void tulostaPvm();
private:
	int paiva;
	int kuukausi;
	int vuosi;

};
void Pvm::asetaTiedot(int p, int k, int v)
{
	paiva = p;
	kuukausi = k;
	vuosi = v;
}
void Pvm::tulostaPvm()
{
	cout << "Paiva on " << paiva << "\n";
	cout << "Kuukausi on " << kuukausi << "\n";
	cout << "Vuosi on " << vuosi << "\n";
}
/*
Kotielukka
*/
class Kotielukka : public Elukka
{
public:
	bool leikattu;
	Pvm Syntynyt;
	void tulostaTiedot();
};
void Kotielukka::tulostaTiedot()
{
	cout << "Onko kotielukka leikattu " << leikattu << "\n";
	Syntynyt.tulostaPvm();

}
int main()
{
	
	Kotielukka kotiE;
	
	kotiE.asetaTiedot(30, "Pertti Kissa");
	kotiE.Syntynyt.asetaTiedot(12, 05, 1991);
	kotiE.leikattu = true;
	kotiE.tulosta();
	kotiE.tulostaTiedot();
	
	
	

	cin.get();
    return 0;
}

