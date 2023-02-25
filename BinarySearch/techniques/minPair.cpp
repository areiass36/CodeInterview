#include <bits/stdc++.h>

using namespace std;

//O(n log n) - time
//O(1) - Space
pair<int,int> minPair(vector<int> arr1, vector<int> arr2){
    pair<int,int> ans;

    sort(arr2.begin(),arr2.end());

    int minDiffPair = INT_MAX;
    for(int num : arr1){
        auto minNumPosition = lower_bound(arr2.begin(),arr2.end(), num) - arr2.begin();
        
        //left
        if (minNumPosition >= 1){
            int diff = abs(num - arr2[minNumPosition-1]);

            if (diff < minDiffPair){
                minDiffPair = diff;
                ans = make_pair(arr2[minNumPosition-1], num);
            }
        }

        //right / greater
        if (minNumPosition != arr2.size()){
            int diff = abs(num - arr2[minNumPosition]);

            if (diff < minDiffPair){
                minDiffPair = diff;
                ans = make_pair(arr2[minNumPosition], num);
            }
        }
    }
    
    return ans;
}

//Another solution
//O(n log n) - Time
//O(1) - Space
pair<int, int> minPair1(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    int minDiff = abs(arr1[0] - arr2[0]);
    pair<int, int> pair1 = make_pair(arr1[0], arr2[0]);
    while (i < arr1.size() && j < arr2.size()) {
        int diff = abs(arr1[i] - arr2[j]);
        if (diff < minDiff) {
            minDiff = diff;
            pair1 = make_pair(arr1[i], arr2[j]);
        }
        if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return pair1;
}

int main() {
    vector<int> arr1 = {-1, 5, 10, 20, 3,0,2,342};
    vector<int> arr2 = {26, 134, 135, 15, 17,343};

    auto pair = minPair(arr1,arr2);

    cout << pair.first << ", " << pair.second << endl;
    

    return 0;
}