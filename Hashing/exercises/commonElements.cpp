#include <bits/stdc++.h>

using namespace std;

//little different on leetcode
//https://leetcode.com/problems/intersection-of-two-arrays/

vector<int> commonElements(vector<int> v1, vector<int> v2){
    map<int,int> m; 
    for(int num : v1){
        m[num]++;
    }
    for(int num : v2){
        m[num]++;
    }

    vector<int> ans;
    for(auto [key,val] : m){
        if (val > 1){
            ans.push_back(key);
        }
    }
    return ans;
}

int main() {
    vector<int> v1 = {1, 45, 54, 71, 76, 12};
    vector<int> v2 = {1, 7, 5, 4, 6, 12};

    auto ans = commonElements(v1,v2);

    for(int num : ans){
        cout << num << " ";
    }
    cout << endl;
}