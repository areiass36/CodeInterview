#include <bits/stdc++.h>

using namespace std;

bool isPossibleDivideK(vector<int> arr, int k, int minCoin){
    int partition = 0;
    int currentFriend = 0;

    for(int num : arr){
        currentFriend += num;
        if (currentFriend >= minCoin){
            partition++;
            currentFriend = 0;
        }
    }

    /* for(int num : arr){
        if(current_sum + num >= minCoin){
            partition +=1;
            currentFriend = 0;
        }
        else {
            currentFriend += num;
        }
    } */ 

    return partition >= k;
}

int maximumSubarraySumIntoKSubsets(vector<int> arr, int k){
    int start = 0;
    int end = 0;
    
    for(int num : arr){
        end += num;
    }

    int ans;
    while (start <= end){
        int mid = (start+end)/2;

        if (isPossibleDivideK(arr, k, mid)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main() {

    vector<int> arr = {1,2,3,4};

    int k = 3;

    cin >> k;

    cout << maximumSubarraySumIntoKSubsets(arr,k) << endl;

    return 0;
}