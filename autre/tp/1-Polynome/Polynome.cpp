
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
Polynome& Polynome::operator* (const Polynome &multiplePolynome) {
    Polynome polynomeSave = *this;

    if(degre < multiplePolynome.degre){
        delete coefficients;
        coefficients = new double[multiplePolynome.degre];
        for(int i = 0; i <= degre; i++) {
            coefficients[i] = polynomeSave.coefficients[i] + multiplePolynome.coefficients[i];
        }
        for(int i = degre + 1; i <= multiplePolynome.degre; i++) {
            coefficients[i] = multiplePolynome.coefficients[i];
        }

        degre = multiplePolynome.degre;
    } else { 
        for(int i = 0; i <= multiplePolynome.degre; i++) {
            coefficients[i] += multiplePolynome.coefficients[i];
        }
    }
    return *this;
}

ostream& operator<<(ostream& cout,const Polynome& pn){	
	for(int i=pn.degre+1;i>0;i--){
		cout<<pn.coefficients[i]<<"x"<<i;
	}
	cout<<endl;
	return cout;
}

istream& operator>>(istream& cin,Polynome& p){
	int x;
	cout<<"le degre du polynome::";
	cin>>p.degre;
	p.coefficients=new double[p.degre+1];
	cout<<endl;
	for(int i=0;i<p.degre+1;i++){
		cin>>p.coefficients[i];
	}
	return cin;
}

Polynome Polynome::primitive() const {
    int newDegre = degre + 1;
    double *newCoefficients = new double[newDegre];
    for (int i = 1; i <= degre + 1; i++) {
      newCoefficients[i] = coefficients[i - 1] / i;
    }
    Polynome primitive(newDegre, newCoefficients);
    return primitive;
  }

// USE CASES
void Polynome::afficher() const{
    cout << "Polynome a afficher" << endl;
    for(int i = degre; i >= 0; i--) {
        cout << coefficients[i];
        if(i != 0) cout << "x^" << i << " + ";
    }
    cout << endl;
}