#include <iostream>
using namespace std;

void findPairs(int arr[], int n) {
    int sums[1000];
    int firstA[1000];
    int firstB[1000];
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int s = arr[i] + arr[j];

            for(int k = 0; k < count; k++) {
                if(sums[k] == s &&
                   firstA[k] != arr[i] && firstB[k] != arr[i] &&
                   firstA[k] != arr[j] && firstB[k] != arr[j]) {

                    cout << "(" << firstA[k] << ", " << firstB[k] << ") and ("
                         << arr[i] << ", " << arr[j] << ")";
                    return;
                }
            }

            sums[count] = s;
            firstA[count] = arr[i];
            firstB[count] = arr[j];
            count++;
        }
    }

    cout << "No pairs found";
}
