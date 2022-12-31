#include <iostream>
using namespace std;
using std::string;

class TableauTri
{
protected:
    static const int tailleDefault = 50;
    float *tab;
    int taille;
    int sommet;

public:
    TableauTri();
    TableauTri(int taille);
    TableauTri(const TableauTri &t);
    ~TableauTri();

    TableauTri &operator=(const TableauTri &t);
    bool operator>(float x);
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
        for (int i = 0; i < t.taille; i++)
        {
            cout << "Saisir tab[" << i << "] = ";
            is >> t.tab[i];
        }
        return is;
    }

    int frequence(float x);
    void supprimer(float x);

    int getTaille()
    {
        return taille;
    }
    float *getTab()
    {
        return tab;
    }
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
        for (int i = 0; i < taille; i++)
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
        for (int i = 0; i < t.taille; i++)
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