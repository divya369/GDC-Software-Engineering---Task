//
// Created by Divya Patel on 25/12/21.
//

//#ifndef CPP_LS_HPP
//#define CPP_LS_HPP
//
//#endif //CPP_LS_HPP

//#include "fstream"
//#include "iostream"
#include "Node.hpp"
#include "CreateLinkedList.hpp"
#include "fstream"

void ls() {
//    ifstream file;
//    string tempString;
//    Node* head = NULL;
//    file.open("task.txt");
//
//    // get data from file and sort while creating linked list
//    while(getline(file, tempString)) {
//        Node* newNode = new Node();
//        int flag = tempString.find(' ');
//        newNode->priority = stoi(tempString.substr(0, flag));   // extract priority from file
//        newNode->task = tempString.substr(flag + 1,'\n');      // extract task from file
//
//        Node* temp;
//        if (head == NULL || (head->priority >= newNode->priority)) {
//            newNode->next = head;
//            head = newNode;
//        } else {
//            temp = head;
//            while(temp->next != NULL && temp->next->priority < newNode->priority) {
//                temp = temp->next;
//            }
//            newNode->next = temp->next;
//            temp->next = newNode;
//        }
//    }
//    file.close();

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