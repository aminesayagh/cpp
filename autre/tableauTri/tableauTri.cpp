#include "tableauTri.h"

#include <iostream>
using namespace std;
using std::string;

// CONSTRUCTORS
TableauTri::TableauTri() : taille(3)
{
    tab = new float[taille];
}

TableauTri::TableauTri(int taille) : taille(taille)
{
    tab = new float[taille];
}

TableauTri::TableauTri(const TableauTri &t) : taille(t.taille)
{
    delete tab;
    tab = new float[t.taille];
    nbElis = 0;
    
    for (int i = 0; i < t.nbElis; i++)
    {
        tab[i] = t.tab[i];
        nbElis++;
    }
}

TableauTri::~TableauTri()
{
    delete tab;
    tab = NULL;

    taille = 0;
    nbElis = 0;
}

TableauTri &TableauTri::operator=(const TableauTri &t)
{
    if (this != &t)
    {
        delete tab;
        taille = t.taille;
        tab = new float[t.taille];
        nbElis = 0;
        for (int i = 0; i < t.nbElis; i++)
        {
            tab[i] = t.tab[i];
            nbElis++;
        }
    }

    return *this;
}

// METHODS
// Exercice 4
int TableauTri::frequence(float x)
{
    int n = 0;
    for (int i = 0; i < nbElis && tab[i] <= x; i++)
    {
        if (tab[i] == x)
            n++;
    }
    return n;
}

// Exercice 5
void TableauTri::supprimer(float x)
{
    int j = 0;
    for (int i = 0; i < nbElis; i++)
    {
        if (tab[i] == x)
        {
            j++;
            nbElis--;
        }
        tab[i] = tab[i + j];
    }
}

int TableauTri::operator>(float x)
{
    for (int i = 0; i < nbElis; i++)
    {
        if (tab[i] == x)
            return i;
        if (tab[i] > x)
            return -1;
    }
    return -1;
}

TableauTri &TableauTri::operator+(float x)
{
    int indexOfX = -1;
    for (int i = 0; i < nbElis && indexOfX == -1; i++)
    {
        if (tab[i] >= x)
        {
            indexOfX = i;
        }
    }
    if (indexOfX == -1)
    {
        tab[nbElis] = x;
        nbElis++;
    }
    else
    {
        for (int i = nbElis; i > indexOfX; i--)
        {
            tab[i + 1] = tab[i];
        }
        tab[indexOfX] = x;
        nbElis++;
    }
    return *this;
}

TableauTri &TableauTri::operator+(const TableauTri &t)
{
    for (int i = 0; i < t.nbElis; i++)
    {
        this = *this + t.tab[i]; // j'utilise le surcharge d'operateur creer en ligne  98 du fichier pour ajouter les elemenets un a un au tableau
    }

    return *this;
}

TableauTri &TableauTri::operator--()
{
    for (int i = 0; i < nbElis; i++)
    {
        tab[i]--;
    }
    return *this;
}

TableauTri TableauTri::operator*(float r)
{
    for (int i = 0; i < nbElis; i++)
    {
        tab[i] *= r;
    }
    return *this;
}

float operator*(float r, TableauTri t)
{
    for (int i = 0; i < t.nbElis; i++)
    {
        r *= t.tab[i];
    }
    return r;
}

istream &operator>>(istream &is, TableauTri &t)
{
    float value = 0;
    int nombreElement;
    cout << "Nombre element a inserer a votre tableau = ";
    is >> nombreElement;

    for (int i = 0; i < nombreElement; i++)
    {
        cout << "Saisir tab[" << i << "] = ";
        is >> value;
        t = t + value; // j'utilise operateur + surcharge a la ligne 98 de ce fichier, ce qui me permet d'ajouter un element en gardent le trie de mon tableau 
    }
    return is;
}

ostream &operator<<(ostream &os, const TableauTri &t)
{
    for (int i = 0; i < t.nbElis; i++)
    {
        os << "tab[" << i << "] = " << t.tab[i] << endl;
    }
    return os;
}

//  TableauTriResp
TableauTriResp::TableauTriResp(int taille) : TableauTri(taille) {}

TableauTriResp::TableauTriResp(const TableauTri &t) : TableauTri(t)
{
    for (int i = 0; i < nbElis; i++)
    {
        int nombreFrequence = frequence(tab[i]);
        if (nombreFrequence == 0)
        {
            elementNonRepeter++;
        }
        else if (nombreFrequence == 1)
        {
            elementNonRepeter--;
            elementRepeter++;
        }
    }
}

ostream &operator<<(ostream &os, const TableauTriResp &t)
{
    os << t << endl;
    return os;
}

istream &operator>>(istream &is, TableauTriResp &t)
{
    for (int i = 0; i < t.nbElis; i++)
    {
        cout << "Saisir tab[" << i << "] = ";
        is >> t.tab[i];

        int nombreFrequence = t.frequence(t.tab[i]);
        if (nombreFrequence == 0)
        {
            t.elementNonRepeter++;
        }
        else if (nombreFrequence == 1)
        {
            t.elementNonRepeter--;
            t.elementRepeter++;
        }
    }
    return is;
}
