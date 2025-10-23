#include<iostream>
using namespace std;

class Node{
public:
    string data;
    Node* next;

    Node(string val){
        data = val;
        next = NULL;
    }
};

class Stack{
public: 
    int capacity;
    Node* head;
    int currSize;

    Stack(int cap){
        capacity = cap;
        head = NULL;
        currSize =0;
    }

    bool isEmpty(){
        return(head == NULL);
    }

    bool isFull(){
        return(currSize >= capacity);
    }

    void push(string val){
        if(isFull()){
            cout << "Stack is full" << endl;
            return;
        }
        Node* newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        currSize++;
    }

    string pop(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return "";
        }
        Node* temp = head;
        head = head->next;
        string x = temp->data;
        delete temp;
        currSize--;
        return x;
    }

    string peek(){
         if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return "";
        }
        return head->data;
    }

    void clear(){
        while (!isEmpty()){
            pop();
        }
    }

    ~Stack(){
        clear();
    }
};

void visitNewPage(string newPage, Stack &back, Stack &forward, string &currPage){
        if(currPage != ""){
            back.push(currPage);
        }
        forward.clear();
        currPage = newPage;
        cout << "Visited: "<< currPage << endl;
    }

    void goBack(Stack &back, Stack &forward, string &currPage){
        if(back.isEmpty()){
            cout << "No prev page" << endl;
            return;
        }
        forward.push(currPage);
        currPage = back.pop();
        cout << "Went back to: " << currPage << endl;
    }

    void goFwd(Stack &back, Stack &forward, string &currPage){
        if (forward.isEmpty()){
            cout << "No fwd page" << endl;
            return;
        }

        back.push(currPage);
        currPage = forward.pop();
        cout << "Went forward to: " << currPage << endl;
    }

    void showCurrPage(string currPage){
        cout << "Current Page: " << currPage << endl;
    }

int main(){
    Stack backStack(10);
    Stack forwardStack(10);
    string currentPage = "Home";

    cout << "Starting at: " << currentPage << endl;

    visitNewPage("About", backStack, forwardStack, currentPage);
    visitNewPage("Gallery", backStack, forwardStack, currentPage);
    visitNewPage("Contact", backStack, forwardStack, currentPage);
    visitNewPage("Blog",backStack, forwardStack, currentPage);

    goBack(backStack, forwardStack, currentPage);
    goBack(backStack, forwardStack, currentPage);
    goFwd(backStack, forwardStack, currentPage);

    

    showCurrPage(currentPage);

}