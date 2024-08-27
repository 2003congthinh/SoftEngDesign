#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;

class Broker {
public:
    string name;
    int buyPrice;
    Broker *nextBuyer = nullptr;

    Broker(string name = "", int price = 0){
        this->name = name;
        this->buyPrice = price;
    }
};

int main(){
    

    return 0;
}