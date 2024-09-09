#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;

class Broker{
    public:
        string name;
        int buyPrice;
        Broker *nextBuyer = nullptr;

        Broker(string name = "", int price = 0){
            this->name = name;
            this->buyPrice = price;
        }

        void showInfo(){
            cout << name << ": bought the house for $" << buyPrice << "\n";
        }
};

void printOut(Broker *firstBuyer){
    Broker *temp = firstBuyer;
    temp->showInfo();
    for(int i = 0; i < 4; i++){
        cout << temp->name << " --> " << temp->nextBuyer->name << " : price = $" << temp->nextBuyer->buyPrice << "\n";
        temp = temp->nextBuyer;
    }
}

void lowestProfit(Broker *firstBuyer){
    Broker *temp = firstBuyer;                                    // need this line cuz line 37 already change temp
    cout << "Broker with lowest income is: ";
    string name = "David";
    int firstProf = firstBuyer->nextBuyer->buyPrice - firstBuyer->buyPrice;
    for(int i = 0; i < 4; i++){
        int tempProf = temp->nextBuyer->buyPrice - temp->buyPrice;
        if(tempProf < firstProf){
            firstProf = tempProf;
            name = temp->name;
        }
        temp = temp->nextBuyer;
    }
    cout << name << " with profit of: $" << firstProf;
}

int main(){
    Broker b1("David", 800), b2("John", 1000), b3("Peter", 1100), b4("Luna", 1800), b5("Sophia", 3500);
    Broker *firstBuyer = &b1;
    b1.nextBuyer = &b2;
    b2.nextBuyer = &b3;
    b3.nextBuyer = &b4;
    b4.nextBuyer = &b5;
    b5.nextBuyer = nullptr;

    printOut(firstBuyer);

    lowestProfit(firstBuyer);

    return 0;
}