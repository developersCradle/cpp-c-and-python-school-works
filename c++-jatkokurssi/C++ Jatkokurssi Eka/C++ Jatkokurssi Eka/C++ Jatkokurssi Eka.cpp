// C++ Jatkokurssi Eka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

int main(void)
{


	
		float tyo_tunnit[30];
		int syote;

		printf("Ohjelma laskee yhteen haluamasi ajanjakson aikana\ntehdyt työtunnit sekä keskimääräisen työpäivän pituuden.\n");
		printf("Kuika monta päivää:");

		scanf("%d", &syote);
		for (int i = 1; syote > i ;i++)
		{
			float temp;
			printf("Anna %d. päivän työtunnit:", i);
			scanf("%f\n", &tyo_tunnit[i-1]);
			
		}
		printf("Ulkona");
	
	
}