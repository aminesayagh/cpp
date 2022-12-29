#include <iostream>
using namespace std;
using std::string;

class TableauTri{
    private:
        static const int tailleDefault = 50;
        float *tab;
        int taille;
        
    public:
        TableauTri(int taille);
        TableauTri(int taille);
        TableauTri(const TableauTri &t);
        ~TableauTri();

        TableauTri& operator=(const TableauTri &t);
        int operator>(float x);
        TableauTri& operator+(float x);
        TableauTri& operator+(const TableauTri &t);


        int frequence(float x);
        void supprimer(float x);

};