//
// Created by h4zem on 7/6/2023.
//

#ifndef ARRAY_ADT_ARRAYADT_H
#define ARRAY_ADT_ARRAYADT_H

#include <iostream>

using namespace std;

class ArrayADT {
private:
    int *arr;
    int size;
    int capacity;
public:
    ArrayADT();

    ArrayADT(const ArrayADT &a);

    void insert(int n);

    void display();

    void insert(int n, int idx);

    void set(int n, int idx);

    void remove(int idx);

    int linSearch(int key);

    // you must make the array sorted before you call this function
    bool BinSearch(int key);

    void InsertSorted(int n);

    bool checkSorted();

    void rightLessThan0();

    void Merg(const ArrayADT &a, const ArrayADT &b);

    void Union(const ArrayADT &a, const ArrayADT &b);

    int get(int idx);

    int Max();

    int Min();

    void reverse();

    int &operator[](int idx) const;

    ~ArrayADT();
};


#endif //ARRAY_ADT_ARRAYADT_H
