//
// Created by Divya Patel on 26/12/21.
//

#include "fstream"
#include "Node.hpp"
#include "CreateLinkedList.hpp"

void report() {
    Node* temp = createSortedLinkedList();
    ofstream file2;
    file2.open("task.txt");
    int count = 1;
    while(temp != NULL) {
        int a = temp->priority;
        string b = temp->task;
        if (count > 1) {
            file2<<"\n";
        }
        file2<<a;
        file2<<" ";
        file2<<b;
        temp = temp->next;
        count++;
    }
    file2.close();

    std::ifstream taskFile;
    string tempString, task;
    int priority, flag, i;

    taskFile.open("task.txt");
    count = 0;
    while(getline(taskFile, tempString)) {
        count++;
    }
    taskFile.close();

    taskFile.open("task.txt");
//    taskFile.seekg(0, std::ios::beg);
    i = 1;
    cout<<"Pending : "<<count<<"\n";
    while(getline(taskFile, tempString)) {
        flag = tempString.find(' ');
        priority = stoi(tempString.substr(0, flag));
        task = tempString.substr(flag + 1, tempString.length());
        cout<<i<<". "<<task<<" ["<<priority<<"]\n";
        i++;
    }
    taskFile.close();

    std::cout<<"\n";

    std::ifstream doneTask;
    doneTask.open("done.txt");
    count = 0;
    while(getline(doneTask, tempString)) {
        count++;
    }
    doneTask.close();

    doneTask.open("done.txt");
    i = 1;
    cout<<"Completed : "<<count<<"\n";
    while(getline(doneTask, tempString)) {
        flag = tempString.find(' ');
        task = tempString.substr(flag + 1, tempString.length());
        std::cout<<i<<". "<<task<<"\n";
        i++;
    }
    doneTask.close();
}