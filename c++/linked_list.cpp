// Implementing the list ADT using the singly linked list data structure

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int n) {
        data = n;
        next = nullptr;
    }

    Node(int n, Node *p) {
        data = n;
        next = p;
    }
};

class LinkedList {
private:
    Node *head, *tail;

public:
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(vector<int> initial) {
        head = nullptr;
        tail = nullptr;
        size = 0;

        for (int n: initial) {
            append(n);
        }
    }

    ~LinkedList() {
        Node *t = head;
        Node *tmp;

        for (int i=0; i<size; i++) {
            tmp = t->next;
            delete t;
            t = tmp;
        }
    }

    int operator[](int index) {
        if (0 <= index and index < size) {
            Node *t = head;
            for (int i=0; i<index; i++) {
                t = t->next;
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
            head = new Node(n);
            tail = head;
            size++;
        }

        Node *t = new Node(n);
        tail->next = t;
        tail = tail->next;
        size++;
    }

    void print() {
        Node *t = head;
        cout << "[";
        for (int i=0; i<size-1; i) {
            cout << t->data << ", ";
            t = t->next;
        }
        cout << t->data << "]" << endl;
    }
};

int main() {
    // Example of use
}
