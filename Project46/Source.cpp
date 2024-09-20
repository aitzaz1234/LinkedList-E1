#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtEnd(20);
    list.insert(10, 15);
    list.traverse();
    list.deleteNode(15);
    list.traverse();
    return 0;
}