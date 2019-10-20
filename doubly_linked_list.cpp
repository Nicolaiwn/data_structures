// Implementing the list ADT using the doubly linked list data structure

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int n, Node *p1) {
        data = n;
        left = p1;
        right = nullptr;
    }

    Node(int n, Node *p1, Node *p2) {
        data = n;
        left = p1;
        right = p2;
    }
};

class DoublyLinkedList {
private:
    Node *head, *tail;

public:
    int size;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    DoublyLinkedList(vector<int> initial) {
        head = nullptr;
        tail = nullptr;
        size = 0;

        for (int n: initial) {
            append(n);
        }
    }

    int operator[](int index) {
        if (0 <= index and index < size) {
            Node *t = head;
            for (int i=0; i<index; i++) {
                t = t->right;
            }
            return t->data;
        } else {
            throw out_of_range("List index out of range");
        }
    }

    int length() {
        return size;
    }

    void append(int n) {
        if (head == nullptr) {
            head = new Node(n, nullptr, nullptr);
            tail = head;
            size++;
            return;
        }

        Node *t = new Node(n, tail);
        tail->right = t;
        tail = tail->right;
        size++;
    }
};

int main() {
    // Example of use
}
