#include <bits/stdc++.h>
using namespace std;

//Little different on Leetcode
//https://leetcode.com/problems/n-queens/

bool solveNQueen(vector<vector<int>> &board, int &way, int row = 0){
    auto isSafe = [&](int x,int y) -> bool {
        //check column - Just Up cause we didn't put queens below yet
        for(int k = x; k >= 0; k--){
            if (board[k][y] == 1)
                return false;
        }
        //Check leftDiagonal;
        int i = x;
        int j = y;
        while(i>= 0 and j>=0){
            if (board[i][j] == 1)
                return false;
            i--;j--;
        }
        
        //Check rightDiagonal;
        i = x;
        j = y;
        while(i >= 0 and j < board.size()){
            if (board[i][j] == 1)
                return false;
            i--;j++;
        }
        return true;
    };
    if (row == board.size()){
        return true;
    }
    for(int column = 0; column < board[0].size(); column++){
        if (isSafe(row,column)){
            board[row][column] = 1;
            if (solveNQueen(board,way,row+1))
                way++;
            board[row][column] = 0;
        }
    }
    return false;
}

int nQueen(int n){
    int way = 0;
    vector<vector<int>> board(n,vector<int>(n,0));
    solveNQueen(board,way);
    return way;
} 

int main(){
    cout << nQueen(2) << endl;
    return 0;
}