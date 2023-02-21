#include <bits/stdc++.h>

using namespace std;

//O(log n) - Time
//O(1)
int rotatedSearch(vector<int> arr, int target){
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end){
        int mid = (start+end)/2;

        int firstValue = arr[start];
        int lastValue = arr[end];

        if (arr[mid] == target){
            return mid;
        }
        
        //2 Cases

        //left part is sorted
        if(firstValue < arr[mid]){
            //target is between interval
            if (firstValue <= target and target <= arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        } else{
            //target is between right part interval
            if (arr[mid] <= target and target <= lastValue){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    //                 0 1 2 3 4 5 6 7
    vector<int> arr = {4,5,6,7,0,1,2,3};

    cout << rotatedSearch(arr, 0) << endl;

    return 0;
}