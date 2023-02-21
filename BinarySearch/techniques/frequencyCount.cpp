#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int target){
    int start = 0;
    int end = arr.size() - 1;
    
    int ans = -1;

    while (start <= end){
        int mid = (start+end)/2;

        if (arr[mid] == target){
            ans = mid;
            end = mid - 1;
        }else if (arr[mid] > target){
            end = mid - 1;
        }else {
            start = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> arr, int target){
    int start = 0;
    int end = arr.size() - 1;
    
    int ans = -1;

    while (start <= end){
        int mid = (start+end)/2;

        if (arr[mid] == target){
            ans = mid;
            start = mid + 1;
        }else if (arr[mid] > target){
            end = mid - 1;
        }else {
            start = mid + 1;
        }
    }
    return ans;
}

//O(log n)
//O(1) - Because B.S is iterative
int frequencyCount(vector<int> arr, int target){
    int lower = lowerBound(arr,target);
    int upper = upperBound(arr,target);

    return upper - lower + 1;
}

int main() {
    //                 0 1 2 3 4 5 6 7 8 9 1 2 3 
    vector<int> arr = {0,1,1,2,3,3,3,3,4,5,5,5,10};

    cout << frequencyCount(arr,5) << endl;

    //STL - C++ have a native upper_bound and Lower_bound function ans solve in one line of code
    cout << upper_bound(arr.begin(),arr.end(), 5) -  lower_bound(arr.begin(),arr.end(), 5) << endl;

    return 0;
}