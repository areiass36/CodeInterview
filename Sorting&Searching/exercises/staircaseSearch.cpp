#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/search-a-2d-matrix-ii

//GeeksForGeeks Solution: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

//O(n) - Time
//O(1) - space
pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    //write your code here.
    
    int start = 0;
    int end = v[0].size() - 1;
    
    while (start < v.size() and end >= 0){
        if (v[start][end] == k){
            return {start,end};
        } else if (v[start][end] > k){
            end--;
        } else{
            start++;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> matrix = {{1,4,9},{2,5,10},{6,7,11}};

    auto pairAns = search(3,3,matrix, 10);

    cout << pairAns.first << "," << pairAns.second << endl;
}