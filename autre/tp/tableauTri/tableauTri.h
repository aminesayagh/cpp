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
        TableauTri &operator--();
        TableauTri &operator*(float r);

        ostream& operator<<(ostream&);
        istream& operator>>(istream&);

        int frequence(float x);
        void supprimer(float x);

        int getTaille(){
            return taille;
        }
        float* getTab(){
            return tab;
        }

        void setCaseOfTable(int c, float value){
            tab[c] = value;
        }
};