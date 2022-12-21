#include <iostream>
using namespace std;

#include "Polynome.h"

Polynome::Polynome(): degre(0), coefficients(NULL) {

};

Polynome::Polynome(int degre): degre(degre){
    coefficients = new double[degre];
}

Polynome::Polynome(const Polynome &lastPolynome): degre(lastPolynome.degre), coefficients(lastPolynome.coefficients) {

}

Polynome::~Polynome() {
    degre = NULL;
    coefficients = NULL;
}