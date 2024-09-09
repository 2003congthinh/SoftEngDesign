#include <iostream>
using namespace std;

#define SIZE 5

class Employee{
    protected:
        string name;
        double salary;
    public:
        //constructor
        Employee(string name="", double salary=0.0):name(name), salary(salary){}

        void showInfo(){
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};

//Inheritance
class Manager : public Employee{
    private:
        double allowance;
    public:
        //constructor
        Manager(string name="", double salary=0.0, double allowance=0.0):Employee(name, salary), allowance(allowance){}

        void showInfo(){
            Employee::showInfo();
            cout << "Allowance: " << allowance << endl;
        }

        //totalIncome to get total income
        double totalIncome(){
            return salary + allowance; 
        }
};

int main()
{
    //(a)
    Employee emp1("Ling Huo Chong", 1000.00);
    emp1.showInfo();

    Manager mgr1("Michael Owen", 2000.00, 500.00);
    mgr1.showInfo();

    //(b)
    Manager *mgrArr = new (nothrow) Manager[SIZE]{{"Michael Owen", 2000.00, 500.00}, 
                                        {"David Platt", 1000.00, 150.00},
                                        {"David Seaman", 1500.00, 200.00},
                                        {"Eric Cantona", 5000.00, 1000.00},
                                        {"Peter Schmeichel", 3500.00, 350.00}};
    
    if(mgrArr == nullptr){
        cout << "Memory allocation failed!\n";
        return -1;
    }

    //initialize tIncome to 0
    double tIncome = 0;

    //for loop to calculate total incomes of all managers
    for(int i=0; i<SIZE; i++){
        tIncome += mgrArr[i].totalIncome();
    }
    
    //calculate and print the average total income 
    cout << "\nAverage total income: " << tIncome/SIZE << endl;

    //free up the allocated memory
    delete []mgrArr;

    return 0;
}