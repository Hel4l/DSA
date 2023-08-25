#include "Linked List.h"

LinkedList::LinkedList() : node{nullptr}, cur{node}, size{0} {
}

void LinkedList::insert(int x) {
    if (size == 0) {
        cur = new Node;
        node = cur;
        cur->data = x;
        cur->next = nullptr;
    } else {
        cur->next = new Node;
        cur = cur->next;
        cur->data = x;
        cur->next = nullptr;
    }
    size++;
}

void LinkedList::display() {
    Node *it = node;
    while (it != nullptr) {
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl;
}

int LinkedList::size_t() {
    return this->size;
}

void r_dis(Node *p) {
    if (p != nullptr) {
        r_dis(p->next);
        cout << p->data << " ";
    }
}

void LinkedList::reverseDisplay() {
    r_dis(node);
    cout << endl;
}

void LinkedList::insertSorted(int x) {
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    if (node == nullptr || node->data >= x) {
        t->next = node;
        node = t;
    } else {
        Node *p = node;
        while (p->next != nullptr && p->next->data < x) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    size++;
}

void LinkedList::reverse() {
    Node *s = nullptr, *q = nullptr, *p = node;
    while (p != nullptr) {
        s = q;
        q = p;
        p = p->next;
        q->next = s;
    }
    node = q;
}

bool LinkedList::search(int x) {
    Node *p = node;
    while (p != nullptr) {
        if (p->data == x) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void LinkedList::insert(int x, int pos) {
    int cnt = 0;
    Node *p = node;
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    if (pos == 0) {
        t->next = node;
        node = t;
    } else if (pos == size - 1) {
        cur->next = t;
        cur = t;
    } else {
        while (cnt != pos - 1) {
            cnt++;
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    size++;
}

void LinkedList::deletePosition(int pos) {
    Node *q = nullptr;
    Node *p = node;
    int cnt = 0;
    while (cnt != pos) {
        q = p;
        p = p->next;
        cnt++;
    }
    if (cnt != 0) {
        q->next = p->next;
        delete p;
    } else {
        node = node->next;
        delete p;
    }
    size--;
}

bool LinkedList::isSorted() {
    Node *p = node;
    int x = INT_MIN;
    while (p != nullptr) {
        if (p->data < x) {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

void LinkedList::removeDupicates() {
    if (size > 1) {
        Node *q = node, *p = node->next;
        while (p != nullptr) {
            if (q->data != p->data) {
                q = p;
                p = p->next;
            } else {
                q->next = p->next;
                delete p;
                p = q->next;
                size--;
            }
        }
    }
}

LinkedList::~LinkedList() {
    Node *p;
    while (node != nullptr) {
        p = node;
        node = node->next;
        delete p;
    }
}