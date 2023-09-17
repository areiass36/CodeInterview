#include <bits/stdc++.h>

using namespace std;

//Little different on Leetcode
//https://leetcode.com/problems/merge-k-sorted-lists/

// Time - O(nk log k)
// Space - O(k)
vector<int> mergeKArrays(vector<vector<int>> arrays){
    int k = arrays.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    for(int i = 0; i < k; i++){
        minHeap.push({arrays[i][0], i,1});
    }

    vector<int> ans;
    while(not minHeap.empty()){
        int num = minHeap.top()[0];
        int kArray = minHeap.top()[1];
        int nextNum = minHeap.top()[2];

        minHeap.pop();

        ans.push_back(num);
        
        if (arrays[kArray].size() > nextNum){
            minHeap.push({arrays[kArray][nextNum],kArray,nextNum+1});
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arrays = {
        {10,15,20,30},
        {2,5,8,14,24},
        {0,11,60,90}
    };
    auto ans = mergeKArrays(arrays);

    for(int num : ans){
        cout << num << " ";
    }
}