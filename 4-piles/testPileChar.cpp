#include <iostream>
using namespace std;

// #include "PileChar.h"
#include "PileChar.cpp"

void afficherInverse(PileChar pile) {
    PileChar pileRenverser(pile.taille());

    for(int i = 0; i < pileRenverser.taille(); i++) {
        pileRenverser.empiler(pile.depiler());
    }
    pileRenverser.afficher();

    for(int i = 0; i < pile.taille(); i++) {
        pile.empiler(pileRenverser.depiler());
    }
}

int main() {
    cout << "Question 1 : " << endl;

    PileChar pile(10);

    cout << "Question 1 : " << endl;

    PileChar myPile2;

    cout << "Question 3 : " << endl;
    PileChar pile3a;
    PileChar pile3b(20);
    PileChar * pile3c = new PileChar(30);
    delete pile3c;

    cout << "Question 4 :" << endl;

    PileChar pile4(5);

    pile4.depiler();

    pile4.empiler((char*)"h");
    pile4.empiler((char*)"e");
    pile4.empiler((char*)"l");
    pile4.empiler((char*)"l");
    pile4.empiler((char*)"o");
    pile4.empiler((char*)" "); // pile pleine
    pile4.empiler((char*)"!"); // pile pleine

    cout << "Contenu de pile : ";
    pile4.afficher();

    cout << "Nombre d'element presents sur pile 4 : " << pile4.compter() << endl;

    cout << "Taille de pile4: " << pile4.taille() << endl;

    char *c = pile4.depiler();
    cout << "Caractere depile : " << c << endl;

    cout << "Contenu de pile4 : ";
    pile4.afficher();

    cout << "Nombre d'element presents sur pile 4 : " << pile4.compter() << endl;

    cout << "Question 5 : " << endl;

    // Deux situations ou le constructeur de copie est appele :
    PileChar pile5a(pile4);
    PileChar pile5b = pile4;

    cout << "Contenu de pile5a : ";
    pile5a.afficher();
    cout << "Nombre d'element presents sur pile5a : " << pile5a.compter() << endl;
    cout << "Taille de pile5a : " << pile5a.taille() << endl;

    cout << "Contenu de pile5b : ";
    pile5b.afficher();
    cout << "Nombre d'element presents sur pile5b : " << pile5b.compter() << endl;
    cout << "Taille de pile5b : " << pile5b.taille() << endl;

    cout << "Question 6 : " << endl;
    PileChar pile6;

    pile6 = pile4;

    pile6.empiler("o");

    cout << "Contenu de pile6: ";
    pile6.afficher();
    cout << "Nombre d'element presents sur pile6 : " << pile6.compter() << endl;
    cout << "Taille de pile6 : " << pile6.taille() << endl;

    cout << "Question 7 : " << endl;
    PileChar pile7;

    pile7.empiler("s");
    pile7.empiler("e");
    pile7.empiler("l");
    pile7.empiler("e");
    pile7.empiler("i");
    pile7.empiler("l");

    cout << "Contenu de pile7 : ";
    pile7.afficher();
    cout << "Contenu inverse de pile7 : ";
    afficherInverse(pile7);
    

    return 0;
}