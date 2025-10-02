//N-Queens
#include<iostream>
using namespace std;

bool isSafe(char **board, int row, int col, int n){
    // horizontal
    for (int j=0 ; j < n ;j++){
        if (board[row][j] == 'Q'){
            return false;
        }
    }

    // vertical
    for (int i=0 ; i < n ;i++){
        if (board[i][col] == 'Q'){
            return false;
        }
    }

    // left diagonal 
    for (int i=row, j=col; i>=0 && j>=0 ; i--, j--){
        if (board[i][j] == 'Q'){
            return false;
        }
    }

    // right diagonal
    for (int i=row, j=col; i>=0 && j<n ; i--, j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

bool NQueens(char **board, int row, int n){
    if (row ==n ) return true;
    
    for (int j=0; j <n ;  j++){
        if(isSafe(board, row, j, n)){
            board[row][j] = 'Q';
            if (NQueens(board, row+1, n)){
                return true;
            }
            board[row][j] = 'X'; //backtracking will start from this point

        }
    }
    return false;
}

char** solveNQueens(int n){
    char** board = new char*[n];
    for (int i=0; i<n ; i++){
        board[i] = new char[n];
        for (int j=0; j< n ; j++){
            board[i][j] = 'X';
        }
    } 
    NQueens(board, 0, n);
    return board;

}

int main(){
    int n;
    cout <<"Enter the value of n: ";
    cin >> n;
    
    char **answer = solveNQueens(n);
    for (int i=0; i< n ; i++){  
        for (int j=0 ; j<n ; j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i< n ; i++){
        delete [] answer[i];
    }
    delete[] answer;

}

