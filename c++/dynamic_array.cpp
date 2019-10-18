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

    void print() {
        cout << "[";
        for (int i=0; i<size-1; i++) {
            cout << data[i] << ", ";
        }
        cout << data[size-1] << "]" << endl;
    }
};

int main() {
    return 0;
}
