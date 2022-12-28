#include <iostream>
using namespace std;
using std::string;


class AbstractEmployee {
    virtual void askForPromotion() = 0;
};

class Employee:AbstractEmployee {
    protected:
        int salary;
    private: //
        string name;
        string company;
        int age;
    public: 
        Employee (string name, string company, int age) {
            this->name = name;
            this->company = company;
            this->age = age;
        }

        void setName(string name) {
            this->name = name;
        }
        string getName() { return this->name; }

        void setCompany(string company) {
            this->company = company;
        }
        string getCompany() { return this->company; }

        void setAge(int age) {
            this->age = age;
        }
        int getAge() { 
            return this->age; 
        }
         
        void introduceYourself() {
            cout << "Name - " << name << endl;
            cout << "Company - " << company << endl;
            cout << "Age - " << age << endl;
        }

        void askForPromotion() {
            if(age>30){
                cout << name << " got promoted " << endl;
            } else {
                cout << name << " no promotion to you " << endl;
            }
        }
};

class Developer:Employee {
    private:
        string favProgrammingLanguage;
    public: 
        Developer(string name, string company, int age, string favProgrammingLanguage): Employee(name, company, age){
            this->favProgrammingLanguage = favProgrammingLanguage;
        }
};

int main() {
    Employee employee_1 = Employee("Mohammed Amine", "happy water", 25);

    employee_1.introduceYourself();

    employee_1.askForPromotion();

    int lastAge = employee_1.getAge();
    employee_1.setAge(lastAge + 10);

    employee_1.askForPromotion();
    

    employee_1.introduceYourself();
}