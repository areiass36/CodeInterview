#include <bits/stdc++.h>

using namespace std;

//O(n) - time
//O(1) - space
int highest_mountain(vector<int> arr){
    int n = arr.size();

    int largest = 0;

    int i = 1;
    while(i <= n-2){
        //check arr[i] is peak or not
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            //arr[i] is peak
            //expand to left and right
            int cnt = 1;
            int j = i;
            //expand to left
            while(j >= 1 && arr[j] > arr[j-1]){
                j--;
                cnt++;
            }
            //expand to right
            while(i <= n-2 && arr[i] > arr[i+1]){
                i++;
                cnt++;
            }
            largest = max(largest, cnt);
        }
        else{
            i++;
        }
    }
    return largest;
}

int main() {
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    cout << highest_mountain(arr) << endl; // 9

    return 0;
}