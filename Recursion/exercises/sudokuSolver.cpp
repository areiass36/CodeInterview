#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/sudoku-solver/

bool _solveSudoku(vector<vector<int>> &input){
    auto isSafe = [&](int num, int i, int j) -> bool {
       //check row and column 
        for(int k = 0; k < 9; k++){
            if (input[k][j] == num or input[i][k] == num)
                return false;
        }
        
        //check subgrid
        int row = i - i % 3;
        int col = j - j % 3;
        
        for(int srow = row; srow < row + 3; srow++){
            for(int scol = col; scol < col + 3; scol++){
                if (input[srow][scol] == num)
                    return false;
            }
        }
        return true;
    };
    
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < input[0].size(); j++){
            if (input[i][j] == 0){
                for(int num = 1; num <= 9; num++){
                    if (isSafe(num,i,j)){
                        input[i][j] = num;
                        if (_solveSudoku(input)){
                            return true;
                        }
                        input[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solveSudoku(vector<vector<int>> &input){
    _solveSudoku(input);
    return input;
}

int main(){
    vector<vector<int>> board = {{5,3,0,0,7,0,0,0,0},
                                  {6,0,0,1,9,5,0,0,0},
                                  {0,9,8,0,0,0,0,6,0},
                                  {8,0,0,0,6,0,0,0,3},
                                  {4,0,0,8,0,3,0,0,1},
                                  {7,0,0,0,2,0,0,0,6},
                                  {0,6,0,0,0,0,2,8,0},
                                  {0,0,0,4,1,9,0,0,5},
                                  {0,0,0,0,8,0,0,7,9}};

    auto newBoard = solveSudoku(board);

    for(auto row : newBoard){
        for(auto col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}