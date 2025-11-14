#include <iostream>
using namespace std;

class Heap {
private:
    int size;
    int capacity;
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

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    bool isMaxHeap() {
        for (int i = 0; i <= (size - 2) / 2; i++) {
            int left = leftChild(i);
            int right = rightChild(i);
            if (left < size && arr[i] < arr[left])
                return false;
            if (right < size && arr[i] < arr[right])
                return false;
        }
        return true;
    }
    void heapSort() {
        int n = size;
        // Build max heap (already a max heap if using insert)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify_down(i);
      
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            size--;
            heapify_down(0);
        }
        size = n; // restore original size
    }

    int* getArray() {
        return arr;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Heap heap(10);
  
    heap.insert(10);
    heap.insert(7);
    heap.insert(9);
    heap.insert(5);
    heap.insert(6);
    heap.insert(8);

    cout << "Heap after insertion: ";
    heap.display();

    // Check if it's a Max-Heap
    if (heap.isMaxHeap())
        cout << "Array represents a Max-Heap." << endl;
    else
        cout << "Array does NOT represent a Max-Heap." << endl;

    heap.heapSort();
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < heap.getSize(); i++)
        cout << heap.getArray()[i] << " ";
    cout << endl;

    return 0;
}
