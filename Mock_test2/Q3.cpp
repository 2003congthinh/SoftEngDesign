#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
#include <vector>
using namespace std;


class Product {
    public:
        string name;
        double price;

        Product(string name = "", double price = 0.0){
            this->name = name;
            this->price = price;
        }

        void showInfo(){
            cout << "Product: " << name << " | " << "Price: " << price << "\n";
        }
};

class Shop {
    public: 
        string name;
        vector<Product> pros;

        Shop(string name = "", vector<Product> pros = {}){
            this->name = name;
            this->pros = pros;
        }

        void showInfo(){
            cout << "Name: " << name << "\n";
            for(Product pro : pros){
                pro.showInfo();
            }
            cout << "\n";
        }
};

class Order{
    public:
        int orderId;
        vector<Product> boughtPros;
        double totalPrice;

        Order(int id = 1, vector<Product> boughtPros = {}){   //The error message you encountered is due to the fact that in C++, default arguments are only allowed for the trailing parameters of a function or constructor. If a parameter is given a default value, all subsequent parameters must also have default values. It used to be: vector<Product> boughtPros
            this->orderId = id;
            this->boughtPros = boughtPros;
            double total = 0.0;
            for(int i =0; i < boughtPros.size(); i++){
                total += boughtPros[i].price;
            }
            this->totalPrice = total;
        }

        void showInfo(){
            cout << "Order ID: " << orderId << endl;
            cout << "Bought list: \n";
            for(Product prod : boughtPros){
                prod.showInfo();
            }
            cout << "Total Expense: " << totalPrice << "\n\n";
        }
};

class Customer{
    public:
        string name;
        vector<Order> list;
        int type = 1;

        Customer(string name = "", int type = 1, vector<Order> orderList={}){
            this->name = name;
            this->type = type;
            this->list = orderList;
        }

        void buyProduct(vector<Product> prodList){
            int orderId = list.size() + 1;
            this->list.push_back(Order(orderId, prodList));
        }

        void showInfo(){
            cout << "Customer: " << name << endl;
            cout << "Account type: " << ((type==2)?"Gold":"Normal")<< "\n\n";

            for(Order o : list){
                o.showInfo();
            }
        }
};

int main(){
    Product p1("Candy", 1), p2("Pen", 5), p3("Eraser", 2), p4("Apple", 5), p5("Paper",0.5);
    vector<Product> pros = {p1,p2,p3,p4,p5};
    Shop s("Convenience Store", pros);
    s.showInfo();

    Customer acc1("Name1", 1);
    acc1.buyProduct({p1});
    acc1.buyProduct(pros);
    acc1.showInfo();

    return 0;
}