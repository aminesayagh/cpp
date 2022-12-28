#include <iostream>
using namespace std;
using std::string;

class PileChar
{
private:
static const int tailleDefaut = 50; 
    int max;
    int sommet = 0;
    char *pile;
public:
    PileChar(int taille=tailleDefaut);
    PileChar(const PileChar &p);
    ~PileChar();
    int compter();
     int taille(); 
    void afficher();
    void empiler(char *x);
    char* getPile();
    int getMax();
    char *depiler();
   PileChar& operator=(const PileChar &p);

};
 void affiche_inverse( PileChar pile);