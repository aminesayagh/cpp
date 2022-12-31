#include "tabTri.h";

TableauTri::TableauTri(int taille = 0): taille(taille) {
    tab = new float[taille];
}

TableauTri::TableauTri(int taille): taille(taille) {
    tab = new float[taille];
}

TableauTri::TableauTri(const TableauTri &t): taille(t.taille) {
    for(int i = 0; i < t.nbrElement; i++) {
        tab[i] = t.tab[i];
        nbrElement++;
    }
}

TableauTri::~TableauTri() {
    delete tab;
    tab = NULL;

    taille = 0;
    nbrElement = 0;
}

TableauTri &TableauTri::operator= (const TableauTri &t) {
    if(this != &t){
        taille = t.taille;
        nbrElement = t.nbrElement;

        //  POINTEUR: Variable pointeur, tableau
        // supprimer ensient valeur
        delete tab;

        // initialiser le nouveau tableua et allocation memoire
        tab = new float[t.taille];

        // remplisage
        for(int i = 0; i < nbrElement; i++) {
            tab[i] = t.tab[i];
        }
    }
    return *this;
}

int TableauTri::frequence(float x) {
    int n = 0;
    for(int i = 0; i < nbrElement; i++) {
        if(tab[i] == x) n++;
    }
    return n;
}

void TableauTri::supprimer(float x){
    int j = 0;
    for(int i = 0; i < nbrElement; i++) {
        while(tab[i] == x) {
            j++;
            nbrElement--;
            tab[i] = tab[i + j + 1];
        }
    }
}
