/*
Kirjoita funktio, joka palauttaa nimessään suuriman luvun kolmes
ta luvusta a, b ja c, jotka viedään parametreinä funktioon.

Heikki Siikavirta 14.12.2015

*/

#include <iostream>

using namespace std;



int a = 19;
int b = 17;
int c = 4;


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

int main()
{



    //suurin(a,b,c);


    cout << "Suurin arvo " << suurin(a, b, c) <<  endl;
    return 0;
}
