//
// Created by Divya Patel on 25/12/21.
//

#include "fstream"
#include "iostream"
using namespace std;

void add(int priorityNumber, const string newTask) {
    ofstream file;
    file.open("task.txt", ios_base::app);
//    file.seekp(0, ios::end);
    if (file.tellp() == 0) {
        file<<priorityNumber;
        file<<" ";
        file<<newTask;
    } else {
        file<<"\n";
        file<<priorityNumber;
        file<<" ";
        file<<newTask;
    }
    cout<<"Added task: \""<<newTask<<"\" with priority "<<priorityNumber<<endl;
    file.close();
}
