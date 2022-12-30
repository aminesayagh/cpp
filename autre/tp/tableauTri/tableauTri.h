#include <iostream>
using namespace std;
using std::string;

class TableauTri{
    protected:
        static const int tailleDefault = 50;
        float *tab;
        int taille;
        int sommet;
    public:

        TableauTri(int taille = tailleDefault);
        TableauTri(int taille);
        TableauTri(const TableauTri &t);
        ~TableauTri();

        TableauTri& operator=(const TableauTri &t);
        bool operator>(float x);
        TableauTri& operator+(float x);
        TableauTri& operator+(const TableauTri &t);
        TableauTri &operator--();
        TableauTri &operator*(float r);

        friend ostream& operator<<(ostream&, const TableauTri &);
        friend istream& operator>>(istream&, TableauTri &);

        int frequence(float x);
        void supprimer(float x);

        int getTaille(){
            return taille;
        }
        float* getTab(){
            return tab;
        }
};

class TableauTriResp:TableauTri{
    private:
        int elementRepeter;
        int elementNonRepeter;
        bool setCaseOfTable(float newValue){
            bool noError = (*this)> newValue;
            if(!noError) {
                cout << "ERROR" << endl;
                return false;
            }

            int nombreFrequence = this->frequence(newValue);
            if(nombreFrequence==0) {
                elementNonRepeter++;
            }else if(nombreFrequence == 1){
                elementNonRepeter--;
                elementRepeter++;
            }
            return true;
        }
    public:
        TableauTriResp(int taille): TableauTri(taille) {

        }
        TableauTriResp(const TableauTri &t): TableauTri(t) {}

        friend ostream& operator<<(ostream& os, const TableauTriResp &t){
            os << t << endl;
        }
        friend istream& operator>>(istream&, TableauTriResp &t){
            
        }
        
};