//
// Created by Divya Patel on 26/12/21.
//

#include "CreateLinkedList.hpp"
#include "fstream"

void done(int taskToBeDone) {
    Node* head = createSortedLinkedList();
    Node* current = head;
    int count = 1;

    if (taskToBeDone == 0) {
        cout<<"Error: no incomplete item with index #"<<taskToBeDone<<" exists.";
    }

    while(current != NULL) {
        if (taskToBeDone == count) {
            std::ofstream doneFile;
            doneFile.open("done.txt", ios_base::app);
            int a = current->priority;
            string b = current->task;
            doneFile<<a;
            doneFile<<" ";
            doneFile<<b;
            doneFile<<"\n";
            cout<<"Marked item as done.\n";
            doneFile.close();

            // write data back to task.txt file
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
            break;
        } else {
            count++;
            current= current->next;
        }
    }
}