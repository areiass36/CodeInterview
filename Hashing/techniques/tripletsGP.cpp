#include<bits/stdc++.h>

using namespace std;

//Ryan's Solution
// Time - O(n)
// Space - O(n)
vector<vector<int>> findTriplets(vector<int> arr, int r){
    unordered_map<int,int> left;
    unordered_map<int,int> right;
    for(int num : arr){
        right[num]++;
    }
    vector<vector<int>> ans;
    for(int num : arr){
        int prev = num/r;
        int mid = num;
        int next = num*r;

        right[mid]--;
        if (mid % r == 0 and left[prev] > 0 and right[next] > 0){
            int leftFreq = left[prev];
            int rightFreq = right[next];
            for(int i = 0; i < leftFreq*rightFreq; i++){
                ans.push_back({prev,mid,next});
            }
        }

        left[mid]++;
    }
    return ans;
}

// Course Solution
// Time - O(n)
// Space - O(n)
int countTriplets(vector<int> arr, int r){
    int n = arr.size();
    unordered_map<long,long> right,left;

    for(auto x : arr){
        right[x]++;
        left[x] = 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        right[arr[i]]--;
        if (arr[i]%r == 0){
            long b = arr[i];
            long a = arr[i]/r;
            long c = arr[i]*r;

            ans += left[a] * right[c];
        }
        left[arr[i]]++;
    }
    return ans;
}


int main() {
    vector<int> arr = {1,16,4,16,64,16};
    int r = 4;

    auto ans = findTriplets(arr,r);
    for(auto triplet : ans){
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }
    cout << "total Triplets: " << countTriplets(arr,r) << endl;
}