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

    TableauTri monTableau4 = monTableau1;

    float value;
    cout << "Value : " << endl;
    cin >> value;
    int frequenceTableau1 = monTableau1.frequence(value);

    if(frequenceTableau1 == -1){
        cout << "frequence not exist" << endl;
    }else{
        cout << "frequence exist" << endl;
    }

    

    return 0;
}