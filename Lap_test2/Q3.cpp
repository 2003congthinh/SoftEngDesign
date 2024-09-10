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
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;

class Analyser {
    private:
        int values;
        Analyser *nextNode = nullptr;
    public:
        Analyser(int values = 0){
            this->values = values;
        }

        void setNextNode(Analyser *next){
            nextNode = next;
        }

        int getVal(){
            return values;
        }

        Analyser* getNode(){
            return nextNode;
        }
};

void traverseList(Analyser *temp){
    cout << "Linked list after traverseList is called" << "\n";
    while(temp != nullptr){
        if(temp->getVal() == -1){
            temp = temp->getNode();
            while(temp != nullptr){
                cout << temp->getVal() << "-->";
                temp = temp->getNode();
                if(temp->getVal() == -1){
                    break;
                }
            }
        }
        temp = temp->getNode();
    }
}

void removeNeg(Analyser *temp){
    cout << "Linked list after removeNeg is called" << "\n";
    while(temp != nullptr){
        if(temp->getNode()->getVal() == -1){
            temp->setNextNode(temp->getNode()->getNode());
        }
        cout << temp->getVal() << "-->";
        temp = temp->getNode();
    }
}

void printMin(Analyser *temp){
    int min = temp->getVal();
    while(temp != nullptr){
        if(temp->getVal() < min){
            min = temp->getVal();
        }
        temp = temp->getNode();
    }
    cout << "Min is " << min;
}

int main(){
    Analyser a1(3), a2(-1), a3(5), a4(2), a5(7), a6(-1);
    Analyser *firstNode = &a1;

    a1.setNextNode(&a2);
    a2.setNextNode(&a3);
    a3.setNextNode(&a4);
    a4.setNextNode(&a5);
    a5.setNextNode(&a6);

    traverseList(firstNode);
    cout << "\n";
    cout << "\n";
    removeNeg(firstNode);
    cout << "\n";
    cout << "\n";
    printMin(firstNode);

    return 0;
}