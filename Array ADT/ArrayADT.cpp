//
// Created by h4zem on 7/6/2023.
//

#include "ArrayADT.h"

ArrayADT::ArrayADT() : size{0}, capacity{10} {
    arr = new int[10];
}

ArrayADT::ArrayADT(const ArrayADT &a) {
    delete[]this->arr;
    this->arr = new int[a.size];
    this->size = a.size;
    for (int i = 0; i < size; ++i) {
        arr[i] = a.arr[i];
    }
    this->capacity = a.capacity;
}

void ArrayADT::insert(int n) {
    if (size >= capacity) {
        int *temp = new int[2 * capacity];
        capacity *= 2;
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        delete[]arr;
        arr = temp;
        temp = nullptr;
    }
    arr[size] = n;
    size++;
}

void ArrayADT::display() {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

void ArrayADT::insert(int n, int idx) {
    if (idx <= size) {
        if (size == capacity) {
            int *temp = new int[2 * capacity];
            capacity *= 2;
            for (int i = 0; i < size; ++i) {
                temp[i] = arr[i];
            }
            delete[]arr;
            arr = temp;
            temp = nullptr;
        }
        for (int i = size; i > idx; --i) {
            arr[i] = arr[i - 1];
        }
        arr[idx] = n;
        size++;
    }
}

int ArrayADT::linSearch(int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

void ArrayADT::remove(int idx) {
    for (int i = idx; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int ArrayADT::get(int idx) {
    return arr[idx];
}

int &ArrayADT::operator[](int idx) const {
    return arr[idx];
}

void ArrayADT::set(int n, int idx) {
    arr[idx] = n;
}

int ArrayADT::Max() {
    int mx = INT_MIN;
    for (int i = 0; i < size; ++i) {
        mx = max(mx, arr[i]);
    }
    return mx;
}

int ArrayADT::Min() {
    int mn = INT_MAX;
    for (int i = 0; i < size; ++i) {
        mn = min(mn, arr[i]);
    }
    return mn;
}

void ArrayADT::reverse() {
    for (int i = 0, j = size - 1; i < j; ++i, --j) {
        swap(arr[i], arr[j]);
    }
}

bool ArrayADT::BinSearch(int key) {
    int l = -1, r = size;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

void ArrayADT::InsertSorted(int n) {
    if (size == capacity) {
        int *temp = new int[2 * capacity];
        capacity *= 2;
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        delete[]arr;
        arr = temp;
        temp = nullptr;
    }
    int idx = 0;
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] > n) {
            arr[i + 1] = arr[i];
        } else {
            idx = i + 1;
            break;
        }
    }
    arr[idx] = n;
    size++;
}

bool ArrayADT::checkSorted() {
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void ArrayADT::rightLessThan0() {
    int i = 0, j = size - 1;
    while (i < j) {
        if (arr[i] < 0) {
            i++;
        }
        if (arr[j] >= 0) {
            j--;
        }
        if (arr[i] >= 0 && arr[j] < 0) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

void ArrayADT::Merg(const ArrayADT &a, const ArrayADT &b) {
    delete[]arr;
    arr = new int[a.size + b.size];
    int i = 0, j = 0, k = 0;
    while (i < a.size || j < b.size) {
        if (i != a.size && a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    size = a.size + b.size;
    capacity = a.size + b.size;
}

void ArrayADT::Union(const ArrayADT &a, const ArrayADT &b) {
    delete[]arr;
    arr = new int[a.size + b.size];
    int i = 0, j = 0, k = 0;
    while (i < a.size || j < b.size) {
        if (i != a.size && j != b.size && a[i] == b[i]) {
            arr[k] = a[i];
            i++, j++;
        } else {
            if (i != a.size && a[i] < b[i]) {
                arr[k] = a[i];
                i++;
            } else {
                arr[k] = b[j];
                j++;
            }
        }
        k++;
    }
    size = k;
    capacity = a.size + b.size;
}

ArrayADT::~ArrayADT() {
    delete[]arr;
}