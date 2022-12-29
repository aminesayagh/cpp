#define DEBUG
#include <iostream>
using namespace std;

class Polynome{
    private: 
        int degre;
        double *coefficients;
    public:
        Polynome();
        Polynome(int);
        Polynome(int degre, double *coefficients);

        ~Polynome();
        Polynome(const Polynome &lastPolynome);

        // usecases
        void afficher() const;
        Polynome primitive() const;

        // operator
        Polynome &operator=(const Polynome &copiePolynome);
        Polynome &operator+(const Polynome &addPolynome);
        Polynome &operator*(const Polynome &multiplePolynome);

        friend ostream& operator<<(ostream&,const Polynome&);//saisie 
	    friend istream& operator>>(istream&,Polynome&);// l'affichage 
};
