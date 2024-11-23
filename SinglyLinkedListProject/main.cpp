#include <iostream>
#include "SinglyLinkedList.cpp"

int main() {
    SinglyLinkedList<int> l1;
    l1.addATFront(5);
    l1.addATFront(10);
    l1.addAtEnd(20);
    l1.addATFront(30);

    std::cout << "List after additions: ";
    l1.displayList();

    l1.removeFirst();
    std::cout << "List after removing first: ";
    l1.displayList();

    l1.removeLast();
    std::cout << "List after removing last: ";
    l1.displayList();

    std::cout << "Size of the list: " << l1.size() << std::endl;

    int valueToFind;
    std::cout << "Enter the number to find: ";
    std::cin >> valueToFind;

    Node<int>* foundNode = l1.find(valueToFind);
    if (foundNode != nullptr) {
        std::cout << "Found value " << valueToFind << " in the list." << std::endl;
    }
    else {
        std::cout << "Value " << valueToFind << " not found in the list." << std::endl;
    }

    return 0;
}
