#include "tableauTri.cpp"

int main()
{
    TableauTri t1(10);

    cin >> t1;

    cout << t1;

    int freq = t1.frequence(5.0);
    cout << "La fréquence de 5.0 dans le tableau est " << freq << endl;

    t1.supprimer(5.0);

    TableauTri t2 = t1;

    t2 = t2 * 2;

    TableauTriResp t3 = t2;

    cout << t3;

    return 0;
}