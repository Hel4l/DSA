//
// Created by h4zem on 9/3/2023.
//

#ifndef STACK_STACKLINKEDLIST_H
#define STACK_STACKLINKEDLIST_H

struct node{
    int data;
    node* next;
};

class StackLinkedList {
    node* t;
public:
    StackLinkedList();

    void push(int num);

    void pop();

    int top();

    bool empty();
};


#endif //STACK_STACKLINKEDLIST_H
