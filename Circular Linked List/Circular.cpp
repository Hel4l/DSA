//
// Created by h4zem on 8/26/2023.
//

#include "Circular.h"
using namespace std;

Circular::Circular(): head{nullptr}{

}

void Circular:: insert(int val) {
    node* tail = new node;
    tail->data = val;
    if(head == nullptr){
        head = tail;
        head->next = head;
    }
    else{
        node* p =  head;
        while(p->next != head){
            p = p->next;
        }
        tail->next = head;
        p->next = tail;
    }
}


void Circular:: deleteIdx(int pos) {
    if(head != nullptr){
        node*q = nullptr;
        node*p = head;
        node*it = head;
        int cnt = 0;
        while(it->next != head){
            cnt++;
            it = it->next;
        }
        if(cnt >= pos){
            if(pos != 0){
                for (int i = 0; i <= pos - 1; ++i) {
                    q = p;
                    p = p->next;
                }
                q->next = p->next;
                delete p;
            }
            else{
                head = head->next;
                it->next = head;
                delete p;
            }
        }
        else{
            cout<<"no elements\n";
        }
    }
    else{
        cout<<"no elements\n";
    }
}

void Circular::display() {
    node *p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }
    while(p!= head);
    cout<<endl;
}

Circular::~Circular() {
    node* d = head->next;
    while(d!= head){
        node* p = d;
        d = d->next;
        delete p;
    }
    delete head;
    head = nullptr;
}