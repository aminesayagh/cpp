#define DEBUG


class Polynome{
    private: 
        int degre;
        double *coefficients;
    public:
        Polynome();
        Polynome(int);
        Polynome(int degre, double *coefficients);

        ~Polynome();
        Polynome(const Polynome &lastPolynome);

        // usecases
        void afficher();

        // operator
        Polynome &operator=(const Polynome &copiePolynome);
        Polynome &operator+(const Polynome &addPolynome);
};
