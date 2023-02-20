#include<bits/stdc++.h>

using namespace std;

//https://leetcode.com/problems/sort-colors/

//must read: http://users.monash.edu/~lloyd/tildeAlgDS/Sort/Flag/
void dnfSort(vector<int> &arr){
    int lo = 0;
    int mid = 0;
    int high = arr.size() - 1;
    
    while(mid <= high){
        if (arr[mid] == 0){
            swap(arr[mid],arr[lo]);
            lo++;
            mid++;
        }else if (arr[mid] == 1){
            mid++;
        }else if (arr[mid] == 2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return;
}

//O(n) - Time
//O(1) - Space
vector<int> sortBalls(vector<int> &balls){
    //sort the balls in place in a single pass (O(N) time, O(1) space)
    dnfSort(balls);
    
    return balls;
}

int main(){
    vector<int> arr = {0, 0, 1, 2, 0, 1, 2, 0};

    sortBalls(arr);

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
}