#include "tableauTri.h"

// CONSTRUCTORS
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

// METHODS
int TableauTri::frequence(float x){
    int n = 0;
    for(int i= 0; i < taille; i++) {
        if(tab[i] == x) n++;
    }
    return n;
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

bool TableauTri::operator>(float x) {
    for(int i = 0; i < taille; i++) {
        if(tab[i] == x) return i;
        if(tab[i] > x) return false;
    }
    return true;
}

TableauTri& TableauTri::operator+(float x) {
    int j = 0;
    float *newTab = new float[taille + 1];
    for(int i = 0; i < taille; i++){
        if(tab[i+1] >= x && j != 1) {
            newTab[i] = x;
            j++;
            taille++;
        }
        newTab[i + j] = tab[i];
    }
    delete tab;

    tab = newTab;
    return *this;
}

TableauTri& TableauTri::operator+(const TableauTri& t){
    int j= 0;
    float *newTab = new float(taille + t.taille);

    for(int i = 0; i < taille; i++){
        while(tab[i+1] >= t.tab[j]){
            taille++;
            newTab[i+j] = t.tab[j];
            j++;
        }
        newTab[i + j] = tab[i];
    }
    delete tab;
    tab = newTab;

    return *this;
}

TableauTri& TableauTri::operator--(){
    for(int i = 0; i < taille; i++){
        tab[i]++;
    }
    return *this;
}


TableauTri& TableauTri::operator*(float r){
    for(int i = 0; i < taille; i++){
        tab[i] *= r;
    }
    return *this;
}

ostream& operator<<(ostream& ot, const TableauTri &t){
    for(int i = 0; i < t.taille; i++){
        ot << "tab[" << i << "] = " << t.tab[i] << endl;
    }
    return ot;
}

istream& operator>>(istream& in, TableauTri &t) {
    for(int i = 0; i < t.taille; i++){
        cout << "Saisir tab[" << i << "] = "; 
        in >> t.tab[i];
    }
    return in;
}

