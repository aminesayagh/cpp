#include "tableauTri.cpp"

#include <iostream>
using namespace std;
using std::string;

int main()
{
    TableauTri monTableau1;

    cin >> monTableau1;

    cout << monTableau1;

    int taille2 = 0;
    cout << "Taille tableau 2 = " << endl;
    cin >> taille2;
    TableauTri monTableau2(taille2);
    
    cin >> monTableau2;

    TableauTri monTableau3(monTableau2);

    cout << monTableau3 << endl;

    

    return 0;
}