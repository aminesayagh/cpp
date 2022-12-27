#include <iostream>
using namespace std;
using std::string;

class PileChar
{
private:
static const int tailleDefaut = 50; 
    const int max;
    int sommet;
    char *pile;
public:
    PileChar(int taille=tailleDefaut);
    ~PileChar();
    int compter();
     int taille(); 
    void afficher();
    void empiler(char *x);
   char *depiler();
};