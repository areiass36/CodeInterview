#include <bits/stdc++.h>
using namespace std;

int findLongestPathRec(vector<vector<int>>& maze, vector<vector<bool>> mazeVisitedCells, int res = 0, int currentRes = 0, int row = 0, int col = 0) {
    if(row == maze.size() - 1 && col == maze[0].size() - 1)
        return max(res, currentRes);
    
    if(row == maze.size() || col == maze[0].size() || row < 0 || col < 0)
        return res;
        
    if(mazeVisitedCells[row][col] || !maze[row][col])
        return res;
        
    mazeVisitedCells[row][col] = true;
    
    res = findLongestPathRec(maze, mazeVisitedCells, res, currentRes + 1, row + 1, col);
    res = findLongestPathRec(maze, mazeVisitedCells, res, currentRes + 1, row - 1, col);
    res = findLongestPathRec(maze, mazeVisitedCells, res, currentRes + 1, row, col + 1);
    res = findLongestPathRec(maze, mazeVisitedCells, res, currentRes + 1, row, col - 1);
    
    mazeVisitedCells[row][col] = false;
    
    return res;
}

int findLongestPath(int m, int n, vector<vector<int>> v) {
    vector<vector<bool>> mazeVisitedCells(v.size(), vector<bool>(v[0].size(), false));
    int res = findLongestPathRec(v, mazeVisitedCells);
    
    return res;
}

int main() {
    vector<vector<int>> grid = {{1,1,1},{1,1,1},{0,0,1}};

    cout << findLongestPath(3,3,grid) << endl;
    return 0;
}