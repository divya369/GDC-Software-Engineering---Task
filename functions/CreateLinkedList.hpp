//
// Created by Divya Patel on 26/12/21.
//

#include "fstream"
#include "iostream"
#include "Node.hpp"
#pragma once

Node* createSortedLinkedList() {
    ifstream file;
    string tempString;
    Node* head = NULL;
    file.open("task.txt");

    // get data from file and sort while creating linked list
    while(getline(file, tempString)) {
        Node* newNode = new Node();
        int flag = tempString.find(' ');
        newNode->priority = stoi(tempString.substr(0, flag));   // extract priority from file
        newNode->task = tempString.substr(flag + 1, tempString.length());      // extract task from file

        Node* temp;
        if (head == NULL || (head->priority >= newNode->priority)) {
            newNode->next = head;
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL && temp->next->priority < newNode->priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    file.close();
    return head;
}