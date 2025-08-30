#include<iostream>
using namespace std;

int * resizeArray(int* oldArray, int oldSize, int newSize) {
    if (oldSize == newSize) {return oldArray;}
    int* newArray = new int[newSize];

    int limit = (oldSize < newSize) ? oldSize : newSize;
    for (int i = 0; i < limit; i++) {
        newArray[i] = oldArray[i];
    }

    delete [] oldArray;
    return newArray;
}


int main()
{
    int months;
    cout << "Enter number of months: ";
    cin >> months;

    int* array = new int [months];

    cout << "Enter the monthly expenses: ";
    for (int i =0; i< months; i++){
        cin >> array[i];
    }

    cout << "Do you want to resize the array? (1 for yes, 0 for no): ";
    int choice;
    cin >> choice;

    int size = months;
    if (choice == 1){
        int newSize;
        cout << "Enter new size: ";
        cin >> newSize; 
        array = resizeArray(array, months, newSize);

        if(newSize > months){
            cout << "Enter the new monthly expenses: ";
            for(int i=months; i< newSize; i++){
                cin >> array[i];
            }
        }
        size = newSize;
    }
    cout << "\nMonthly expenses: ";
    for(int i=0; i< size; i++){
        cout << array[i] << " ";
    }

    int total = 0;
    for(int i=0; i< size; i++){
        total+=array[i];
    }
    cout << "\nTotal expenses: " << total << endl;

    double avg = (double) total/months;
    cout << "Average monthly expense: " << avg << endl;

    delete[] array;
}

