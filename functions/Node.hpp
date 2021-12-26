//
// Created by Divya Patel on 26/12/21.
//

//#ifndef CPP_NODE_HPP
//#define CPP_NODE_HPP
//
//#endif //CPP_NODE_HPP

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