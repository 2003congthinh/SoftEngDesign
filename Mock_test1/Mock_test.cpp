#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

float doubleVal(float n){
    return (n * 2);
}

int doubleVal(int n){
    return (n * 2);
}

string doubleVal(string n){
    int hex;
    string result;
    stringstream ss;
    ss << std::dec << n;
    ss >> hex;
    hex = hex*2;
    ss >> std::hex >> std::showbase >> result;
    return result;
}

int main(int argc, char *argv[]){
    if (argc < 2){
        cout << "Please enter a number";
        return 1;
    }
    
    string args = argv[1];
    stringstream ss(args);
    if (args.find("0x") == 0 || args.find("0X") == 0){  // Original code: args.find("0x") || args.find("0X") - This condition will always evaluate to true because 
                                                        // std::string::find returns std::string::npos when the substring is not found, which is a non-zero value and
                                                        // thus considered true in a boolean context.  --- This is where everything gone wrong, be mindful in the future.
        cout << doubleVal(args);                        
    } else if (args.find(".")!= string::npos){          // Original code: args.find(".")
        float n;
        ss >> n;
        n = doubleVal(n);
        cout << n;
    } else {
        int n;
        ss >> n;
        int newN = doubleVal(n);
        cout << newN;
    }

    return 0;
}

// float doubleVal(float n) {
//     return (n * 2);
// }

// int doubleVal(int n) {
//     return (n * 2);
// }

// int doubleVal(string n) {
//     int hex;
//     stringstream ss;
//     ss << std::hex << n;
//     ss >> hex;
//     return (hex * 2);
// }

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         cout << "Please enter a number" << endl;
//         return 1;
//     }

//     string args = argv[1];
//     stringstream ss;

//     if (args.find("0x") == 0 || args.find("0X") == 0) {
//         // Handle hexadecimal input
//         int doubledValue = doubleVal(args);
//         cout << std::hex << std::showbase << doubledValue;
//     } else if (args.find(".") != string::npos) {
//         // Handle floating-point input
//         float n;
//         stringstream ss(args);
//         ss >> n;
//         float doubledValue = doubleVal(n);
//         cout << std::fixed << std::setprecision(2) << doubledValue;
//     } else {
//         // Handle integer input
//         // int n;
//         // stringstream ss(args);
//         // ss >> n;
//         // int doubledValue = doubleVal(n);
//         // cout << doubledValue;

//         int n;
//         ss << args;
//         ss >> n;
//         n = doubleVal(n);
//         cout << n;
//     }

//     return 0;
// }