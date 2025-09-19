#include <iostream>
using namespace std;

void functionA(int n) {
    if (n <= 0) return; 
    cout << "A:" << n << " ";
    functionB(n - 1);
}

void functionB(int n) {
    if (n <= 0) return; 
    cout << "B:" <<n<< " ";
    functionA(n - 1);
}

int main() {
    cout << "Indirect Recursion: ";
    functionA(3);
    cout << endl;
}
