// Tehtävä 7.6.cpp : Defines the entry point for the console application.
//Laadi kahteen suuntaan ketjutettu lista, jossa siis tail on kytketty headiin ja vastaavasti head on kytketty tailiin.
//Heikki Siikavirta, 27.7.2016
// // ä = \x84 ja ö = \x94 
#include "stdafx.h"
#include <iostream>


using namespace std;

typedef struct solmu
{
public:
	int tieto;
	struct solmu * seuraava;
	struct solmu * edellinen;
	

}lista;


lista * head, * tail;

void luolista(lista **li);
void tulostalistaK(lista * li);

int main()
{
	lista * alku; 
	luolista(&alku);	

	//Tulostetaan seuraava tiedon avulla kunnes saavutaan NULL arvoon.
	tulostalistaK(alku);


	
	cout << endl << "\nListan tulostus h\x84nn\x84n\x84 ja p\x84\x84n avulla: \n";
	// Tulostetaan pään ja hännän avulla
	for (lista * apu = head; apu != tail->seuraava; apu = apu->seuraava)
	{
		cout << apu->tieto << "\t";
	}
	cout << endl << "===================================" << endl;
	for (lista * apu = tail; apu != head->edellinen; apu = apu->edellinen)
	{
		cout << apu->tieto << "\t";
	}

	cin.get();
	cin.get();

	return 0;
}


void luolista(lista **li)
{
	int i;
	lista *apu, *temp; 
	*li = NULL;		
	apu = new(lista);
	apu->tieto = 100;
	apu->edellinen = NULL;
	apu->seuraava = NULL;
	*li = apu;
	tail = apu;

	


	for (i = 1; i < 5; i++)
	{
		apu = new(lista);
		apu->tieto = i*i;
		(*li)->edellinen = apu;
		apu->edellinen = NULL;
		apu->seuraava = *li;
		*li = apu;
		head = *li;
	}

}

void tulostalistaK(lista *li) 
{
	lista * apu;
	cout << "\nListan tulostus: \n";
	apu = li;
	lista * loppu = NULL;


	for (apu = li; apu != NULL; apu = apu->seuraava)
		cout << apu->tieto << "\t";
	cout << "\n";

	for (apu = li; apu != NULL; apu = apu->seuraava)
		loppu = apu;



	for (apu = loppu;apu != li->edellinen; apu = apu->edellinen)
		cout << apu->tieto << "\t";

}



