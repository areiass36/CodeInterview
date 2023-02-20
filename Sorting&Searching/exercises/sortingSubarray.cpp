#include<bits/stdc++.h>
using namespace std;

//Little different on Leetcode
//The subarraySort pattern seen in the ArrayAndVectors section

bool isNotOrdered(vector<int> arr, int index){
    int currentNum = arr[index];
    if (index == 0){
        return currentNum > arr[index+1];
    } else if (index == arr.size() - 1){
        return currentNum < arr[index-1];
    }

    return currentNum > arr[index+1] or currentNum < arr[index-1];
}

pair<int,int> subarraySorting(vector<int> arr){
    //Expected Optimal Complexity O(n) Time, O(1) Space
    //may be start with O(NLogN) and try to improve
    //complete this function
    
    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        if (isNotOrdered(arr,i)){
            minValue = min(arr[i],minValue);
            maxValue = max(arr[i],maxValue);
        }
    }

    if (minValue == INT_MAX or maxValue == INT_MIN){
        return {-1,-1};
    }

    int left = 0;
    while(minValue >= arr[left]){
        left++;
    }

    int right = arr.size() - 1;
    while(maxValue <= arr[right]){
        right--;
    }

    return {left,right};
}

int main(){
    vector<int> arr = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};

    auto ans = subarraySorting(arr);

    cout << ans.first << " " << ans.second << endl;
}