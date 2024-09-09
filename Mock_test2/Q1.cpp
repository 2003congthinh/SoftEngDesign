#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;

class Employee {
    private:
        string name;
        double salary;
    public:
        Employee(string name = "", double salary = 0.0){
            this->name = name;
            this->salary = salary;
        }

        void showInfo(){
            cout << "Name: " << name << "\n" << "Salary: " << salary << "\n";
        }

        friend class Manager;
};

class Manager : public Employee {
    private:
        double allowance;
    public:
        Manager(string name = "", double sal = 0.0, double allow = 0.0)
        : Employee(name, sal) {
            this->allowance = allow;
        }

        void showInfo(){
            cout << "Name: " << Employee::name << "\n" << "Salary: " << Employee::salary << "\n" << "Allowance: " << allowance << "\n";
        }

        double totalIncome(){
            double total = 0.0;
            total = Employee::salary + allowance;
            return total;
        }
};

int main(){
    Employee e("JK",300);
    e.showInfo();

    Manager m("JK",300,50);
    m.showInfo();

    Manager *man = new Manager[5]{
        {"Jack",500,50},
        {"Jake",400,40},
        {"Jaquin",300,30},
        {"Jill",200,20},
        {"John",100,10}
    };

    double total = 0;
    for(int i = 0; i < 5; i++){
        total += man[i].totalIncome();
    }
    cout << "Avg income is: " << total/5 << "\n";

    delete[] man;

    return 0;
}