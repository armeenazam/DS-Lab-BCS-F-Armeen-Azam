#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val)  {
        data = val;
        next = NULL;
    }
};


Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node* head =NULL;
    if (l1->data < l2->data) {
        head = l1;
        l1 = l1->next;
    } else
     {
        head = l2;
        l2 = l2->next;
    }

    Node* curr = head;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = (l1) ? l1 : l2;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(3);
    a->next->next = new Node(5);

    Node* b = new Node(2);
    b->next = new Node(4);
    b->next->next = new Node(6);

    Node* merged = mergeLists(a, b);
    cout << "Merged List: ";
    printList(merged);
}
