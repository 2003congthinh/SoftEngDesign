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

    void showInfo(){
        cout << name << ": bought the house for $" << buyPrice << "\n";
    }
};

void printOut(Broker *firstBroker){
    firstBroker->showInfo();
    /* Loop through the linked list */
    Broker *temp = firstBroker;  //start with first node (head)
    int count = 1;
    while (temp != nullptr){
        if(count == 5){
            break;
        }
        cout << temp->name << " --> ";
        temp = temp->nextBuyer; //access next node
        cout << temp->name << " : price = $" << temp->buyPrice << "\n";
        count ++;
    }
}

void lowestProfit(Broker *firstBroker){
    int bPrice;
    int sPrice;
    int profit = firstBroker->nextBuyer->buyPrice - firstBroker->buyPrice;
    /* Loop through the linked list */
    Broker *temp = firstBroker;  //start with first node (head)
    int count = 1;
    while (temp != nullptr){
        if(count == 5){
            break;
        }
        int tempProf;
        bPrice = temp->buyPrice;
        temp = temp->nextBuyer; //access next node
        sPrice = temp->buyPrice;
        tempProf = sPrice - bPrice;
        if(tempProf < profit){
            profit = tempProf;
        }
        count ++;
    }
    cout << profit;
}

int main(){
    /* Initialize nodes */
    Broker b1("David", 800), b2("John", 1000), b3("Peter", 1100), b4("Luna", 1800), b5("Sophia", 3500);

    /* Save reference of first node in head */
    Broker *firstBroker = &b1;

    /* Connect nodes */
    b1.nextBuyer = &b2;
    b2.nextBuyer = &b3;
    b3.nextBuyer = &b4;
    b4.nextBuyer = &b5;

    // a)
    printOut(firstBroker);

    // b)
    lowestProfit(firstBroker);

    return 0;
}