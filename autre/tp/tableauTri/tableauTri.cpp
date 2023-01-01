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

    for (int i = 0; i < t.taille; i++)
    {
        tab[i] = t.tab[i];
        nbrElement++;
    }
}

TableauTri::~TableauTri()
{
    delete tab;
    tab = NULL;

    taille = 0;
    nbrElement = 0;
}

TableauTri &TableauTri::operator=(const TableauTri &t)
{
    if (this != &t)
    {
        delete tab;
        taille = t.taille;
        tab = new float[t.taille];
        for (int i = 0; i < t.taille; i++)
        {
            tab[i] = t.tab[i];
            nbrElement++;
        }
    }

    return *this;
}

// METHODS
int TableauTri::frequence(float x)
{
    int n = 0;
    for (int i = 0; i < taille; i++)
    {
        if (tab[i] == x)
            n++;
    }
    return n;
}

void TableauTri::supprimer(float x)
{
    int j = 0;
    for (int i = 0; i < nbrElement; i++)
    {
        if (tab[i] == x)
        {
            j++;
            nbrElement--;
            tab[i] = tab[i + j + 1];
        }
    }
}

int TableauTri::operator>(float x)
{
    for (int i = 0; i < nbrElement; i++)
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
    for(int i = 0; i < nbrElement && indexOfX == -1; i++){
        if(tab[i] >= x){
            indexOfX = i;
        }
    }
    if(indexOfX == -1){
        tab[nbrElement] = x;
        nbrElement++;
    }else{
        for(int i = nbrElement; i > indexOfX; i--){
            tab[i] = tab[i-1];
        }
        tab[indexOfX] = x;
        nbrElement++;
    }
    return *this;
}

TableauTri &TableauTri::operator+(const TableauTri &t)
{
    for(int i = 0; i < t.nbrElement; i++){
        *this + t.tab[i];
    }

    return *this;
}

TableauTri &TableauTri::operator--()
{
    for (int i = 0; i < nbrElement; i++)
    {
        tab[i]--;
    }
    return *this;
}

TableauTri &TableauTri::operator*(float r)
{
    for (int i = 0; i < nbrElement; i++)
    {
        tab[i] *= r;
    }
    return *this;
}

//  TableauTriResp
TableauTriResp::TableauTriResp(int taille) : TableauTri(taille) {}