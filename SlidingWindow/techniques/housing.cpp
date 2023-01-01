#include <bits/stdc++.h>

using namespace std;

//Course Solution
//O(n) - time
//O(1) - space
//obs: refactor int pointer arr to vector<int>
void housing(vector<int> arr, int k){
    int n = arr.size();

    int i = 0;
    int j = 0;
    int cs = 0;

    while (j < n){
        //expand to right
        cs += arr[j];
        j++;

        //remove elements from left, shrink to right
        while(cs > k and i < j){
            cs -= arr[i];
            i++;
        }

        //check if any given point
        if (cs == k){
            cout << i << " - " << j - 1 << endl;
        }
    }

    return;
}

//Ryan Solution
//O(n) - time
//O(1) - space 
vector<pair<int,int>> housing2(vector<int> arr, int k){
    int n = arr.size();

    int start = 0;
    int end = 0;

    vector<pair<int,int>> ans;

    int prefixSum = arr[0];
    while(end < n){
        if (prefixSum == k){
            ans.push_back({start,end});
            prefixSum -= arr[start];
            start++;
        } else if (prefixSum < k){
            end++;
            prefixSum += arr[end];
        } else if (prefixSum > k){
            prefixSum -= arr[start];
            start++;
        }
    }
    return ans;
}

int main() {
    vector<int> plots = {1,3,2,1,4,1,3,2,1,1,7}; //[2,5], [4,6], [5,9], [9, 10]
    int k = 8;

    housing(plots,k);

    /*
    auto output = housing2(plots,k);

    for(auto x : output){
        cout << x.first << " " << x.second << endl;
    }
    cout << endl; 
    */
    
    return 0;
}