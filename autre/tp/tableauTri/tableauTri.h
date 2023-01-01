#include <iostream>
using namespace std;
using std::string;

class TableauTri
{
protected:
    int taille;
    float *tab = NULL;
    int nbrElement = 0;

public:
    TableauTri();
    TableauTri(int taille);
    TableauTri(const TableauTri &t);
    ~TableauTri();

    TableauTri &operator=(const TableauTri &t);
    int operator>(float x);
    TableauTri &operator+(float x);
    TableauTri &operator+(const TableauTri &t);
    TableauTri &operator--();
    TableauTri &operator*(float r);

    friend ostream &operator<<(ostream &os, const TableauTri &t)
    {
        for (int i = 0; i < t.taille; i++)
        {
            os << "tab[" << i << "] = " << t.tab[i] << endl;
        }
        return os;
    }
    friend istream &operator>>(istream &is, TableauTri &t)
    {
        int value;
        for (int i = 0; i < t.taille; i++)
        {
            cout << "Saisir tab[" << i << "] = ";
            is >> value;
            t = t + value;
            // is >> t.tab[i];
        }
        return is;
    }

    int frequence(float x);
    void supprimer(float x);
};

class TableauTriResp : TableauTri
{
private:
    int elementRepeter = 0;
    int elementNonRepeter = 0;

public:
    TableauTriResp(int taille);
    TableauTriResp(const TableauTri &t) : TableauTri(t)
    {
        for (int i = 0; i < nbrElement; i++)
        {
            int nombreFrequence = frequence(tab[i]);
            if (nombreFrequence == 0)
            {
                elementNonRepeter++;
            }
            else if (nombreFrequence == 1)
            {
                elementNonRepeter--;
                elementRepeter++;
            }
        }
    }

    friend ostream &operator<<(ostream &os, const TableauTriResp &t)
    {
        os << t << endl;
        return os;
    }
    friend istream &operator>>(istream &is, TableauTriResp &t)
    {
        for (int i = 0; i < t.nbrElement; i++)
        {
            cout << "Saisir tab[" << i << "] = ";
            is >> t.tab[i];

            int nombreFrequence = t.frequence(t.tab[i]);
            if (nombreFrequence == 0)
            {
                t.elementNonRepeter++;
            }
            else if (nombreFrequence == 1)
            {
                t.elementNonRepeter--;
                t.elementRepeter++;
            }
        }
        return is;
    }
};