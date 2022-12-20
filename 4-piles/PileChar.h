#define DEBUG

class PileChar{
    private:
        static const int tailleDefault = 50; // contante de classe

        const unsigned int max;
        unsigned int sommet;
        char *pile;

    public: 
        PileChar(int taille = tailleDefault);
        
        int taille();
        int compter();
        void afficher();
        void empiler(char *c);
        char* depiler();

        ~PileChar();
        PileChar(const PileChar &lastPile);
        PileChar& operator=(const PileChar &p);
};