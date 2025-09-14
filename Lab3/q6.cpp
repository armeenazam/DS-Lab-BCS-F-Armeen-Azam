#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) : data(val), next(NULL), child(NULL) {}
};

class MultiLevelList {
public:
    Node* head;
    MultiLevelList() : head(NULL) {}

    void print(Node* h) {
        while (h) {
            cout << h->data << " ";
            h = h->next;
        }
        cout << endl;
    }

    Node* flatten(Node* head) {
        if (!head) return NULL;
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childHead = flatten(curr->child);

                curr->next = childHead;

                Node* temp = childHead;
                while (temp->next) temp = temp->next;
                temp->next = nextNode;

                curr->child = NULL;
            }
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    MultiLevelList ml;
    ml.head = new Node(1);
    ml.head->next = new Node(2);
    ml.head->next->next = new Node(3);

    ml.head->next->child = new Node(4);
    ml.head->next->child->next = new Node(5);

    cout << "Flattened: ";
    Node* flat = ml.flatten(ml.head);
    ml.print(flat);
}
