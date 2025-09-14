#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}

    void insert(int val) {
        Node* n = new Node(val);
        if (!head) head = n;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
        }
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* reverseK(Node* node, int k) {
        Node* prev = NULL;
        Node* curr = node;
        Node* next = NULL;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next) node->next = reverseK(next, k);
        return prev;
    }

    void reverseInGroups(int k) {
        head = reverseK(head, k);
    }
};

int main() {
    LinkedList l;
    for (int i = 1; i <= 8; i++) l.insert(i);

    cout << "Original: "; l.print();
    l.reverseInGroups(3);
    cout << "Reversed in groups of 3: "; l.print();
}
