#include <iostream>
using namespace std;

int searchInterpolation(int data[], int size, int value) {
    int start = 0, end = size - 1;
    while (start <= end && value >= data[start] && value <= data[end]) {
        if (data[start] == data[end]) {
            return (data[start] == value) ? start : -1;
        }
        int pos = start + ((value - data[start]) * (end - start)) / (data[end] - data[start]);
        if (data[pos] == value) {
            return pos;
        } else if (data[pos] < value) {
            start = pos + 1;
        } else {
            end = pos - 1;
        }
    }
    return -1;
}

bool checkUniform(int data[], int size) {
    int step = data[1] - data[0];
    for (int k = 2; k < size; k++) {
        if (data[k] - data[k - 1] != step) {
            return false;
        }
    }
    return true;
}

void sortBubble(int data[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int j = 0; j < size - pass - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    int total, searchVal;
    cout << "Enter how many balances you want to input: ";
    cin >> total;

    int balances[100];
    cout << "Enter the balances: ";
    for (int i = 0; i < total; i++) {
        cin >> balances[i];
    }

    sortBubble(balances, total);

    if (!checkUniform(balances, total)) {
        cout << "Error: Balances are not uniformly spaced." << endl;
        return 0;
    }

    cout << "Enter balance to look for: ";
    cin >> searchVal;

    int location = searchInterpolation(balances, total, searchVal);

    if (location != -1) {
        cout << "Balance " << searchVal << " found at position " << location << "." << endl;
    } else {
        cout << "Balance " << searchVal << " not found in the list." << endl;
    }

    return 0;
}
