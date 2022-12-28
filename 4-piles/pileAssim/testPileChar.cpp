#include "PileChar.cpp"

int main()
{
    PileChar pilechar1;
    PileChar pilechar2(20);

    PileChar *pilechar3 = new PileChar(30);
    delete pilechar3;
    PileChar pile4(5);
    PileChar pile7(6);
    /*pile4.depiler(); // pile vide !
    pile4.empiler((char *)"h");
    pile4.empiler((char *)"e");
    pile4.empiler((char *)"l");
    pile4.empiler((char *)"l");
    pile4.empiler((char *)"o");
    pile4.empiler((char *)" "); // pile pleine !
    pile4.empiler((char *)"!"); // pile pleine !
    cout << "Contenu de pile4 : " << endl;
    pile4.afficher();
    cout << "Nombre déléments présents sur pile4 : " << pile4.compter() << endl;
    cout << "Taille de pile4 : " << pile4.taille() << endl;
    char *y = pile4.depiler(); // on récupère ’o’
    cout << "Caractère dépilé : " << y << endl;
    cout << "Contenu de pile4 : " << endl;
    pile4.afficher();
    cout << "Nombre déléments présents sur pile4 : " << pile4.compter() << endl;
    PileChar pile5a(pile4);      // Appel du constructeur de copie pour instancier pile5a
    PileChar pile5b = pilechar1; // Appel du constructeur de copie pour instancier pile5b
    cout << "Contenu de pile5a : ";
    pile5a.afficher();
    cout << "Nombre delements présents sur pile5a : " << pile5a.compter() << endl;
    cout << "Taille de pile5a : " << pile5a.taille() << endl;
    cout << "Contenu de pile5b : ";
    pile5b.afficher();
    cout << "Nombre delements présents sur pile5b : " << pile5b.compter() << endl;
    cout << "Taille de pile5b : " << pile5b.taille() << endl;
    cout << "Question 6 :\n";
    PileChar pile6; // Appel du constructeur par défaut pour créer pile6
    pile6 = pile4;  // Appel de l’opérateur d’affectation pour copier pile4 dans pile6
    pile6.empiler((char *)"o");
    cout << "Contenu de pile6 : ";
    pile6.afficher();
    cout << "Nombre deléments présents sur pile6 : " << pile6.compter() << endl;
    cout << "Taille de pile6 : " << pile6.taille() << endl;*/
    pile7.empiler((char *)"s");
    pile7.empiler((char *)"o");
    pile7.empiler((char *)"l");
    pile7.empiler((char *)"e");
    pile7.empiler((char *)"i");
    pile7.empiler((char *)"l");
    cout << "Contenu de pile7 : ";
    // pile7.afficher();
    cout << "Contenu inverse de pile7 : ";
    affiche_inverse(pile7);
    cout << "Contenu de pile7 : ";
    // pile7.afficher();
}
