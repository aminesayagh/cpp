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
