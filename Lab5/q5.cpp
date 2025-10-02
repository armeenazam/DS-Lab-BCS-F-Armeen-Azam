//sudokuSolver
#include<iostream>
using namespace std;

bool isSafe(char** board, int row,int col, char dig,  int n){
    // horizontal 
    for (int j=0; j<n ; j++){
        if (board[row][j] == dig ){
            return false;
        }
    }

    //vertical
    for (int i=0; i< n ;i++){
        if (board[i][col] == dig){
            return false;
        }
    }

    //grid 3*3
    int StartRow = (row/3) * 3;
    int StartCol = (col/3) * 3;   
    
    for (int i=0; i<3 ; i++){
        for (int j=0; j<3 ; j++){
            if (board[i + StartRow][j + StartCol] == dig){
                return false;
            }
        }
    }
}

bool sudokuSolver(char ** board, int row, int col, int n){
    if (row == n) return true;

    if (col == n) return sudokuSolver(board, row+1, 0, n);

    if (board[row][col] != '.'){
        return sudokuSolver(board, row, col+1, n);
    }

    for (char dig = '1' ;  dig <= '9'; dig++){
        if (isSafe(board, row, col, dig, n)){
            board[row][col] = dig;
            if (sudokuSolver(board, row, col+1, n)){
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;

}

char** solveSudoku(int n){
    char** board= new char* [n];
    for (int i=0; i<n ; i++){
        board[i] = new char[n];
        for (int j=0; j<n ; j++){
            board[i][j] = '.';
        }
    }
    sudokuSolver(board, 0,0, n);
    return board;
}
int main(){
    int n = 9;
    char** ans = solveSudoku(n);
    for (int i=0; i<n ; i++){
        for (int j=0; j<n ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

