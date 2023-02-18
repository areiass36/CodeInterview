#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);

    return i + 1;
}

//Ryan's Note:  I think that using QuickSort With Binary Search is badass
int _quickSelect(vector<int> &arr, int low, int high, int k){
    int pivotIndex = partition(arr,low,high);
    
    if (pivotIndex == k){
        return arr[pivotIndex];
    } else if (pivotIndex > k){
        _quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        _quickSelect(arr, pivotIndex + 1, high, k);
    }
}

//O(N) - Time (O(n²) in worstCase) 
//O(1) - Space
int quickSelect(vector<int> &arr, int k){
    return _quickSelect(arr, 0, arr.size() - 1, k);
}

int main() {

    vector<int> arr = {10,5,2,0,7,6,4};
    int k = 4;

    cin >> k;

    cout << quickSelect(arr,k) << endl;

    return 0;
}