//
// Created by h4zem on 9/3/2023.
//

#include "StackLinkedList.h"

StackLinkedList::StackLinkedList() : t{nullptr} {

}

void StackLinkedList::push(int num) {
    node *p = new node;
    p->data = num;
    p->next = t;
    t = p;
}

void StackLinkedList::pop() {
    if (!empty()) {
        node *x = t;
        t = t->next;
        delete x;
    }
}

int StackLinkedList::top() {
    return t->data;
}

bool StackLinkedList::empty() {
    if (t != nullptr) {
        return false;
    }
    return true;
}