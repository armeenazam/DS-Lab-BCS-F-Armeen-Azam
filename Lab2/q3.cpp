#include <iostream>
using namespace std;

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    int* numCourses = new int[numStudents];

    int** marks = new int*[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the number of courses taken by student " << i + 1 << ": ";
        cin >> numCourses[i];

        marks[i] = new int[numCourses[i]];

        cout << "Enter marks for " << numCourses[i] << " courses: ";
        for (int j = 0; j < numCourses[i]; j++) {
            cin >> marks[i][j];
        }
    }

    cout << "\nStudent Averages:\n";
    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < numCourses[i]; j++) {
            sum += marks[i][j];
        }
        double avg = (double)sum / numCourses[i];
        cout << "Student " << i + 1 << " average = " << avg << endl;
    }

    
    for (int i = 0; i < numStudents; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] numCourses;

    return 0;
}
