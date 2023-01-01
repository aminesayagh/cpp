#include "tableauTri.cpp"

int main()
{
    // Instanciation d'un objet de la classe TableauTri avec un tableau de taille 5
    TableauTri monTableau(5);

    // Saisie des éléments du tableau par l'utilisateur
    cin >> monTableau;

    // Affichage du tableau
    cout << monTableau;

    
    return 0;
}