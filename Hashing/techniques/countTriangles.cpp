#include<bits/stdc++.h>

using namespace std;

// Time - O(n)
// Space - O(n)
int count_triangles(vector<pair<int,int>> points){
    unordered_map<int,int> freqX;
    unordered_map<int,int> freqY;

    for(auto [x,y] : points){
        freqX[x]++;
        freqY[y]++;
    }

    int count = 0;
    for(auto [x,y] : points){
        int fx = freqX[x];
        int fy = freqX[y];

        if (fx >= 1 and fy >= 1){
            count += (fx-1)*(fy-1);
        }   
    }

    return count;
}


int main(){
    vector<pair<int,int>> points = {
        {1,2},
        {2,0},
        {2,2},
        {2,3},
        {4,2}
    };

    cout << count_triangles(points) << endl;
}