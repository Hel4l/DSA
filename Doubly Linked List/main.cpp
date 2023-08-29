#include "Doubly.h"

using namespace std;

int main() {
    Doubly d;
    d.inset(2, 0);
    d.inset(3, 0);
    d.inset(3, 2);
    d.inset(5, 3);
    d.inset(0, 1);
    d.display();
    cout << d.delElement(2) << endl;
    d.display();
    d.inset(1, 0);
    d.reverse();
    d.display();
    return 0;
}
