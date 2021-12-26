//
// Created by Divya Patel on 25/12/21.

#include "Node.hpp"
#include "CreateLinkedList.hpp"
#include "fstream"

void ls() {
    Node* head = createSortedLinkedList();
    int totalNode = 0;
    string tempString;
    ofstream file2;

    Node* temp = head;
//    file2.open("task.txt");
    while(temp != NULL) {
        totalNode++;
        temp = temp->next;
    }
//    file2.close();
    if(totalNode == 0) {
        cout<<"There are no pending tasks!\n";
    }

    temp = head;
    file2.open("task.txt");
    int count = 1;
    while(temp != NULL) {
        int a = temp->priority;
        string b = temp->task;
        cout<<count<<". "<<b<<" ["<<a<<"]\n";
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
}