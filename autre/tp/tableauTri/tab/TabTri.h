#include <iostream>
using namespace std;

class TableauTri{
    protected:
        int taille;
        float *tab = NULL;

        int nbrElement = 0;
    public:
        // constructor
        TableauTri(int taille = 0); // constructor par default
        TableauTri(int taille); // constructor usuel
        TableauTri(const TableauTri &t); // constructor de copie

        // destructor
        ~TableauTri();


        TableauTri &operator=(const TableauTri &t);

        int frequence(float x);
        void supprimer(float x);
        
        
};