#include <iostream>
#include "StackADT.h"
#include "StackLinkedList.h"

using namespace std;

int main() {
    StackLinkedList s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(4);
    s.push(5);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
