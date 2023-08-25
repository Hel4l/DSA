#include "ArrayADT.h"

int main() {
    ArrayADT a, b;
    a.insert(1);
    a.insert(1);
    b.insert(1);
    b.insert(2);
    ArrayADT c{a};
    c.Merg(a, b);
    a.display();
    cout << endl;
    b.display();
    cout << endl;
    ArrayADT u;
    u.Union(a, b);
    u.display();
    return 0;
}
