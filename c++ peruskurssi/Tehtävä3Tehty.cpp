/*

Kirjoita p‰‰ohjelma, jolla testataan edelliset aliohjelma
t 1 ja 2

Heikki Siikavirta 14.12.2015

*/

#include <iostream>
#include <cstdlib> // tarvitaan rand() -funktiolle
#include <ctime> // tarvitaan time -funktiolle

using namespace std;



int numerot[2];
int a = 19;
int b = 17;
int c = 24;



int vertailu(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}



int suurin(int a, int b, int c)
{

    cout << "Palautetaan  " << endl;

    if(a > b && a > c)
    {
        return a;

    }else if(b > a && b > c)
    {
        return b;
    }else
    {
        return c;
    }

    return(0);
}




void sortaaNumerotPiennimmasta()
{




    qsort((void *)numerot, 2, sizeof(numerot[0]), vertailu);

    cout << "Numerot ovat " << numerot[0] << " " << numerot[1] << endl;
    return;
}



int main()
{




numerot[0] = 170;
numerot[1] = 160;

sortaaNumerotPiennimmasta();

cout << "Suurin arvo kolmesta oli " << suurin(a,b,c);


    return 0;
}

