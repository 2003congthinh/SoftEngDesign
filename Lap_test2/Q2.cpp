/*
    RMIT University Vietnam
    Course: EEET2653/COSC2721
    Semester: 2024-2
    Lab Assessment: 2
    Author: Nguyen Cong Thinh
    ID: S3926387
    Compiler used: g++ 13.2.0
    Created  date: 10/09/2024
    Acknowledgement: 
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

class mealType{
    public:
        string type;
        double price;

        mealType(){}
        mealType(string type, double price){
            this->type = type;
            this->price = price;
        }

        void showInfo(){
            cout << "Type: " << type << "\n" << "Price: " << price << "\n";
        }
};
class reserveMealDetails{
    public:
        mealType mt;
        int numbOfp; 
        double totalPrice;

        reserveMealDetails(){}
        reserveMealDetails(mealType mt, double numb){
            this->mt = mt;
            this->numbOfp = numb;
            this->totalPrice = numbOfp*mt.price;
        }

        void showInfo(){
            mt.showInfo();
            cout << "Number of people: " << numbOfp << "\n" << "Total price: " << totalPrice << "\n";
        }
};
class Transaction{
    public:
        int transId;
        reserveMealDetails rsmt;

        Transaction(){}
        Transaction(int transId = 0, reserveMealDetails rsmt = {}){
            this->transId = transId;
            this->rsmt = rsmt;
        }

        void showInfo(){
            cout << "ID: " << transId << "\n";
            rsmt.showInfo();
        }
};
class Restaurant{
    public: 
        string name;
        vector<Transaction> transList;

        Restaurant(string name = "", vector<Transaction> trans = {}){
            this->name = name;
            this->transList = trans;
        }

        void makeReservation(reserveMealDetails meal){
            int id = transList.size() + 1;
            transList.push_back(Transaction(id,meal));
        }

        void showInfo(){
            cout << "Name: " << name << "\n";
            for(Transaction t : transList){
                t.showInfo();
            }
        }
};

void showTransaction(Restaurant res, int id){
    for(Transaction t : res.transList){
        if(t.transId == id){
            t.showInfo();
        }
    }
}

void showStats(Restaurant res){
    cout << "Total reservations: " << res.transList.size() << "\n";
    double totalRev = 0;
    for(Transaction t : res.transList){
        totalRev += t.rsmt.totalPrice;
    }
    cout << "Total revenue: " << totalRev;
}

int main(){
    mealType m1("Tea", 30), m2("Lunch",40), m3("Lunch",80), m4("Breakfast", 50);
    reserveMealDetails r1(m1, 2), r2(m2, 4), r3(m3, 4), r4(m4, 3);

    Restaurant re1("Res");

    re1.makeReservation(r1);
    re1.makeReservation(r3);
    re1.makeReservation(r2);
    re1.showInfo();
    cout << "\n";
    showTransaction(re1, 3);
    cout << "\n";
    showStats(re1);

    return 0;
}