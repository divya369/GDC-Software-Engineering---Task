//
// Created by Divya Patel on 26/12/21.
//

#pragma once

class Node {
public:
    int priority;
    string task;
    Node* next;

    Node() {
        priority = 0;
        task = "";
        next = NULL;
    }
};