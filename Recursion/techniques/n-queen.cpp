#include <bits/stdc++.h>

using namespace std;

void printBoard(int n, int board[][20]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool canPlace(int board[][20], int n, int x, int y){
    // Check column
    for(int k = x; k >= 0; k--){
        if (board[k][y] == 1){
            return false;
        }
    }

    // Check left diagonal
    int i = x;
    int j = y;
    while (i>=0 and j>=0){
        if (board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }

    // Check right diagonal 
    i = x;
    j = y;
    while (i>=0 and j<n){
        if (board[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}


//Time complexity - O(n!)
//Space complexity - O(n^2) (cause of the board)
bool solveNQueen(int n, int board[][20], int i = 0){
    if (i == n){
        //print board
        printBoard(n, board);
        return true;
    }

    //rec case
    //try to place a queen in every column in the current row
    for(int j = 0; j < n; j++){
        if (canPlace(board,n,i,j)){
            board[i][j] = 1;
            bool success = solveNQueen(n,board,i+1);
            if (success){
                return true;
            }
            //backtracking
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {

    int board[20][20] = {0};
    int n;
    cin >> n;

    solveNQueen(n,board);

    return 0;
}