// Implementing the list ADT using the dynamic array data structure

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int *data;
    int capacity;

public:
    int size;

    DynamicArray() {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    DynamicArray(vector<int> initial) {
        size = 0;
        capacity = 1;
        data = new int[capacity];

        for (int e: initial) {
            append(e);
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    int operator[](int index) {
        if (0 <= index and index < size) {
            return data[index];
        } else {
            throw out_of_range("List index out of range");
        }
    }

    int length() {
        return size;
    }

    void resize() {
        capacity *= 2;
        int *tmp = new int[capacity];
        
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }

    void append(int n) {
        if (size >= capacity) {
            resize();
        }

        data[size] = n;
        size++;
    }

    void insert(int index, int n) {
        if (0 <= index and index <= size) {
            if (size >= capacity) {
                resize();
            }

            for (int i=size-1; i>=index; i--) {
                data[i+1] = data[i];
            }
            data[index] = n;
            size++;
        } else {
            throw out_of_range("List index out of range");
        }
    }

    void shrink_to_fit() {
        while (2*size <= capacity) {
            capacity /= capacity;
        }
        int *tmp = new int[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }

    void remove(int index) {
        if (0 <= index and index < size) {
            for (int i=index; i<size; i++) {
                data[i] = data[i+1];
            }
            size--;

            if (float(size)/capacity < 0.25) {
                shrink_to_fit();
            } 
        } else {
            throw out_of_range("List index out of range");
        }
    }

    int pop() {
        int tmp = data[size-1];
        remove(size-1);
        return tmp;
    }

    int pop(int index) {
        if (0 <= index and index < size) {
            int tmp = data[index];
            remove(index);
            return tmp;
        } else {
            throw out_of_range("List index out of range");
        }
    }

    void print() {
        cout << "[";
        for (int i=0; i<size-1; i++) {
            cout << data[i] << ", ";
        }
        cout << data[size-1] << "]" << endl;
    }
};

int main() {
    // Example of use
}
