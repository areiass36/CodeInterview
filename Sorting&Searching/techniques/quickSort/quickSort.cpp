#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low,int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int start, int end){
    if (start >= end){
        return;
    }
    
    int pivotIndex = partition(arr,start,end);
    quickSort(arr,start, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, end);
}

int main() {

    vector<int> arr{10,5,2,0,7,6,4};

    quickSort(arr,0,arr.size() - 1);

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}