#include "Circular.h"
using namespace std;

int main() {
    Circular c;
    c.insert(3);
    c.insert(4);
    c.insert(5);
    c.insert(1);
    c.insert(2);
    c.display();
    c.deleteIdx(1);
    c.display();
    c.deleteIdx(1);
    c.display();
    return 0;
}
