#include "LinkedList.h"

int main() {
    LinkedList a;
    a.insert(3);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.display();
    a.reverseRec();
    a.display();
    return 0;
}
