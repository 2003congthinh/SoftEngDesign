#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <iomanip>
using namespace std;

int min(int x, int num[]){
    int min_num = num[0];
    for(int i = 0; i < x; i++){
        if(num[i] < min_num){
            min_num = num[i];
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
    int size = 14;
    int num[size] = {18,3,9,52,60,32,5,4,7,71,2,23,15,67};
    cout << min(size, num);

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
    //Precision
    // cout << 3.14159 << " " << 12.3456 << " (DATA TO DISPLAY)\n";
    // cout << "precision = 3: \n";
    // cout << std::setprecision(3)
    // << 3.14159 << " " << 12.3456 << "\n\n";
    // /* Note: setprecision(n) applies to the entire number,
    // must use the fixed-point format to apply to the fractional part only*/
    // cout << "precision = 3, fixed: \n";
    // cout << std::fixed << std::setprecision(3)
    // << 3.14159 << " " << 12.3456 << "\n\n\n";
    // //Width
    // cout << 10 << " " << 20 << " (DATA TO DISPLAY)\n";
    // cout << "width = 10: \n";
    // cout << std::setw(10)
    // << 10 << " " << 20 << "\n\n";
    // //Fill & Width
    // cout << "fill = 'x', width = 10: \n";
    // cout.fill('x');
    // cout.width(10);
    // cout << 10 << " " << 20 << "\n\n";
    // //Set Format Flags
    // cout << "set flags left justification and showpos, width = 10: \n";
    // cout << std::left << std::showpos << std::setw(10)
    // << 10 << " " << 20 << "\n\n";
}