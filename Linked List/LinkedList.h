#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int size;
public:

    LinkedList();

    int size_t();

    void insert(int x);

    void insert(int x, int pos);

    void insertSorted(int x);

    void deletePosition(int pos);

    void reverse();

    void removeDupicates();

    void display();

    void reverseDisplay();

    void reverseRec();

    bool search(int x);

    bool isSorted();

    ~LinkedList();
};


#endif //LINKEDLIST_LINKEDLIST_H
