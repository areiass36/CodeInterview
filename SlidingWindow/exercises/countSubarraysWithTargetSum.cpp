#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/subarray-sum-equals-k


//Neetcode Solution - https://youtu.be/fFVZt-6sgyo
//O(n) - time
//O(n) - space
int cntSubarrays(vector<int> arr,int k){
    
    unordered_map<int,int> prefixSums = {{0,1}};
    
    int ans = 0;
    int currSum = 0;
    
    for(int num : arr){
        currSum += num;
        int diff = currSum - k;
        
        
        ans += prefixSums[diff]; //add 0 if not found
        prefixSums[currSum] += 1; //just add 1 if not found
    }
    
    return ans;
}

int main() {
    vector<int> arr1 = {10, 2, -2, -20, 10};
    vector<int> arr2 = {1,2,3};

    cout << cntSubarrays(arr1, -10) << endl; //3
    cout << cntSubarrays(arr2, 3) << endl; //2
}