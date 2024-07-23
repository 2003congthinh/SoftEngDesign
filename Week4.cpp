#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

// Exp1
class ComplNum{
private:
    double real;
    double imag;
public:
    ComplNum(double real_val = 0.0, double imag_val = 0.0){
        real = real_val;
        imag = imag_val;
    }

    ComplNum operator ++ (){
        real++;
        imag++;
        return *this;
    }

    ComplNum operator ++ (int){
        real++;
        imag++;
        return *this;
    }

    ComplNum operator -- (){
        real--;
        imag--;
        return *this;
    }

    ComplNum operator -- (int){
        real--;
        imag--;
        return *this;
    }

    ComplNum operator - (ComplNum &n3){
        ComplNum temp;
        temp.real = this->real - n3.real;
        temp.imag = this->imag - n3.imag;
        return temp;
    } 

    ComplNum operator - (double num){
        ComplNum temp;
        temp.real = this->real - num;
        temp.imag = this->imag - num;
        return temp;
    } 

    //Without the friend keyword, the operator- function would not be able to access the private members (real and imag) 
    //of the ComplNum class. By declaring it as a friend, we allow this non-member function to access these members directly.
    friend ComplNum operator - (double num, ComplNum &n3) {
        ComplNum temp;
        temp.real = num - n3.real;
        temp.imag = num - n3.imag;
        return temp;
    }

    // Friend function to compute the absolute value
    friend double abs(const ComplNum &n);

    string toString(){
        return "Real: " + to_string(real) + "; " + "Imag: " + to_string(imag);
    }
};

// Definition of the friend function to compute the absolute value
double abs(const ComplNum &n) {
    return sqrt(n.real * n.real + n.imag * n.imag);
}

// Exp2
class BankAcc{
public:
    string name;
    float amount;

    BankAcc(string name_val, float amount_val){
        name = name_val;
        amount = amount_val;
    }

    void withdraw(float num){
        if(this->amount >= num){
            this->amount -= num; // this->amount = this->amount - num;
            cout << "Updated amount: " << this->amount;
        } else{
            cerr << "The withdraw is larger than the amount." ;
        }
    }

    // Method to save account details to a file
    void saveToFile(ofstream &outFile) const {
        outFile << name << " " << amount << endl;
    }

    string toString(){
        return "Name: " + name + "; " + "Amount: " + to_string(amount);
    }
};


int main(int argc, char *argv[]){
    // Exp1
    // // a)
    // ComplNum n1(10,20), n2(30,40);
    // ComplNum r1 = n1++, r2 = ++n1;
    // cout << "R1: " << r1.toString() << "; " << "R2: " << r2.toString() << "\n";

    // // b)
    // ComplNum result;
    // result = n2 - n1;
    // cout << result.toString() << "\n";

    // result = n2 - 10.0;
    // cout << result.toString() << "\n";

    // result = 20.0 - n1;
    // cout << result.toString() << "\n";

    // result = n2--;
    // cout << result.toString() << "\n";

    // result = --n2;
    // cout << result.toString() << "\n";

    // // c)
    // // Testing the friend function for absolute value
    // double absValue = abs(n1);
    // cout << "Absolute value of n1: " << absValue << "\n";

    // Exp2
    // // a)
    // BankAcc p1("Thomas", 500000), p2("Thinh",600000), p3("Someone",700000);
    // cout << p1.toString() << "\n" << p2.toString() << "\n" << p3.toString() << "\n";

    // // b)
    // p1.withdraw(600000);
    // cout << p1.toString();

    // // c)
    // // Check if a filename is provided
    // if (argc > 1) {
    //     ofstream outFile(argv[1]);
    //     if (!outFile) {
    //         cerr << "Error opening file for writing: " << argv[1] << endl;
    //         return 1;
    //     }

    //     // Save account details to file
    //     p1.saveToFile(outFile);
    //     p2.saveToFile(outFile);
    //     p3.saveToFile(outFile);

    //     outFile.close();
    //     cout << "Account details saved to " << argv[1] << endl;
    // } else {
    //     cout << "No file specified, data not saved." << endl;
    // }

    // Exp3
    // a)

    return 0;
}