#include <iostream>
using namespace std;
using std::string;

class Employee{
    private :
        string nom;
        int salary;
        int id;
        int age = 0;
    public:
        Employee(string nomDonnes, int _id);
        Employee(string nomDonnes);
        ~Employee();

        void setSalary(int salary);
        int getSalary();
        void setage(int age);
        int getage();
       void asktopromotion();
};
