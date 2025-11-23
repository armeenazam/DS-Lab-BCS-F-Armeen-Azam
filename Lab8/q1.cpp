#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertIntoBST(Node* root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
        root->right = insertIntoBST(root->right, data);
    else if (data < root->data)
        root->left = insertIntoBST(root->left, data);
    // duplicate values ignored
    return root;
}

Node* minValue(Node* root){
    if (root == nullptr) return nullptr;
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* deletion(Node* root, int data){
    if (root == NULL){
        cout <<"Tree is empty.." << endl;
        return root;
    }
    if(root->data == data){

        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child 
             //left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp; 
        }
             //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp; 
        } 

        //2 child case
        if(root->left != NULL && root->right != NULL){
            int minimum = minValue(root->right)->data; // min from right or u can take max from left
            root->data = minimum;
            root->right = deletion(root->right, minimum);
            return root;
        }
    }

    else if(data < root->data){
        root->left = deletion(root->left, data);
        return root;
    }

    else{
        root->right = deletion(root->right, data);
        return root;
    }

}

bool searchNode(Node* root, int data) {
    if (root == nullptr)
        return false;

    if (data == root->data)
        return true;
    else if (data > root->data)
        return searchNode(root->right, data);
    else
        return searchNode(root->left, data);
}



Node* maxValue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* takeInput(Node* root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;

    cout << "Enter data for BST (-1 to stop): " << endl;
    root = takeInput(root);

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nInorder Traversal:\n";
    inorderTraversal(root);
    cout << "\nPreorder Traversal:\n";
    preorderTraversal(root);
    cout << "\nPostorder Traversal:\n";
    postorderTraversal(root);
    cout << endl;

    int key;
    cout << "\nEnter value to search: ";
    cin >> key;

    if (searchNode(root, key))
        cout << "Node is in the tree." << endl;
    else
        cout << "Node is not in the tree." << endl;
    
    root = deletion(root, key);
    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);
    return 0;
}
