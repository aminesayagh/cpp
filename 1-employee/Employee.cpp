
#include <iostream>
using namespace std;
using std::string;

#include "Employee.h"

Employee::Employee(string nomDonnes, int _id): nom(nomDonnes), id(_id) {}
 Employee::Employee(string nomDonnes): nom(nomDonnes){}
Employee::~Employee(){nom = "";
            id = 0;
}
void Employee::setSalary(int salary){this->salary = salary;}
 int Employee::getSalary(){ return salary;}
void Employee::setage(int age){ this->age=age;}
int Employee::getage(){return age;}
 void Employee::asktopromotion(){if(age==0){
                return;
            }
            if (age>30){
                cout << "vous avez une promotion" << endl;
            }else {
                cout << "vous n'avez pas une promotion" << endl;
            }}


class Developpeur:Employee{
    private:
        string lang;
    
    public:
        Developpeur(string nom,int id,string lang): Employee(nom,id), lang(lang) {
            
        }
}; 

int main(){
    cout << "Partie 1";
    Employee emp("Assim");
    emp.setage(45);
    emp.asktopromotion();

    cout << "Partie 2";
    Developpeur dvp("Assim",3,"cpp");
    return 0;
}