/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2024-2
    Lab Assessment: 1
    Author: Nguyen Cong Thinh
    ID: S3926387
    Compiler used: g++ 13.2.0
    Created  date: 3/8/2024
    Acknowledgement: Canvas, W3school.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

void opPlus(int &num1, int &num2){
    int result = num1 + num2;
    cout << result;
}

void opMinus(int &num1, int &num2){
    int result = num1 - num2;
    cout << result;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        cout << "Insufficient arguments.";
        return 1;
    } 

    string args1 = argv[1];
    string args2 = argv[3];
    string operators = argv[2];

    if(args1.find("0x") == 0 || args1.find("0X") == 0 || args2.find("0x") == 0 || args2.find("0X") == 0){
        int num1;
        int num2;
        stringstream ss1;
        stringstream ss2;
        ss1 << args1;
        ss2 << args2; 
        ss1 >> hex >> num1;
        ss2 >> hex >> num2;
        if(operators == "+"){
            opPlus(num1,num2);
        } else if(operators == "-"){
            opMinus(num1,num2);
        }
    } else{
        cout << "Argument(s) provided is(are) not hexadecimal.";
        return 1;
    }
    return 0;
}