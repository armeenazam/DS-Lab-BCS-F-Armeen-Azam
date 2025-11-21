#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void push(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// ===========================
void swapNodes(Node* a, Node* b) {
    if (a == b) return;
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* head, Node* end, Node*& newHead, Node*& newEnd) {
    Node* pivot = end;
    Node* prev = NULL, *cur = head, *tail = pivot;

    newHead = head;
    newEnd = end;

    Node* pivotPrev = NULL;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (newHead == pivot) newHead = cur;  
            prev = cur;
            cur = cur->next;
        }
        else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    Node* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = newHead;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(Node*& head) {
    if (!head || !head->next) return;

    Node* end = head;
    while (end->next)
        end = end->next;

    head = quickSortRecur(head, end);
}

int main() {
    Node* head = NULL;
    
    push(head, 3);
    push(head, 5);
    push(head, 1);
    push(head, 9);
    push(head, 8);
    push(head, 7);
    push(head, 10);

    cout << "\nOriginal list:\n";
    printList(head);

    quickSort(head);

    cout << "\nSorted list:\n";
    printList(head);  // Expected: 1 3 5 7 8 9 10

    return 0;
}
