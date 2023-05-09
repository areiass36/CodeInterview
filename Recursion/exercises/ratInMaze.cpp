#include <bits/stdc++.h>
using namespace std;

bool _findPath(int n, vector<vector<char>> grid, vector<int> &ans, int i = 0, int j = 0){
    int num = i*n + j + 1;
    ans.push_back(num);
    if (i >= n or j >= n){
        ans.pop_back();
        return false;
    }

    if (i*j == (n-1)*(n-1)){
        return true;
    }

    if (grid[i][j] == 'X'){
        ans.pop_back();
        return false;
    }
    
    bool r = _findPath(n,grid,ans,i,j+1);
    bool d = _findPath(n,grid,ans,i+1,j);

    //This is necessary cause we are pushing the number before checking if it 
    //is valid path (When is X or out of bound we already pop it)
    //so we need to pop it back if it is not valid
    if (r or d){
        return true;
    }else{
        ans.pop_back();
        return false;
    }
}

vector<int> findPath(int n, vector<vector<char>> c){
    vector<int> ans;
    _findPath(n,c,ans);
    return ans;
}

int main() {
    vector<vector<char>> grid = {
        {'O','O','X','O'},
        {'O','X','O','O'},
        {'O','O','O','X'},
        {'X','X','O','O'}
    };
    vector<int> path = findPath(4,grid);
    for(auto i : path){
        cout << i << " ";
    }

    return 0;
}