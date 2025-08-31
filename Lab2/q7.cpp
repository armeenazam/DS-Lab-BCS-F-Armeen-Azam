#include <iostream>
#include <string>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

 
    string* deptNames = new string[departments];

    double** salaries = new double*[departments];
    int* empCount = new int[departments];

    for (int i = 0; i < departments; i++) {
        cout << "\nEnter name of department " << i+1 << ": ";
        cin >> deptNames[i];

        cout << "Enter number of employees in " << deptNames[i] << ": ";
        cin >> empCount[i];

        salaries[i] = new double[empCount[i]];

        cout << "Enter salaries of employees in " << deptNames[i] << ": ";
        for (int j = 0; j < empCount[i]; j++) {
            cin >> salaries[i][j];
        }
    }

    cout << "\n--- Department Salary Analysis ---\n";
    for (int i = 0; i < departments; i++) {
        double highest = salaries[i][0];
        for (int j = 1; j < empCount[i]; j++) {
            if (salaries[i][j] > highest) {
                highest = salaries[i][j];
            }
        }
        cout << "Highest salary in " << deptNames[i] << " = " << highest << endl;
    }

    double maxAvg = -1;
    int deptIndex = -1;

    for (int i = 0; i < departments; i++) {
        double sum = 0;
        for (int j = 0; j < empCount[i]; j++) {
            sum += salaries[i][j];
        }
        double avg = sum / empCount[i];

        if (avg > maxAvg) {
            maxAvg = avg;
            deptIndex = i;
        }
    }

    cout << "\nDepartment with maximum average salary: " 
         << deptNames[deptIndex] 
         << " (Average = " << maxAvg << ")" << endl;

    // Free memory
    for (int i = 0; i < departments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] empCount;
    delete[] deptNames;

    return 0;
}
