//
// Created by h4zem on 9/3/2023.
//

#ifndef STACK_STACKADT_H
#define STACK_STACKADT_H


class StackADT {
    int t;
    int size;
    int *arr;
public:
    StackADT();

    void push(int x);

    void pop();

    bool empty();

    int top();
};

#endif //STACK_STACKADT_H
