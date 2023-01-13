#include <iostream>
using namespace std;

#include "Polynome.cpp"

int main() {
    double coefficient1[3] = {1, 3, 2};

    double coefficient2[2] = {4, 1};

    Polynome polynome_1(2, coefficient1);
    Polynome polynome_2(1, coefficient2);
    cout << polynome_1 << endl;
    cout << polynome_2 << endl;

    polynome_2 = polynome_2 + polynome_1;
    cout << polynome_2 << endl;
    return 0;
}