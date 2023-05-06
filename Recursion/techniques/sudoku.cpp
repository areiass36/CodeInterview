#include <bits/stdc++.h>

using namespace std;

void printMatrix(int n, int board[][9]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int mat[][9], int i, int j, int num, int n){
    // check for row and column
    for(int x=0; x<n; x++){
        if(mat[x][j] == num || mat[i][x] == num){
            return false;
        }
    }

    //check for subgrid
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x=sx; x<sx+rn; x++){
        for(int y=sy; y<sy+rn; y++){
            if(mat[x][y] == num){
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
    //base case
    if (i == n){
        printMatrix(n,mat);
        return true;
    }

    //if we reach the end of the row, go to the next row
    if (j == n) return solveSudoku(mat, i+1, 0, n);

    //if the cell is not empty, go to the next cell
    if (mat[i][j] != 0) return solveSudoku(mat, i, j+1, n);

    //recursive case - fill the current cell with possible options
    for(int num=1; num <= n; num++){
        //check if is safe place number
        if (isSafe(mat,i,j,num,n)){
            mat[i][j] = num;
            bool solveSubproblem = solveSudoku(mat,i,j+1,n);
            if(solveSubproblem){
                return true;
            }

        }
    }
    //if no option works, then backtrack
    mat[i][j] = 0;
    return false;
}

int main() {

    int n = 9;
    int mat[9][9] = 
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

        if(!solveSudoku(mat, 0, 0, n)){
            cout << "Solution doesn't exist" << endl;
        }

    return 0;
}