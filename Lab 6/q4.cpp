#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() { return (front == 0 && rear == SIZE - 1) || (rear + 1 == front); }
    bool isEmpty() { return front == -1; }

    void enqueue(int val) {
        if (isFull())
            cout << "Queue is Full!\n";
        else {
            if (isEmpty())
                front = rear = 0;
            else
                rear = (rear + 1) % SIZE;
            arr[rear] = val;
            cout << val << " enqueued\n";
        }
    }

    void dequeue() {
        if (isEmpty())
            cout << "Queue is Empty!\n";
        else {
            cout << arr[front] << " dequeued\n";
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.enqueue(5);
    q.display();
}
