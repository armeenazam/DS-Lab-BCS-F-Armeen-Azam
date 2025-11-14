#include <iostream>
using namespace std;

int kthLargest(int arr[], int n, int k) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr[k - 1];
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter K: ";
    cin >> k;

    if (k > 0 && k <= n) {
        cout << "The " << k << "-th largest element is: " << kthLargest(arr, n, k) << endl;
    } else {
        cout << "Invalid value of K!" << endl;
    }

    delete[] arr;
    return 0;
}
