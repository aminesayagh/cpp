#include <iostream>
using namespace std;
using std::string;


void supprimer(int *t, int x, int nbrElement){
    int j = 0;
    for(int i = 0; i < nbrElement; i++) {
        while(t[i] == x) {
            j++;
            nbrElement--;
            t[i] = t[i + j + 1];
        }
    }
}

int main() {
    int *tab = new int[7];
    for(int i = 0; i < 7; i++){
        cout << "Tab[" << i << "] : ";
        cin >> tab[i];
    }
    for(int i = 0; i < 7; i++){
        cout << tab[i] << endl;
    }
    cout << endl;
    supprimer(tab, 5, 7);
    cout << endl;

    // for(int i = 0; i < 7; i++){
    //     cout << tab[i] << endl;
    // }

}