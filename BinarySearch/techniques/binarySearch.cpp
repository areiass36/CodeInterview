#include <bits/stdc++.h>

using namespace std;

int iterativeBinarySearch(vector<int> arr, int target){
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end){
        int mid = (start+end)/2;

        if (arr[mid] == target){
            return mid;
        }else if (arr[mid] > target){
            end = mid - 1;
        }else if (arr[mid] < target){
            start = mid + 1;
        }
    }

    return -1;
}

int _recursiveBinarySearch(vector<int> arr, int target,int low,int high){
    if (low > high){
        return -1;
    }

    int mid = (low+high)/2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target){
        return _recursiveBinarySearch(arr,target,low,mid-1);
    }else if (arr[mid] < target){
        return _recursiveBinarySearch(arr,target,mid+1,high);
    }

    return -1;
}

int recursiveBinarySearch(vector<int> arr, int target){
    return _recursiveBinarySearch(arr,target,0, arr.size() - 1);
}

int main() {

    vector<int> arr = {1,2,10,11,19,29,28};

    cout << iterativeBinarySearch(arr,19) << endl;
    cout << recursiveBinarySearch(arr,19) << endl;


    return 0;
}