/*

Kirjoita  funktio,  joka  järjestää  kaksi  parametreinä  vietyä
lukua  a  ja  b  (järjestys  on pienemmästä isompaan)
suuruusjärjestykseen. HUOM! Vie luvut osoitteina aliohjelmaan

Heikki Siikavirta 14.12.2015

*/

#include <iostream>
#include <cstdlib> // tarvitaan rand() -funktiolle
#include <ctime> // tarvitaan time -funktiolle

using namespace std;


int numerot[2];

int vertailu(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}




int main()
{
    numerot[0] = 170;
    numerot[1] = 160;


    qsort((void *)numerot, 2, sizeof(numerot[0]), vertailu);

    cout << "Numerot ovat " << numerot[0] << " " << numerot[1] << endl;

    return 0;
}



// Vertailualiohjelmaa käytetään lukujen järjestämiseen qsortilla


