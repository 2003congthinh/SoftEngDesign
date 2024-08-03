/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2024-2
    Lab Assessment: 1
    Author: Nguyen Cong Thinh
    ID: S3926387
    Compiler used: g++ 13.2.0
    Created  date: 3/8/2024
    Acknowledgement: Canvas, W3school.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class Task{
private:
    int t_Hour;
    int t_Minute;
public:
    Task(){
        t_Hour = 0;
        t_Minute = 0;
    }

    Task(int hour, int minute){
        t_Hour = hour;
        if(minute>59 || minute<0){
            t_Minute = 0;
        } else{
            t_Minute = minute;
        }
    }

    void toString(){
        cout << setw(2) << setfill('0') << t_Hour;
        cout << ":";
        cout << setw(2) << setfill('0') << t_Minute;
    }

    friend ostream& operator << (ostream &out, Task &task);

    bool operator > (Task &task){
        // this->toString();
        // cout << " > ";
        // cout << task << "?  ";
        if(this->t_Hour == task.t_Hour){
            if(this->t_Minute > task.t_Minute){
                // cout << "True";
                return true;
            } else {
                // cout << "False";
                return false;
            }
        } else if(this->t_Hour > task.t_Hour){
            // cout << "True";
            return true;
        } else {
            // cout << "False";
            return false;
        }
    }
};

ostream& operator << (ostream &out, Task &task){
    task.toString();
    return out;
}

void printTask(){
    ifstream ifile;
    ifile.open("data.txt");
    if(!ifile){
        cerr << "Can't open file.";
    }
}

int main(){
    Task ta(2,9), tb(2,35);
    // t1 > t2;
    cout << ta << " < " << tb << "?";
    if ((ta > tb)){
        cout << "True" << "\n";
    } else {
        cout << "False" << "\n";
    }

    Task t1,t2,t3,t4;
    Task tArr[4] = {t1,t2,t3,t4};
    int hour;
    int min;
    cout << "Enter hours and minutes taken for your task: ";
    cin >> hour >> min;
    Task myT(hour,min);
    cout << "\n" << "Your task: " << myT << "\n";

    ifstream ifile;
    ifile.open("data.txt");
    if(!ifile){
        cerr << "Can't open file.";
    }
    string line;
    int count = 0;
    int bigger = 0;
    while(getline(ifile, line)){
        // cout << line << "\n";
        int hour;
        int min;
        stringstream ss(line);
        ss >> hour >> min;
        Task temp(hour,min);
        tArr[count] = temp;
        cout << tArr[count] << "\n";
        if(tArr[count] > myT){
            bigger += 1;
        }
        count++;
    }
    cout << "Number of tasks time greater than your task time: " << bigger; 

    return 0;
}