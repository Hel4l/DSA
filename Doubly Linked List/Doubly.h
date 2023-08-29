#ifndef DOUBLY_LINKED_LIST_DOUBLY_H
#define DOUBLY_LINKED_LIST_DOUBLY_H

#include <iostream>

struct node {
    node *prev;
    int data;
    node *next;
};

class Doubly {
    node *head;
    node *tail;
public:
    Doubly();

    void inset(int val, int idx);

    int delElement(int idx);

    void display();

    void rdisplay();

    void reverse();

    int size_t();

    ~Doubly();
};


#endif //DOUBLY_LINKED_LIST_DOUBLY_H
