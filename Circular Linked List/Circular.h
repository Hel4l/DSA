//
// Created by h4zem on 8/26/2023.
//

#ifndef CIRCULAR_LINKED_LIST_CIRCULAR_H
#define CIRCULAR_LINKED_LIST_CIRCULAR_H
#include <iostream>
struct node {
    int data;
    node *next;
};

class Circular {
    node* head;
public:
    Circular();

    void insert(int val);

    void deleteIdx(int pos);

    void display();

    ~Circular();
};


#endif //CIRCULAR_LINKED_LIST_CIRCULAR_H
