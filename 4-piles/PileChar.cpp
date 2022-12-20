#include <iostream>
using namespace std;
using std::string;

#include "PileChar.h"

PileChar::PileChar(int taille): max(taille), sommet(0), pile(0) {
    pile = new char[max];

    cout << "PileChar (" << taille << ") : " << this << endl;
};

PileChar::~PileChar() {
    delete[] pile;

    sommet = 0;
    pile = NULL;
    
    cout << "Destruct PileChar (" << max << ") : " << this << endl;
}

int PileChar::taille() {
    return max;
}

int PileChar::compter() {
    return sommet;
}

void PileChar::afficher() {
    cout << "[";
    for(int i = 0; i < sommet; i++){
        cout << pile[i];
    }
    cout << "]" << endl;
}

void PileChar::empiler(char *c) {
    if(sommet == max) {
        cout << "Error: Pile Remplie";
        return;
    }
    pile[sommet] = *c;
    sommet++;
}

char* PileChar::depiler() {
    if(sommet == 0){
        cout << "Error: Pile Vide";
        return NULL;
    } else{
        char c = pile[sommet];
        sommet--;
        return &c;
    }
}

PileChar::PileChar(const PileChar &lastPile): max(lastPile.max), sommet(lastPile.sommet), pile(0) {
    char *copiePile = new char[max];

    for(int i = 0; i < sommet; i++){
        copiePile[i] = lastPile.pile[i];
    }

    cout << "PileChar(const PileChar &p) : " << this << "\n";
}

PileChar& PileChar::operator=(const PileChar &p) {
    if(this != &p) {
        delete[] pile;
        pile = NULL;
    
        
        sommet = p.sommet;

        pile = new char[max];

        for(int i = 0; i < sommet; i++){
            pile[i] = p.pile[i];
        }

    }

    cout << "Operator= (const PileChar &p) : " << this << endl;

    return *this;
}