#include <iostream>
using namespace std;

class Heap {
private:
    int size;       // current number of elements
    int capacity;   // maximum size of heap
    int* arr;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapify_up(int index) {
        while (index != 0 && arr[index] > arr[parent(index)]) {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }

    void heapify_down(int index) {
        int largest = index;
        int l = leftChild(index);
        int r = rightChild(index);

        if (l < size && arr[l] > arr[largest])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify_down(largest);
        }
    }

public:
    Heap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[cap];
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap overflow!" << endl;
            return;
        }
        arr[size] = value;
        heapify_up(size);
        size++;
    }

    void update_key(int i, int new_val) {
        if (i < 0 || i >= size) {
            cout << "Invalid index!" << endl;
            return;
        }

        int old_val = arr[i];
        arr[i] = new_val;

        if (new_val > old_val)
            heapify_up(i);
        else
            heapify_down(i);
    }

    void delete_key(int i) {
        if (i < 0 || i >= size) {
            cout << "Invalid index!" << endl;
            return;
        }

        arr[i] = arr[size - 1];  // Replace with last element
        size--;
        heapify_down(i);          // Restore heap property
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap heap(10);

    heap.insert(8);
    heap.insert(7);
    heap.insert(6);
    heap.insert(5);
    heap.insert(4);

    cout << "Max Heap: ";
    heap.display();

    heap.update_key(3, 10);
    cout << "after updating index 3 to 10: ";
    heap.display();

    heap.delete_key(1);
    cout << "after deleting index 1: ";
    heap.display();

    return 0;
}
