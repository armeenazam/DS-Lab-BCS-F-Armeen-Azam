#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
   
    Node(int val){
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList{
public:
    Node* head;
    
    SinglyLinkedList(){
        head = NULL;
    }

    Node* reverseList(Node* head){
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;

        while(curr != NULL){
            next = curr->next;
            curr->next =prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if (head == NULL ){
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp-> next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }

    bool isPalindrome(){
        if (!head || !head->next) return true;

        Node* fast = head;
        Node* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
         Node* secondHalf = reverseList(slow->next);

        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf; 
        bool palindrome = true;
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        slow->next = reverseList(secondHalfCopy);

        return palindrome;

    }
};

int main(){
    SinglyLinkedList l1;
    int n, val;
    cout << "Enter the number of nodes: ";
    cin >>n;

    cout <<"Enter elements: ";
    for(int i=0; i<n ; i++){
        cin >> val;
        l1.insertAtEnd(val);
    }

    if(l1.isPalindrome()){
        cout << "Palindrome...." <<endl; 

    }
    else {
        cout << "Not a palindrome...." << endl;
    }
    return 0;

}