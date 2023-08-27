#include "LinkedList.h"

LinkedList::LinkedList() : head{nullptr}, tail{nullptr}, size{0} {

}

void LinkedList::insert(int x) {
    if (size == 0) {
        tail = new Node;
        head = tail;
        tail->data = x;
        tail->next = nullptr;
    } else {
        tail->next = new Node;
        tail = tail->next;
        tail->data = x;
        tail->next = nullptr;
    }
    size++;
}

void LinkedList::display() {
    Node *it = head;
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
    r_dis(head);
    cout << endl;
}

void LinkedList::insertSorted(int x) {
    Node *t = new Node;
    t->data = x;
    if (tail->data <= x) {
        tail->next = t;
        tail = t;
        tail->next = nullptr;
    } else {
        t->next = nullptr;
        if (head == nullptr || head->data >= x) {
            t->next = head;
            head = t;
        } else {
            Node *p = head;
            while (p->next != nullptr && p->next->data < x) {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    size++;
}

void LinkedList::reverse() {
    Node *s = nullptr, *q = nullptr, *p = head;
    while (p != nullptr) {
        s = q;
        q = p;
        p = p->next;
        q->next = s;
    }
    head = q;
}

bool LinkedList::search(int x) {
    Node *p = head;
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
    Node *p = head;
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    if (pos == 0) {
        t->next = head;
        head = t;
    } else if (pos == size - 1) {
        tail->next = t;
        tail = t;
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
    Node *p = head;
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
        head = head->next;
        delete p;
    }
    size--;
}

bool LinkedList::isSorted() {
    Node *p = head;
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
        Node *q = head, *p = head->next;
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

Node *rec(Node *p) {
    if (p->next == nullptr)
        return p;
    rec(p->next)->next = p;
    return p;
}

void LinkedList::reverseRec() {
    rec(head);
    swap(head, tail);
    tail->next = nullptr;
}

LinkedList::~LinkedList() {
    Node *p;
    while (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}