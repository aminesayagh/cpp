#include "PileChar.cpp"

int main() {
    PileChar pilechar1;
    PileChar pilechar2(20);
   
    PileChar* pilechar3 = new PileChar(30);
    delete pilechar3;
    PileChar pile4(5);
    
pile4.depiler(); // pile vide !
pile4.empiler("h");
pile4.empiler("e");
pile4.empiler("l");
pile4.empiler("l");
pile4.empiler("o");
pile4.empiler(" "); // pile pleine !
pile4.empiler("!"); // pile pleine !
cout << "Contenu de pile4 : "; pile4.afficher();
cout << "Nombre d’éléments présents sur pile4 : " << pile4.compter() << endl;
cout << "Taille de pile4 : " << pile4.taille() << endl;
char *y = pile4.depiler( ); // on récupère ’o’
cout << "Caractère dépilé : " << y << endl;
cout << "Contenu de pile4 : "; pile4.afficher();
cout << "Nombre d’éléments présents sur pile4 : " << pile4.compter() << endl;
}