#include <iostream>
using namespace std;
using std::string;

#include "PileChar.h"

PileChar::PileChar(int taille) : max(taille), pile(0), sommet(0)
{
    pile = new char[max];
    cout << "PileChar(" << taille << ") : " << this << endl;
}
PileChar::~PileChar()
{
    delete pile;
    pile = NULL;
    cout << "~PileChar(" << max << ") : " << this << endl;
}
int PileChar::compter() { return sommet; }
int PileChar::taille() { return max; }
void PileChar::afficher()
{
    for (int i = 0; i < max; i++)
        cout << "Pile[" << i << "] =" << pile[i] << endl;
}
void PileChar::empiler(char *x)
{
    if (max == sommet)
    {
        cout << "pile pleine !" << endl;
    }
    else
    {
        pile[sommet] = *x;
        sommet = sommet + 1;
    }
}
char *PileChar::depiler()
{
    char *y = NULL;
    if (sommet == 0)
    {
        cout << "pile vide!" << endl;
    }
    else
    {
        y = &pile[sommet];
        sommet - 1;
    }
    return y;
}
PileChar::PileChar(const PileChar &p) : max(p.max), sommet(p.sommet)
{
    delete pile;
    pile = new char[max];
    for (int i = 0; i < sommet; i++)
    {
        pile[i] = p.pile[i];
    }
    cout << "Pilchar(const PileChar &p) = " << this << endl;
}
PileChar& PileChar::operator=(const PileChar &p)
{
    if (this != &p)
    {
        delete pile;
        sommet = 0;
        max = 0;
        pile = new char[max];
        for (int i = 0; i < sommet; i++)
        {
            pile[i] = p.pile[i];
        }
    }
    cout << "operator=(const PileChar &p) = " << this << endl;
    return *this;
}
char* PileChar::getPile(){
    return pile;
}
int PileChar::getMax(){
    return max;
}
void affiche_inverse(PileChar p)
{
    char *pile=p.getPile();
    for (int i = p.getMax(); i >= 0; i--)
    
        cout << "P  ile[" << i << "] =" << pile[i] << endl;
}
