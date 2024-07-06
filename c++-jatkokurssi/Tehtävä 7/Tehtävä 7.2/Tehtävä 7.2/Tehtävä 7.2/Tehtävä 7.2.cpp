// Teht‰v‰ 7.2.cpp : Defines the entry point for the console application.
//Heikk Siikavirta 24.7.2016
/*
Muuta edellinen teht‰v‰ siten, ett‰ listaa voidaan selata molempiin suuntiin.

Lis‰‰ listaan 5 j‰sent‰ ja tulosta lista molempiin suuntiin.
*/
// Muista _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct HENKILO
{	
public:
	char nimi[15];
	struct HENKILO * seuraava;
	struct HENKILO * edellinen;
}solu;



solu *li;

void luolista(solu **li);
void tulostalistaK(solu *li);


int main(void)
{
	solu *alku;   	
	luolista(&alku); 
					
	tulostalistaK(alku);
	
	cin.get();
	return(0);
}

void luolista(solu **li)
{

	int i;
	solu *apu, *temp;  
	*li = NULL;			
	apu = new(solu);

	sprintf(apu->nimi, "Ensimmainen");
	//apu->nimi = "Kerttu";
	apu->edellinen = NULL;
	apu->seuraava = NULL;
	*li = apu;

	for (i = 1;i<5;i++)
	{
		apu = new(solu);
		sprintf(apu->nimi, "Testi nimi %d",i);
		//apu->nimi = " test";
		(*li)->edellinen = apu;
		apu->edellinen = NULL;
		apu->seuraava = *li;
		*li = apu;
	}
}



void tulostalistaK(solu *li)
{
	solu *apu;
	cout << "\nListan tulostus: \n";
	apu = li;
	solu * loppu = NULL;

	for (apu = li;apu != NULL;apu = apu->seuraava)
	{
		cout << apu->nimi << "\t";
	}
	cout << "\n";

	
	for (apu = li;apu != NULL;apu = apu->seuraava)
	{
		loppu = apu;
	}

	for (apu = loppu;apu != li->edellinen;apu = apu->edellinen)
	{
		cout << apu->nimi << "\t";
	}
}



