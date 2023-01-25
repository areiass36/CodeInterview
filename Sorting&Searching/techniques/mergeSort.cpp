#include <bits/stdc++.h>

using namespace std;

void _mergeSort(vector<int> &arr, int start,int end){
    int i = start;
    int mid = (start + end) / 2;
    int j = mid + 1;

    vector<int> temp;
    while(i <= mid and j <= end){
        if (arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    
    while(j <= end){
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for(int idx = start; idx <= end; idx++){
        arr[idx] = temp[k++];
    }
    return;
}

void mergeSort(vector<int> &arr, int start, int end){
    if (start >= end)
        return;

    int mid = (start+end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    return _mergeSort(arr,start,end);
}


int main() {

    vector<int> arr = {9,2,7,32,0,3,8,-1,-123,4,6,8,28,8};

    mergeSort(arr, 0, arr.size() - 1);

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}