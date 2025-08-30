#include<iostream>
using namespace std;

int main(){
    int rows1, cols1, rows2, cols2;
    cout <<"Enter the number of rows and columns of matrix1: ";
    cin >> rows1 >> cols1;
    cout << "Enter the number of rows and columns of matrix2: ";
    cin >> rows2 >> cols2;

    if (rows1 != rows2 || cols1 != cols2){
        cout << "Error: Matrices must have the same dimensions for addition or subtraction." << endl;
        return 1;
    }

    int** matrix1 = new int*[rows1];
    for(int i=0; i< rows1; i++){
        matrix1[i] = new int[cols1];
    }

    int** matrix2 = new int*[rows2];
    for(int i=0; i< rows2; i++){
        matrix2[i] = new int[cols2];
    }

    cout << "\nEnter the elements of matrix1: ";
    for(int i=0; i< rows1 ; i++){
        for (int j= 0; j< cols1 ; j++)
        {
            cin >> matrix1[i][j];
        }
    }
      cout << "\nEnter the elements of matrix2: ";
    for(int i=0; i< rows2 ; i++){
        for (int j= 0; j< cols2 ; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    cout << "\nMatrix1: \n";
    for(int i=0; i< rows1 ; i++){
        for (int j= 0; j< cols1 ; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMatrix2: \n";
    for(int i=0; i< rows2 ; i++){
        for (int j= 0; j< cols2 ; j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    int** sumMatrix = new int*[rows1];
    for(int i=0; i< rows1; i++){
        sumMatrix[i] = new int[cols1];
    }

    for(int i = 0; i < rows1; i++) {
        for (int j=0 ; j< cols1; j++){
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "\nSum of Matrix1 and Matrix2: \n";
    for(int i=0; i< rows1 ; i++){
        for (int j= 0; j< cols1 ; j++)
        {
            cout << sumMatrix[i][j] << " ";
        }
        cout << endl;
    }

    int** diffMatrix = new int*[rows1];
    for(int i=0; i< rows1; i++){{
        diffMatrix[i] = new int[cols1];
    }

    for(int i = 0; i < rows1; i++) {
        for (int j=0 ; j< cols1; j++){
            diffMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    cout << "\nDifference of Matrix1 and Matrix2: \n";
    for(int i=0; i< rows1 ; i++){
        for (int j= 0; j< cols1 ; j++)
        {
            cout << diffMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = rows1; i>0 ; i++){
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] sumMatrix[i];
        delete[] diffMatrix[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] sumMatrix;
    delete[] diffMatrix;


return 0;
}}