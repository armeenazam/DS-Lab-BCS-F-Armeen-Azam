#include <iostream>
using namespace std;

int main() {
    int* arr;
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    arr = new int[size]; 

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    cout << "Initial array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int choice;
    do {
        int index, value;
        cout << "Enter the index you want to change and the new value: ";
        cin >> index >> value;

        if (index >= 0 && index < size) {
            arr[index] = value;
        } else {
            cout << "Invalid index!" << endl;
        }

        cout << "Updated array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Enter 1 if you want to update another element, 0 to exit: ";
        cin >> choice;

    } while (choice == 1);

    delete[] arr; 
    return 0;
}
