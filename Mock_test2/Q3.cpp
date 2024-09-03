#include <iostream>
#include <vector>

using namespace std;

#define DISCOUNT_RATE 0.05

class Product{
    private:
        string name;
        double price;
    
    public:
        //constructor
        Product(string name="", double price=0.0): name(name), price(price){}

        void showInfo(){
            cout << name << ", $" << price << "\n";
        }

        //friend class to grant access to private attributes
        friend class Customer;
};

class Shop{
    private:
        string name;
        vector<Product> prodList;
    
    public: 
        //constructor   
        Shop(string name="", vector<Product> prodList = {}): name(name), prodList(prodList){}

        void showInfo(){
            cout << "Shop: " << name << endl;
            cout << "Product list: \n";
            for(Product prod : prodList){
                prod.showInfo();
            }
        }
};

class Order{
    private:
        int orderID;
        vector<Product> boughtList; //list of bought products
        double totExpense; //total expense for the order
    
    public:
        //constructor
        Order(int orderID, vector<Product> boughtList = {}, double totExpense = 0.0)
            : orderID(orderID), boughtList(boughtList), totExpense(totExpense){}
        
        void showInfo(){
            cout << "Order ID: " << orderID << endl;
            cout << "Bought list: \n";
            for(Product prod : boughtList){
                prod.showInfo();
            }
            cout << "Total Expense: " << totExpense << "\n\n";
        }
};

class Customer{
    private:
        string name;
        int accType = 1; //Normal account = 1, Gold account = 2
        vector<Order> orderList;

    public:
        //constructor
        Customer(string name="", int accType=1, vector<Order> orderList={})
            :name(name), accType(accType), orderList(orderList){}

        void buyProduct(vector<Product> prodList){
            //calculate total expenses
            double totExpense = 0.0;
            for(Product prod : prodList){
                if(accType == 2) // Gold account
                    totExpense += (prod.price * (1 - DISCOUNT_RATE));
                else  // Normal account
                    totExpense += prod.price;
            }           
            //assign running number for orderID starting from 1  
            int orderID = orderList.size() + 1;
            //create and add the order into the list
            orderList.push_back(Order(orderID, prodList, totExpense));
        }

        void showInfo(){
            cout << "Customer: " << name << endl;
            cout << "Account type: " << ((accType==2)?"Gold":"Normal")<< "\n\n";

            for(Order o : orderList){
                o.showInfo();
            }
        }
};

int main()
{
    // Create a shop and add products
    Product pd1("Shoe", 20), pd2("Car", 1000), pd3("Book", 10);
    Shop shop1("Shop1", {pd1, pd2, pd3});
    shop1.showInfo();
    
    cout << "\n";
    //Test normal and gold accounts
    Customer acc1("Name1", 1);
    acc1.buyProduct({pd1});
    acc1.buyProduct({pd1, pd2, pd3});
    acc1.showInfo();

    cout << "\n";

    Customer acc2("Name2", 2);
    acc2.buyProduct({pd1});
    acc2.buyProduct({pd1, pd2, pd3});
    acc2.showInfo();

    cout << "\n";

    return 0;
}