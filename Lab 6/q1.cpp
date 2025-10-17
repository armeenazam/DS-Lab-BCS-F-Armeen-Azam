#include <iostream>
using namespace std;

class Stack{
private:   
    int top;
    int size;
    int* array;
public:
    Stack(int n){
        top = -1;
        size = n;
        array = new int[size];
    }
     
    
    void push(int x){
        if ( top >= size-1){
            cout << "Stack overflow" << endl;
            return;
        }
        else{
            array[++top] = x; 
        }
    }
    
    int pop(){
        if(top == -1){
            cout <<"Stack is empty"<< endl;
            return -1;
        }
        int var = array[top--];
        return var;
    }
    
    int peek(){
         if(top == -1){
            cout <<"Stack is empty"<< endl;
             return -1;
        }
        int var = array[top];
        return var;
    }
    
     void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack contents (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    
};
int main() {
    Stack s1(6);
    for(int i=0; i<6; i++){
        s1.push(i);
    }
    
    int p = s1.peek();
    cout << "Top Element :" << p << endl; 
    
    cout << "Popped elements: " << endl;
    for(int i=0; i<6; i++){
        int res = s1.pop();
        cout << res << endl;
    }
    s1.display();

    return 0;
}