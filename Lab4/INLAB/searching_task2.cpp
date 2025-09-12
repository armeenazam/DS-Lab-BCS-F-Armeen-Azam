#include <iostream>
using namespace std;

int binarySearch(int ids[], int left, int right, int target) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (ids[mid] == target) return mid;
        else if (ids[mid] < target)
            return binarySearch(ids, mid + 1, right, target);
        else
            return binarySearch(ids, left, mid - 1, target);
    }
    return -1;
}
int main() {
    int count, rollNumber = 0654;
    cout << "Enter the number of employee IDs: ";
    cin >> count;

    int* empIDs = new int[count];
    cout << "Enter employee IDs in sorted order: ";
    for (int i = 0; i < count; i++) {
        cin >> empIDs[i];
    }

    int searchID = rollNumber % 100;
    int foundIndex = binarySearch(empIDs, 0, count - 1, searchID);

    if (foundIndex != -1) {
        cout << "Employee ID " << searchID
             << " exists at position " << foundIndex << "." << endl;
    } else {
        int* updatedIDs = new int[count + 1];
        int insertPos = 0;

        while (insertPos < count && empIDs[insertPos] < searchID) {
            updatedIDs[insertPos] = empIDs[insertPos];
            insertPos++;
        }

        updatedIDs[insertPos] = searchID;

        for (int i = insertPos; i < count; i++) {
            updatedIDs[i + 1] = empIDs[i];
        }

        count++;

        cout << "Employee ID " << searchID
             << " not found. Inserted at position " << insertPos << "." << endl;

        cout << "Updated employee list: ";
        for (int i = 0; i < count; i++) {
            cout << updatedIDs[i] << " ";
        }
        cout << endl;

        delete[] empIDs;
        empIDs = updatedIDs;
    }
}

