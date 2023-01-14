#include <iostream>
using namespace std;
using std::string;

// Exercice 1: Specifier completement la classe tableau_tri
class TableauTri
{
protected:
    int taille;   // Taille maximale du tableau
    float *tab = NULL;   // Pointeur vers un tableau de flottants qui contiendra les données
    int nbElis = 0;  // Nombre d'éléments actuellement stockés dans le tableau

public:
    // Exercice 2: Implémenter les constructeurs (par défaut, usuel, copie) et destructeur
    TableauTri(); // constructeur par défaut : Initialise un tableau vide
    TableauTri(int taille); // constructeur usuel : Initialise un tableau vide de la taille donnée en paramètre
    TableauTri(const TableauTri &t); // constructeur de copie : Permet de créer une copie d'un tableau existant

    ~TableauTri(); // destructeur : Se charge de libérer la mémoire allouée pour le tableau

    // Exercice 3: Implémenter l'opération d'affectation
    TableauTri &operator=(const TableauTri &t);

    // Exercice 4: Nombre de répétitions d'un réel dans un tableau
    int frequence(float x);

    // Exercice 5: Supprimer une occurrence d'un tableau
    void supprimer(float x);

    // Exercice 6: Implementer l'operation >, permettant de chercher un element particullier dans un tableau trie
    int operator>(float x);

    // Exercice 7: Implementer l'operation + permettant l'ajout physique d'un nouvel element en conservant le tri
    TableauTri &operator+(float x);
        // Exercice 7: Implémenter l'opération + permettant la fusion de deux tableaux triés
    TableauTri &operator+(const TableauTri &t);

    // Exercice 8: Opérateur -- qui décrémente de un tous les éléments du tableau
    TableauTri &operator--();

    // Exercice 9: Opérateur * qui multiplie tous les éléments d'un tableau par un réel
    TableauTri operator*(float r);
    // Exercice 9: Opérateur * permettant cette fois-ci de multiplier un réel r par les éléments du tableau
    friend float operator*(float r, TableauTri);

    // Exercice 10: Implémenter les opérateurs >> et << pour la saisie et l'affichage
    friend ostream &operator<<(ostream &os, const TableauTri &t); // cout << 
    friend istream &operator>>(istream &is, TableauTri &t); // cin >>
};
// Exercice partie B
class TableauTriResp : public TableauTri
{
private:
    int elementRepeter = 0;
    int elementNonRepeter = 0;

public:
    // Exerice 1
    TableauTriResp(int taille);
    // Exercice 2
    TableauTriResp(const TableauTri &t);

    friend ostream &operator<<(ostream &os, const TableauTriResp &t);
    // Exercice 3
    friend istream &operator>>(istream &is, TableauTriResp &t);
};