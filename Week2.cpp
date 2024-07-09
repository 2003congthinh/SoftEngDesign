#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
using namespace std;

int min(int x, int num[]){
    int min_num = num[0];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x;j++){
            int test_num = (num[i] < num[j]) ? num[i] : num[j];
            min_num = (test_num < min_num) ? test_num : min_num;
        }
    }
    return min_num;
}

// int hexToNum(string hex){
//     if(hex[0]=="0" && hex[1]=="x"){} // The error in your code is due to the fact that you are trying to compare characters in a string using "==" with double quotes,
                                        // which is used for string literals. In C++, single characters should be compared using single quotes.
// }

int hexToNum(string hex) {
    // Check if the string starts with "0x" or "0X"
    if (hex.size() >= 2 && hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        hex = hex.substr(2); // Remove the "0x" or "0X" prefix
    }
    
    int num = 0;
    int base = 1; // Initially, the base is 16^0

    for (int i = hex.size() - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            num += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            num += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            num += (hex[i] - 'a' + 10) * base;
        } else {
            throw invalid_argument("Invalid hexadecimal digit");
        }
        base *= 16;
    }

    return num;
}

void strToChar(string str){
    char strChar[str.size()];
    for(int i = 0; i < str.size(); i++){
        strChar[i] = str[i];
    };
    for(int j = 0; j < sizeof(strChar); j++){
        cout << strChar[j] << " ";
    }
}

int main(){
    // Exp1
    // int size = 15;
    // int num[size] = {18,3,9,52,60,32,5,1,7,71,2,23,15,67};
    // cout << min(size, num);

    // Exp2
    // string a;
    // cout << "Enter your hex number(prefix \"0x\", please): ";
    // cin >> a;
    // cout << "Hex to num is: " << hexToNum(a);

    // Exp3
    // a)
    // string str;
    // cout << "enter string: ";
    // cin >> str;
    // strToChar(str);
    
    // b)

}