#include <bits/stdc++.h>

using namespace std;

// If the num is out of order, we need to find the correct position for it
bool outOfOrder(vector<int> arr, int index){
    int num = arr[index];

    if (index == 0) 
        return num > arr[1];
    if (index == arr.size() - 1)
        return num < arr[index - 1];
    
    return num > arr[index + 1] or num < arr[index - 1];
}

//O(n) - time
//O(1) - space
pair<int, int> subarraySort(vector<int> arr){
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        
        if (outOfOrder(arr, i)){
            smallest = min(smallest, arr[i]);
            largest = max(largest, arr[i]);
        }
    }

    //find the right index where smallest and largest lie (subarray) for out solution
    if (smallest == INT_MAX or largest == INT_MIN){
        return {-1, -1};
    }

    int left = 0;
    while (smallest >= arr[left]){
        left++;
    }

    int right = arr.size() - 1;
    while (largest <= arr[right]){
        right--;
    }

    return {left, right};
}

int main() {
    vector<int> arr = {1,2,3,4,5,8,6,7,9,10,11};
    auto p = subarraySort(arr);
    cout << p.first << " " << p.second << endl; // 5 7

    return 0;
}