#include <iostream>
using namespace std;

int main() {
    int benches, seats;
    cout << "Enter the number of benches and seats on each bench: ";
    cin >> benches >> seats;

    int **seating = new int*[benches];
    for (int i = 0; i < benches; i++) {
        seating[i] = new int[seats];
    }

    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
            seating[i][j] = 0;
        }
    }

    cout << "\nInitial Seating Chart:\n";
    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
            cout << seating[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nEnter seat values (1 for occupied, 0 for empty):\n";
    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
            int value;
            cin >> value;
            if (value == 0 || value == 1)
                seating[i][j] = value;
            else {
                cout << "Invalid input!\n";
                seating[i][j] = 0;
            }
        }
    }

    cout << "\nFinal Seating Chart:\n";
    for (int i = 0; i < benches; i++) {
        for (int j = 0; j < seats; j++) {
            cout << seating[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < benches; i++) {
        delete[] seating[i];
    }
    delete[] seating;

    return 0;
}
