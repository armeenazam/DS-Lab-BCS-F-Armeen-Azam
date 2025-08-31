#include<iostream>
using namespace std;

int main(){
    int rows, cols;
    cout <<"Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for(int i=0; i< rows; i++){
        matrix[i] = new int[cols];
    }   
    cout << "\nEnter the elements of the matrix: ";
    for(int i=0; i< rows ; i++){
        for (int j= 0; j< cols ; j++)
        {
            cin >> matrix[i][j];
        }
    }   
    cout << "\nNormal Matrix: \n";
    for(int i=0; i< rows ; i++){
        for (int j= 0; j< cols ; j++)
        {
            cout << matrix[i][j] << " ";
        }   
    }

     int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    int** sparse = new int*[nonZeroCount];
    for (int i = 0; i < nonZeroCount; i++) {
        sparse[i] = new int[3];  
    }

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;        
                sparse[k][1] = j;           
                sparse[k][2] = matrix[i][j]; 
                k++;
            }
        }
    }

    cout << "\nCompressed Matrix (row, col, value):\n";
    for (int i = 0; i < nonZeroCount; i++) {
        cout << sparse[i][0] << " "
             << sparse[i][1] << " "
             << sparse[i][2] << endl;
    }

    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < nonZeroCount; i++) delete[] sparse[i];
    delete[] sparse;

    return 0;
}