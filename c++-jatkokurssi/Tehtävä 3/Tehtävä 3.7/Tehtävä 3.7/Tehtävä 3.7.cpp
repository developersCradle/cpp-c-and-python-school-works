// tehtävä 3.7.cpp : Defines the entry point for the console application.
// Heikki Siikavirta 14.6.2016
// Tee ohjelma, joka tallentaa taulukon, jossa on useita Henkilo-olioita tiedostoon.

// Latta _CRT_SECURE_NO_WARNINGS poikkeus
#include "stdafx.h";
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Henkilo
{

public:
	int ika;
	int pituus;
	char nimi[20];
	char sukunimi[20];
};







int _tmain(int argc, _TCHAR* argv[])
{

	Henkilo taulukko[6];

	// Laitetaan henkilöille tietoja

	taulukko[0].ika = 1;
	taulukko[1].ika = 2;
	taulukko[2].ika = 3;
	taulukko[3].ika = 4;
	taulukko[4].ika = 5;
	taulukko[5].ika = 6;

	taulukko[0].pituus = 100;
	taulukko[1].pituus = 200;
	taulukko[2].pituus = 300;
	taulukko[3].pituus = 400;
	taulukko[4].pituus = 500;
	taulukko[5].pituus = 600;

	strcpy(taulukko[0].nimi, "Kalevi");
	strcpy(taulukko[1].nimi, "Kirsti");
	strcpy(taulukko[2].nimi, "Terhi");
	strcpy(taulukko[3].nimi, "Seppo");
	strcpy(taulukko[4].nimi, "Sergei");
	strcpy(taulukko[5].nimi, "Hilkka");

	strcpy(taulukko[0].sukunimi, "Virtanen");
	strcpy(taulukko[1].sukunimi, "Aho");
	strcpy(taulukko[2].sukunimi, "Mirjala");
	strcpy(taulukko[3].sukunimi, "Ukko");
	strcpy(taulukko[4].sukunimi, "Dawai");
	strcpy(taulukko[5].sukunimi, "Kirjala");


	cout << sizeof(taulukko[0]) << " " << sizeof(Henkilo) << endl;
	cout << sizeof(taulukko) << endl;


	//tallennus

	ofstream sisaan("Teksti.txt", ios::out); //Out, ulos muistista
	int koko = sizeof(taulukko);


	sisaan.write((char *)&taulukko, koko);

	sisaan.close();



	cin.get();

	return 0;

}