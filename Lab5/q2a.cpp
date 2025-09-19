#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n == 0) return; 
    cout << n << " ";
    printNumbers(n - 1); 
}

int main() {
    cout << "Direct Recursion: ";
    printNumbers(5);
    cout << endl;
    return 0;
}
