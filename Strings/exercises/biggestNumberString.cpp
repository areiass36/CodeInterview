#include<bits/stdc++.h>
using namespace std;

//TODO: Back in this question after see  Smallest String video from section Sorting and Searching

//https://leetcode.com/problems/largest-number/

static bool compare(int a, int b){
    string aStr = to_string(a);
    string bStr = to_string(b);

    return aStr + bStr > bStr + aStr;
}

//O(n log n) - time
//O(1) - space
string concatenate(vector<int>& nums) {
    sort(nums.begin(), nums.end(), compare);
    
    string ans = "";
    for(int num : nums){
        ans += to_string(num);
    }

    if (ans[0] == '0')
        return "0";
    
    return ans;
}

int main(){
    vector<int> input = {10, 11, 20, 30, 3};

    cout << concatenate(input) << endl;
}