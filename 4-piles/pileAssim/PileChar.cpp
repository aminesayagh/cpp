#include <iostream>
using namespace std;
using std::string;

#include "PileChar.h"

PileChar::PileChar(int taille) : max(taille), pile(0), sommet(0)
{
    pile = new char[max];
    cout << "PileChar(" << taille << ") : " << this << "\n";
}
PileChar::~PileChar()
{
    delete pile;
    pile = NULL;
    cout << "~PileChar(" << max << ") : " << this << "\n";
}
int PileChar::compter() { return sommet; }
int PileChar::taille() { return max; }
void PileChar::afficher()
{
    for (int i = 0; i < max; i++)
        cout << "Pile[" << i << "] =" << pile[i] << endl;
}
void PileChar::empiler(char x)
{
    if (max == sommet)
    {
        cout << "pile pleine !";
    }
    else
    {
        pile[sommet] = x;]
    }
