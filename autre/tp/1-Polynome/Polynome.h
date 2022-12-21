class Polynome {
    private: 
        int degre;
        double *coefficients;
    public:
        Polynome();
        Polynome(int);

        ~Polynome();
        Polynome(const Polynome &lastPolynome);

        // operator
        Polynome &operator=(const Polynome &copiePolynome);
        Polynome &operator+(const Polynome &addPolynome);
};
