#include <iostream>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void addFirst(T value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void addLast(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeFirst() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void removeLast() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Node* find(T value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << "->";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    SinglyLinkedList<int> list;

    list.addFirst(10);
    list.addFirst(20);
    list.addLast(5);
    list.addFirst(30);

    std::cout << "List after additions: ";
    list.printList();

    list.removeFirst();
    std::cout << "List after removing first: ";
    list.printList();

    list.removeLast();
    std::cout << "List after removing last: ";
    list.printList();

    std::cout << "Size of the list: " << list.size() << std::endl;

    std::cout << "Enter the number to find: ";
    int numberToFind;
    std::cin >> numberToFind;

    auto result = list.find(numberToFind);
    if (result != nullptr) {
        std::cout << "Found node with value: " << result->data << std::endl;
    } else {
        std::cout << "Value not found in the list." << std::endl;
    }

    return 0;
}
