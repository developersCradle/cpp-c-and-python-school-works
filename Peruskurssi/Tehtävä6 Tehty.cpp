/*

    Heikki Siikavirta 30.12.2015

    Seuraavalla   sivullaoleva   C++   -ohjelma   lukee   tiedostosta   matriisi.txt
    kokonaislukutaulukon  sijoittaen  sen  5x5  taulukkoon  (matriisi[5][5]).  Ohjelma
    tulostaa matriisin n�yt�lle, laskee alkioiden summan ja tulostaa summan n�yt�lle
    hy�dynt�en funktioita tulosta_matriisi() ja laske_summa().

    Sinun  teht�v�n�  on  laatia  n�m�  kaksi  funktiota.  Rivill�  sijaitsevat arvot  erotellaan
    v�lily�nnein. Huomaa tiedostojen k�sittely (nyt vain luetaan samasta kansiosta, miss� ohjelma sijaitsee).
    Tee tekstitiedosto esim. Notepadill�.


    T�rppi: Muista txt on samassa kansiossa, ei tarvitse hakea polkua.

    ESIMERKKITULOSTUS:

    Matriisi:
    32 32 2 23 33
    3 2 33 332 32
    42 43 44 32 31
    83 86 56 545 44
    33 37 38 39 30
    Alkioiden summa: 1707

*/

#define rivi 5
#define linja 5

#include <iostream>
#include <fstream>



using namespace std;

//Muista EOF raportoi viimeisimm�st� toiminnosta, raportointi tapahtuu meneisyydess� eik� tulevaisuudessa.
// EOF palauttaa bool arvon true-> jos EOF on huomattu, muutoin false.

// 2 dimension matriisi, [x] [y], miss� x on kerros ja y on kerroksessa olavat asukkaat.
void tulosta_matriisi(int matriisi[5][5])
{
    // Miten saa fixed postioning? selvit�

    for(int x = 0; x < rivi; x++)
    {

        for(int y = 0; y < linja; y++)
        {
            cout << " " << matriisi[x][y]  << " ";
        }

        cout << endl;
    }
}

int laske_summa(int matriisi[5][5])
{
    int summa = 0;

    for(int x = 0; x < rivi; x++)
    {

        for(int y = 0; y < linja; y++)
        {
             summa += matriisi[x][y];
        }

    }
    return summa;
}

int main(void)
{
    int matriisi[5][5];
    int summa;

      ifstream luku("matriisi.txt");

    if (!luku)
    {
        cout << "Tiedoston avaaminen ep\x84onnistui...";
    }
    else
    {
        for (int y=0; y<5;y++)
        {
            for (int x=0;x<5;x++)
            {
                luku >> matriisi[y][x];
            }
        }

        luku.close();

        cout << "Matriisi:" << endl;

        tulosta_matriisi(matriisi);
        summa = laske_summa(matriisi);

        cout << "Alkioiden summa: " << summa << endl;
      }
}
