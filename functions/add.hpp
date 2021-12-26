//
// Created by Divya Patel on 25/12/21.
//

//#ifndef CPP_ADD_HPP
//#define CPP_ADD_HPP
//
//#endif //CPP_ADD_HPP

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
