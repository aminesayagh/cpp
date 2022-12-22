
#include <iostream>
using namespace std;
using std::string;

#include "Polynome.h"

// CONSTRUCTOR
Polynome::Polynome(): degre(0), coefficients(NULL) {
    cout << "Polynome constructed : " << this << endl;
};

Polynome::Polynome(int degre): degre(degre){
    coefficients = new double[degre];
    cout << "Polynome constructed : " << this << "with degre " << degre << endl;
}

Polynome::Polynome(int degre, double *coefficients): degre(degre), coefficients(coefficients) {
    cout << "Polynome constructed : " << this << "with degre " << degre << endl;
}

Polynome::Polynome(const Polynome &lastPolynome): degre(lastPolynome.degre), coefficients(lastPolynome.coefficients) {

}

Polynome::~Polynome() {
    degre = 0;
    delete coefficients;
    coefficients = NULL;
}

// OPERATORS
Polynome& Polynome::operator=(const Polynome &copiePolynome){
    if(this != &copiePolynome) {
        degre = copiePolynome.degre;
        for(int i = 0; i < copiePolynome.degre; i++) {
            coefficients[i] = copiePolynome.coefficients[i];
        }
    }
    return *this;
};


Polynome& Polynome::operator+ (const Polynome &addPolynome){
    Polynome polynomeSave = *this;

    if(degre < addPolynome.degre){
        delete coefficients;
        coefficients = new double[addPolynome.degre];
        for(int i = 0; i <= degre; i++) {
            coefficients[i] = polynomeSave.coefficients[i] + addPolynome.coefficients[i];
        }
        for(int i = degre + 1; i <= addPolynome.degre; i++) {
            coefficients[i] = addPolynome.coefficients[i];
        }

        degre = addPolynome.degre;
    } else { 
        for(int i = 0; i <= addPolynome.degre; i++) {
            coefficients[i] += addPolynome.coefficients[i];
        }
    }

    return *this;
};

// USE CASES
void Polynome::afficher(){
    cout << "Polynome a afficher" << endl;
    for(int i = degre; i >= 0; i--) {
        cout << coefficients[i];
        if(i != 0) cout << "x^" << i << " + ";
    }
    cout << endl;

}