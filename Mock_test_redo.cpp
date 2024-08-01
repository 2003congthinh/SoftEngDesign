#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// Exp 1
int doubleVal(int n){
    return (n * 2);
}

float doubleVal(float n){
    return (n * 2);
}

int doubleVal(string n){
    int newHex;
    stringstream ss; // stringstream ss(n); - this one wrong because n is still a string of "0x<somthing>" and not a hex. So it need to be converted to hex first, then to int.
    ss << hex << n; 
    ss >> newHex;
    return (newHex * 2);
}

// Exp2
class Student{
private:
    string name;
    int scores[3];
public:
    Student(){}
    Student(string name_val, int scores_val[3]){
        name = name_val;
        for(int i = 0; i < 3; i++){
            scores[i] = scores_val[i];
        }
    }

    // void showInfo(){
    //     cout << "Name: " + name + "\n" + to_string(scores[0]) + "\n" + to_string(scores[1]) + "\n" + to_string(scores[2]);
    // }

    // void inputData(){
    //     string stu_name;
    //     int stu_score[3];
    //     cout << "Please enter student's data: ";
    //     cin >> name >> stu_score[0] >> stu_score[1] >> stu_score[2];
    //     Student(stu_name,stu_score);
    // }

    void showInfo() {
        cout << "Name: " << name << "\n";
        for (int i = 0; i < 3; i++) {
            cout << "Score " << i + 1 << ": " << scores[i] << "\n";
        }
    }

    void inputData() {
        cout << "Please enter student's name: ";
        cin >> name;
        cout << "Please enter student's scores (3 scores): ";
        for (int i = 0; i < 3; i++) {
            cin >> scores[i];
        }
    }

    Student operator >> (){
        inputData();
        return *this;
    }
};

int main(int argc, char *argv[]){
    // Exp 1
    // if(argc < 2){
    //     cout << "Please enter the correct input.";
    //     return 1;
    // }

    // string args = argv[1];
    // stringstream ss(args);

    // if(args.find("0x") == 0 || args.find("0X") == 0){
    //     int newHex = doubleVal(args);
    //     // cout << hex << showbase << newHex;
    //     cout << newHex;
    // } else if (args.find(".") != string::npos){
    //     float n;
    //     ss >> n;
    //     n = doubleVal(n);
    //     cout << n;
    // } else {
    //     int n;
    //     ss >> n;
    //     n = doubleVal(n);
    //     cout << n;
    // }

    // Exp 2
    Student stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8, stu9, stu10;
    stu1.inputData();
    stu1.showInfo();

    return 0;
}