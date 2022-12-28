#include "tableauTri.h"

TableauTri::TableauTri(int taille){
    taille = taille;
    tab = new float[taille];
}

TableauTri::TableauTri(int taille): taille(taille){
    tab = new float[taille];
}

TableauTri::TableauTri(const TableauTri &t): taille(t.taille) {
    delete tab;
    tab = new float[t.taille];
    for(int i = 0; i < t.taille; i++){
        tab[i] = t.tab[i];
    }
}

TableauTri::~TableauTri() {
    taille = 0;
    delete tab;
}

TableauTri& TableauTri::operator=(const TableauTri &t){
    if(this != &t) {
        delete tab;
        taille = t.taille;
        tab = new float[t.taille];
        for(int i=0; i<t.taille; i++) {
            tab[i] = t.tab[i];
        }
    }

    return *this;
}

int TableauTri::frequence(float x){
    int n = 0;
    for(int i= 0; i < taille; i++) {
        if(tab[i] == x) n++;
    }
}

void TableauTri::supprimer(float x) {
    int j = 0;
    for(int i = 0; i < taille; i++){
        if(tab[i] == x) {
            j++;
            taille--;
        }
        tab[i] = tab[i + j];
    }
}
