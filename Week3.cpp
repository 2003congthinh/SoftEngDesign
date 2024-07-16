#include <iostream>
#include <string>
// #include <cmath>
// #include <stdexcept>
// #include <iomanip>
#include <fstream>
using namespace std;

class Student {
private:
    string password;
public:
    int score;
    string name;

    Student(int score_val = 0, string name_val = "", string password_val = " "){
        cout << "Default constructor is called \n";
        score = score_val;
        name = name_val;
        password = password_val;
    }

    void showInfo(){
        cout <<"score & name: " << score << " " << name << "\n";
    }

    string getPwd(){return password;}

    void changePwd(){
        string filename = name + ".dat";
        ifstream infile(filename);

        if (!infile) {
            // If no existing password file, allow setting a new password
            cout << "No existing password. Enter new password: ";
            cin >> password;
            ofstream outfile(filename);
            outfile << password;
            outfile.close();
            cout << "Password set successfully." << endl;
        } else {
            // If there is an existing password, check the old password first
            string existingPassword;
            infile >> existingPassword;
            infile.close();

            string oldPassword;
            cout << "Enter existing password: ";
            cin >> oldPassword;

            if (oldPassword == existingPassword) {
                cout << "Enter new password: ";
                cin >> password;
                ofstream outfile(filename);
                outfile << password;
                outfile.close();
                cout << "Password changed successfully." << endl;
            } else {
                cout << "Incorrect password. Password not changed." << endl;
            }
        }
    }
};

void savePwd(){
    string pwd;
    cin >> pwd;

    // Create and open a text file
    ofstream PwdFile("pwd.dat");

    // Write to the file
    PwdFile << pwd;

    // Close the file - Why do we close the file? It is considered good practice, and it can clean up unnecessary memory space.
    PwdFile.close();
}

void readPwd(){
    // Create a text string, which is used to output the text file
    string myPwd;

    // Read from the text file
    ifstream PwdFile("pwd.dat");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (PwdFile, myPwd)) {
        // Output the text from the file
        cout << myPwd;
    }

    // Close the file
    PwdFile.close();
}

int main(){
    // Exp 1
    // int choice;
    // cout << "Password management program";
    // cin >> choice;
    // if (choice == 1){
    //     savePwd();
    // } else if (choice == 2){
    //     readPwd();
    // } else {
    //     cout << "Wrong choice";
    // }
    
    // Exp 2
    // // b)
    Student stu1(10,"Thinh");
    Student stu2(9,"Thomas");
    Student stu3(15,"James");
    // stu1.showInfo();
    // stu2.showInfo();
    // // c)
    // Student stuArr[3] = {stu1,stu2,stu3};
    // Student stu;
    // int maxScore = stuArr[0].score;
    // int x = sizeof(stuArr) / sizeof(stuArr[0]);
    // for(int i = 0; i < x; i++){
    //     if(stuArr[i].score > maxScore){
    //         maxScore = stuArr[i].score;
    //         stu = stuArr[i];
    //     }
    // }
    // stu.showInfo();

    // Exp 3
    cout << "Testing password change for student: " << stu1.name << endl;
    stu1.changePwd();

    // Exp 4
    

    return 0;
}

