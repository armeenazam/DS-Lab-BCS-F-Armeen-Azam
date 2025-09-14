#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) : data(val), next(NULL), prev(NULL) {}
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

    // Singly → Doubly
    DNode* toDoubly() {
        if (!head) return NULL;
        DNode* newHead = new DNode(head->data);
        DNode* dCurr = newHead;
        Node* sCurr = head->next;

        while (sCurr) {
            dCurr->next = new DNode(sCurr->data);
            dCurr->next->prev = dCurr;
            dCurr = dCurr->next;
            sCurr = sCurr->next;
        }
        return newHead;
    }

    // Singly → Circular
    Node* toCircular() {
        if (!head) return NULL;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = head;
        return head;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void printDoubly(DNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    LinkedList l;
    l.insert(1);
    l.insert(2);
    l.insert(3);

    cout << "Original Singly: "; l.print();

    DNode* d = l.toDoubly();
    cout << "Converted Doubly: "; printDoubly(d);

    Node* c = l.toCircular();
    cout << "Converted Circular (first 5 shown): ";
    Node* t = c;
    for (int i = 0; i < 5; i++) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
