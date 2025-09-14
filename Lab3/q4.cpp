#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class CircularList {
public:
    Node* head;
    CircularList(int n) {
        head = new Node(1);
        Node* prev = head;
        for (int i = 2; i <= n; i++) {
            prev->next = new Node(i);
            prev = prev->next;
        }
        prev->next = head;
    }

    int josephus(int k) {
        Node* ptr = head;
        while (ptr->next != ptr) {
            for (int i = 1; i < k - 1; i++)
                ptr = ptr->next;
            Node* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
            ptr = ptr->next;
        }
        return ptr->data;
    }
};

int main() {
    int n = 7, k = 3;
    CircularList cl(n);
    cout << "Josephus Survivor (n=7, k=3): " << cl.josephus(k) << endl;
}
