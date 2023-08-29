#include "Doubly.h"

using namespace std;

Doubly::Doubly() : head{nullptr}, tail{nullptr} {}

void Doubly::inset(int val, int idx) {
    node *p = new node;
    p->data = val;
    p->next = nullptr;
    p->prev = nullptr;
    if (idx == 0) {
        p->next = head;
        if (head) head->prev = p;
        head = p;
        if (tail == nullptr) tail = head;
    } else {
        node *q = head;
        for (int i = 0; i < idx - 1; ++i) {
            q = q->next;
        }
        if (q->next)q->next->prev = p;
        p->next = q->next;
        q->next = p;
        p->prev = q;
        if (q == tail)
            tail = p;
    }
}

void Doubly::display() {
    node *p = head;
    while (p) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

void Doubly::rdisplay() {
    node *q = tail;
    while (q) {
        cout << q->data << ' ';
        q = q->prev;
    }
    cout << endl;
}

int Doubly::delElement(int idx) {
    int x;
    node *p = head;
    if (idx == 0) {
        x = p->data;
        head = head->next;
        if (head) head->prev = nullptr;
    } else {
        x = 0;
        for (int i = 0; i < idx; ++i) {
            p = p->next;
        }
        if (p == tail)
            tail = tail->prev;
        x = p->data;
        if (p->next) p->next->prev = p->prev;
        p->prev->next = p->next;
    }
    delete p;
    return x;
}

void Doubly::reverse() {
    node *p = head;
    while (p) {
        swap(p->next, p->prev);
        p = p->prev;
    }
    swap(head, tail);
}

int Doubly::size_t() {
    int cnt = 0;
    node *p = new node;
    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

Doubly::~Doubly() {
    node *p = head;
    while (head) {
        p = head;
        head->next;
        delete p;
    }
    delete p;
}