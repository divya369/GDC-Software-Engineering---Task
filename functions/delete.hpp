//
// Created by Divya Patel on 26/12/21.
//
//
//#ifndef CPP_DELETE_HPP
//#define CPP_DELETE_HPP
//
//#endif //CPP_DELETE_HPP

#include "CreateLinkedList.hpp"
#include "Node.hpp"

void deleteTask(int taskToBeDeleted) {
    Node* head = createSortedLinkedList();
    Node* current = head;
    string tempString;
    int totalNode=0;

    Node* temp1 = head;
    while(temp1 != NULL) {
        totalNode++;
        temp1 = temp1->next;
    }
    if (taskToBeDeleted==0 || taskToBeDeleted > totalNode) {
        cout<<"Error: task with index #"<<taskToBeDeleted<<" does not exist. Nothing deleted.";
    }

    int countNode = 0;
    while (current != NULL) {
        countNode++;
        if (taskToBeDeleted == countNode) {
            std::ofstream taskFile;
            taskFile.open("task.txt");
            Node* temp = head;
            int count = 1;
            while(temp != NULL) {
                if (temp == current) {
                    temp = temp->next;
                    continue;
                } else {
                    int a = temp->priority;
                    string b = temp->task;
                    if (count > 1) {
                        taskFile<<"\n";
                    }
                    taskFile<<a;
                    taskFile<<" ";
                    taskFile<<b;
                    temp = temp->next;
                    count++;
                }
            }
            taskFile.close();
            std::cout<<"Deleted task #"<<taskToBeDeleted<<"\n";
            break;
        } else {
            current= current->next;
        }
    }
}