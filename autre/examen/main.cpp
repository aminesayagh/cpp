#include <iostream>
using namespace std;
using std::string;

class Livre 
{
    char *title;
    bool index;
    float prix;
    public: 
        Livre(){
            prix = 0;
            index= false;
            title = NULL;
        }
        Livre(float prix, bool p, char *title);
        Livre(const Livre &);
        void Afficher();
        char *getTitle();
        ~Livre();

        bool operator==(const Livre &other) {
            return title == other.title && index == other.index && prix == other.prix;
        }
        bool operator!=(const Livre &other) {
            return !(*this == other);
        }
        Livre &operator=(const Livre &other) {
            //copier les propriétés
            title = other.title;
            index = other.index;
            prix = other.prix;
            return *this;
        }

};

class SerieLivre
{
    protected:
        int nbp;
        Livre *T;
    public:
        SerieLivre(int nbp, Livre *T) : nbp(nbp){
            this->nbp = nbp;
            T = new Livre[nbp];
            this->T = T;
        }
        
};

Livre::Livre(float prix, bool p, char *title): prix(prix), index(p), title(title) {

}

Livre::Livre(const Livre &L): prix(L.prix), index(L.index), title(L.title) {

}

void Livre::Afficher(){
    cout << "Afficher" << endl;
    cout << "Index: " << index << endl;
    cout << "Title: " << title << endl;
    cout << "Prix: " << prix << endl << endl;
}

char* Livre::getTitle(){
    return title;
}

Livre::~Livre(){
    delete title;
    title = NULL;

    prix = 0;
    index = 0;
}

