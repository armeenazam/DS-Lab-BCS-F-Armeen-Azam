#include <iostream>
using namespace std;

int main() {
    int size, value;
    cout << "Enter the number of elements: ";
    cin >> size;

    int* numbers = new int[size];
   
    for (int index = 0; index < size; index++) {
        cout << "Enter element " << index + 1 << ": ";
        cin >> numbers[index];
    }
    cout << "Enter the value you want to search for: ";
    cin >> value;

    bool isFound = false;
    for (int index = 0; index < size; index++) {
        if (numbers[index] == value) {
            cout << "Value " << value << " found at index " << index << "." << endl;
            isFound = true;
            return 0;
        }
    }

    if (!isFound) {
        cout << "Value " << value << " not found in the array." << endl;
    }

}
