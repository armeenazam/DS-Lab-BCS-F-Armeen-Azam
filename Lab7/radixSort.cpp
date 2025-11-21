#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    int output[100], count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSortAscending(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void radixSortDescending(int arr[], int n) {
    radixSortAscending(arr, n);
    for (int i = 0; i < n / 2; i++)
        swap(arr[i], arr[n - 1 - i]);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSortAscending(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSortDescending(arr2, n);
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";

    return 0;
}
