#include <iostream>
using namespace std;

#include "Polynome.h"

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

    int minDegre = addPolynome.degre;
    if(degre < addPolynome.degre){
        delete coefficients;
        coefficients = new double[addPolynome.degre];
        for(int i = 0; i < degre; i++) {
            coefficients[i] = polynomeSave.coefficients[i];
        }
        for(int i = degre; i < addPolynome.degre; i++) {
            coefficients[i] = addPolynome.coefficients[i];
        }

        degre = addPolynome.degre;
        minDegre = degre;
    }

    for(int i = 0; i < minDegre; i++){
        coefficients[i] += addPolynome.coefficients[i];
    }
};