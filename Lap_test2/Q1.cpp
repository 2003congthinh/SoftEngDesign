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
#include <exception> // for std::exception
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
using namespace std;

class Block {
    private:
        int id;
        string hash;
        Block* prev = nullptr;
    public:
        //constructor
        Block(int id, string hash, Block* prev) : id(this->id), hash(this->hash), prev(this->prev) {}
        //some methods
        int getId() const { return id; }
        string getHash() const { return hash; }
        Block* getPrev() const { return prev; }
};
/*
Reads block data from "chain.dat" and constructs a linked list of Block objects.
Each new block is added to the front of the list, making it the new head.
*/
void readData(Block *&head) {
    ifstream file("chain.dat");
    int id;
    string hash;
    while (file >> id >> hash) {
        // cout << "Id: " << id << "\n" << "Hash: " << hash << "\n";
        try {
        head = new Block(id, hash, head);
        } catch (const std::length_error& exception)
    {
        std::cerr << "You ran out of memory!" << '\n';
    }
    }
}

/*
Question 1(b) Complete the method to print out the blockchain to the console.
Show ID, hash, and previous hash.
Example of sample output:
Block ID: 859357
Hash: 00000000000000000002fbbe14b2eb41d27e72e868dd92c0617b81db2ce158eb
Prev Hash: 000000000000000000020f1a69f52052369f96d4c91e8d1eace5b99ac9adc554
Block ID: 859356
Hash: 000000000000000000020f1a69f52052369f96d4c91e8d1eace5b99ac9adc554
Prev Hash: 000000000000000000027517bc0e6a5b0707260c590ae08f988a2fb3c5a8ce66
Block ID: 859355
Hash: 000000000000000000027517bc0e6a5b0707260c590ae08f988a2fb3c5a8ce66
Prev Hash: None (Genesis Block)
NOTE: Write your own comments.
*/

void showChain(Block *&head) {
    cout << "output chain here";
}

int main() {
    // initialise the head pointer
    Block* head = nullptr;
    readData(head);
    showChain(head);
    return 0;
}