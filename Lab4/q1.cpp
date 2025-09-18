#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) if (arr[i] == target) return i;
    return -1;
}
int main() {
    int n, target;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> target;
    int index = linearSearch(arr, n, target);
    if (index != -1) cout << index;
    else cout << "Not found";
}
