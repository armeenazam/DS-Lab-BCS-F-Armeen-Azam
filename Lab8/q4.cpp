#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) { data=d; left=right=NULL; }
};

class BST {
public:
    Node* root;
    BST() { root=NULL; }

    Node* insert(Node* r,int v) {
        if(!r) return new Node(v);
        if(v < r->data) r->left = insert(r->left,v);
        else r->right = insert(r->right,v);
        return r;
    }
    void insert(int v) { root = insert(root,v); }

    Node* search(Node* r,int v) {
        if(!r) return NULL;
        if(r->data==v) return r;
        if(v < r->data) return search(r->left,v);
        return search(r->right,v);
    }

    void inorder(Node* r) {
        if(!r) return;
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }

    void searchInsertPrint(int v) {
        if(!search(root,v)) insert(v);
        inorder(root);
    }
};

int main() {
    BST t;
    t.insert(50);
    t.insert(20);
    t.insert(70);
    t.insert(10);
    t.insert(30);

    cout<<"Enter value: ";
    int x;
    cin>>x;

    t.searchInsertPrint(x);
    return 0;
}
