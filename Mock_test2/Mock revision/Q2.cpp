#include <iostream>
using namespace std;

class Broker{
    private:
        string name;
        int buyPrice;
        Broker *nextBuyer = nullptr;
    
    public:
        //constructor
        Broker(string name="", int buyPrice=0):name(name), buyPrice(buyPrice){}

        //set connection to next buyer
        void setNextBuyer(Broker *next){
            nextBuyer = next;
        }

        //get profit
        int getProfit(){
            return (nextBuyer->buyPrice - buyPrice);
        }

        //friend functions to access private attributes
        friend void viewTransact(Broker *head);
        friend void lowestProfit(Broker *head);
};

//(a)
void viewTransact(Broker *head){
    if(head == nullptr){
        cout << "There's no transaction\n";
    }else{
        Broker *curr = head;
    
        cout << curr->name << ": initially bought the house for $" << curr->buyPrice << endl;
        
        while(curr->nextBuyer != nullptr){
             cout << curr->name << " --> " << curr->nextBuyer->name << " : price = $" << curr->nextBuyer->buyPrice << endl;  
             curr = curr->nextBuyer;
        }   
    }
}

//(b)
void lowestProfit(Broker *head){
    if(head == nullptr){
        cout << "There's no transaction\n";
    }else if(head->nextBuyer == nullptr){
        cout << "There's only one buyer. Therefore, no profit yet.\n";
    }else{
        //this pointer will point to the broker with lowest profit.
        Broker *lowestBroker = nullptr;
        Broker *curr = head;
        //set lowestBroker initially to point to the same broker as curr
        lowestBroker = curr;
        //advance curr to next buyer
        curr = curr->nextBuyer;

        //find the broker with lowest profit
        while(curr->nextBuyer != nullptr){
            if(lowestBroker->getProfit() > curr->getProfit())
                lowestBroker = curr;
            curr = curr->nextBuyer;
        }
        //print out the broker with the lowest profit
        cout << "Broker with lowest profit: " << lowestBroker->name << " with profit of " << lowestBroker->getProfit() << endl;
    }
}

int main()
{
    Broker b1("David", 800), b2("John", 1000), b3("Peter", 1200), b4("Luna", 1800), b5("Sophia", 3500);

    Broker *headPtr = &b1;
    
    b1.setNextBuyer(&b2);
    b2.setNextBuyer(&b3);
    b3.setNextBuyer(&b4);
    b4.setNextBuyer(&b5);
    b5.setNextBuyer(nullptr); //not necessary

    //(a)
    cout << "Real estate transactions\n";
    viewTransact(headPtr);
    
    //(b)
    lowestProfit(headPtr);
    
    return 0;
}