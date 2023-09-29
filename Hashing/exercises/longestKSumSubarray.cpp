#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/longest-sub-array-sum-k/

// Time - O(n)
// Space - O(n)
int longestSubarrayKSum(vector<int> arr,int k){
    unordered_map<int,int> mp;
    int sum = 0;
    int maxLen = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        // if sum-k is present in map then update maxLen
        if(mp.find(sum-k) != mp.end()){
            maxLen = max(maxLen,i-mp[sum-k]);
        }
        // if sum is not present in map then only insert it saving its index
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr = {0,-2,1,2,3,4,5,15,10,5};

    cout << longestSubarrayKSum(arr, 15) << endl;
}