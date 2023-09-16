//
// Created by h4zem on 9/3/2023.
//

#include "StackADT.h"


StackADT::StackADT(): t{-1}, size{10} {
    arr = new int[10];
}


void StackADT::push(int x) {
    if (t == size - 1) {
        arr = new int[size * 2];
        size *= 2;
    }
    t++;
    arr[t] = x;
}

void StackADT::pop() {
    if(t!= -1)
        t--;
}

int StackADT::top() {
  return arr[t];
}


bool StackADT::empty() {
    if(t == -1)
        return true;
    return false;
}