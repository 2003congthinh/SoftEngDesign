#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;

class Employee {
public:
    string name;
    double salary;

    Employee(string name = "", double sal = 0.0){
        this->name = name;
        this->salary = sal;
    }

    void showInfo(){
        cout << name << ": " << salary << " ";
    }
};

class Manager : public Employee {
public:
    double allowance;

    Manager(string name = "", double sal = 0.0, double allow = 0.0)
        : Employee(name, sal){
        this->allowance = allow;
    }

    void showInfo(){
        Employee::showInfo();
        cout << allowance << "\n";
    }
};

int main(){
    Manager man1("John", 1000, 50), man2("Jim", 2000, 100), man3("Jake", 4000, 200), man4("Jack", 8000, 400), man5("Jaqui", 16000, 800);
    man1.showInfo();

    Manager man[] = {man1, man2, man3, man4, man5};

    int total;
    for(int i = 0; i < 5; i++){
        total += man[i].salary;
    }
    cout << "The avg sal is: " << total/5;

    return 0;
}