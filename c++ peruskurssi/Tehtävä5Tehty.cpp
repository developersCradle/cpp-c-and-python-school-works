/*
Tee  ohjelma, joka  kysyy  k‰ytt‰j‰lt‰  p‰iv‰m‰‰r‰‰(jokaista  erikseen, p‰iv‰, kuukausi  ja vuosi).
Ohjelma  tarkistaa, ett‰  p‰iv‰ys  on  k‰yp‰(p‰ivi‰ 1 - 31, riippuen  kuukaudesta;
kuukausia 12 ja vuosi 1900 ja 2100 ñlukujen v‰liss‰).
P‰iv‰m‰‰r‰ kysyt‰‰n uudestaan jos tulee virhe.
P‰iv‰m‰‰r‰ tulostetaan esim.muodossa 5. marraskuuta 2015.

\x84 = ‰
\x94 = ˆ

Heikki Siikavirta 12.1.2015

*/

#include "stdafx.h"	// Visual studion omia juttuja?

#include <iostream>
#include <cstring>
#include<stdio.h>
#include<conio.h>
#include <cstdlib>

using namespace std;

//Globaalit muuuttujat
int paiviaKuukaudessa[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 0 indexi on tammikuu, kk nousee



int kysyVuosi()
{
	int vuosi;

	cout << "Anna vuosi! Antamasi vuosi pit\x84\x84 olla 1900 ja 2100 v\x84lill\x84. " << endl;


	while (1)
	{
		cin >> vuosi;

		if (vuosi > 1900 && vuosi < 2100)
		{
			return vuosi;
		}
		else
		{
			cout << "ERROR! Vuoden tarkista antamasi vuosi, 1900 - 2100" << endl;
			system("PAUSE");
			system("cls");
		}

	}

}

int paiviakuukaudessa(int kuukausi)
{
	int paivia = paiviaKuukaudessa[kuukausi - 1];
	cout << "P\x84ivi\x84 t\x84ss\x84 kuussa on " << paivia << endl;

	return paivia; 
}


int kysyKuukausi()
{
	int merkki;

		while (1)
		{
			cout << "Tammikuu = 1 " << "Helmikuu = 2 " << "Maaliskuu = 3 " << endl
				<< "Hutikuu = 4 " << "Toukokuu = 5 " << "Kes\x84kuu = 6 " << endl
				<< "Hein\x84kuu = 7 " << "Elokuu = 8 " << "Syyskuu = 9 " << endl
				<< "Lokakuu = 10 " << "Marraskuu = 11 " << "Joulukuu = 12 " << endl;

			cout << endl << "Anna kuukausi: " << endl;

			cin >> merkki;
			

			switch (merkki)
			{
				case 1: cout << "Valitsit Tammikuun" << endl; return 1;	// tai return merkki
				case 2: cout << "Valitsit Helmikuun" << endl; return 2;
				case 3: cout << "Valitsit Maaliskuun" << endl; return 3;
				case 4: cout << "Valitsit Huhtikuun" << endl; return 4;
				case 5: cout << "Valitsit Toukokuun" << endl; return 5;
				case 6: cout << "Valitsit Kes\x84kuun" << endl; return 6;
				case 7: cout << "Valitsit Hein\x84kuun" << endl; return 7;
				case 8: cout << "Valitsit Elokuun" << endl; return 8;
				case 9: cout << "Valitsit Syyskuun" << endl; return 9;
				case 10: cout << "Valitsit Lokakuun" << endl; return 10;
				case 11: cout << "Valitsit Marraskuun" << endl; return 11;
				case 12: cout << "Valitsit Joulukuun" << endl; return 12;

				default: cout << "Error! Anna luku 1 - 12 v\x84lill\x84" << endl; system("PAUSE"); system("cls");
			}
			
		}
		
}

int kysyPaivamaara(int maxPaiviaTassaKuussa)
{
	//char merkki;

	while (1)
	{
		cout << "Anna p\x84iv\x84m\x84\x84r\x84 1 - " << maxPaiviaTassaKuussa << endl;

		int paiva;
		cin >> paiva;

		if (paiva <= maxPaiviaTassaKuussa && paiva >= 1)
		{
			return paiva;
		}
		else
		{
			cout << "Error! Tarkista sy\x94tt\x84m\x84si luku!" << endl;
			system("PAUSE");

			system("cls");
		}
	
	}

}


void tulostaPaiv(int kuukausi, int paiva, int vuosi)
{


	char kuukausiTekstina[20];

	switch (kuukausi)
	{
		case 1: strcpy_s(kuukausiTekstina, "Tammikuuta"); break;
		case 2: strcpy_s(kuukausiTekstina, "Helmikuuta"); break;
		case 3: strcpy_s(kuukausiTekstina, "Maaliskuuta"); break;
		case 4: strcpy_s(kuukausiTekstina, "Huhtikuuta"); break;
		case 5: strcpy_s(kuukausiTekstina, "Toukokuuta"); break;
		case 6: strcpy_s(kuukausiTekstina, "Kes\x84kuuta"); break;
		case 7: strcpy_s(kuukausiTekstina, "Hein\x84kuuta"); break;
		case 8: strcpy_s(kuukausiTekstina, "Elokuuta"); break;
		case 9: strcpy_s(kuukausiTekstina, "Syyskuuta"); break;
		case 10:strcpy_s(kuukausiTekstina, "Lokakuuta"); break;
		case 11:strcpy_s(kuukausiTekstina, "Marraskuuta"); break;
		case 12:strcpy_s(kuukausiTekstina, "Joulukuuta"); break;
	}
	
	






	cout << "Valitsemasi p\x84iv\x84m\x84\x84r\x84si oli " << paiva << ". " << kuukausiTekstina << " " << vuosi << endl;

}
// 5. marraskuuta 2015.


int main(void)
{
	int kuukausi = kysyKuukausi();						//Kuukausi
	int paiviaTassaKuussa = paiviakuukaudessa(kuukausi);
	int paiva = kysyPaivamaara(paiviaTassaKuussa);		//P‰iv‰
	int vuosi = kysyVuosi();							// Vuosi


	tulostaPaiv(kuukausi, paiva, vuosi);

	system("PAUSE");

	return 0;
}


