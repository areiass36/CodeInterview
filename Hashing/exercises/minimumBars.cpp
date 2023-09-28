#include<bits/stdc++.h>
using namespace std;

int _min_bars(string s, int idx, unordered_set<string> dict, int dp[]){
    if (idx == -1) return 0;
    if (dp[idx] != 0) return dp[idx];
    
    int ans = INT_MAX;
    string temp = "";
    for(int i=idx; i>=0; i--){
        temp = s[i] + temp;
        if (dict.find(temp) != dict.end()){
            int sub_ans = _min_bars(s, i-1, dict, dp);
            if (sub_ans != -1){
                ans = min(ans, sub_ans+1);
            }
        }
    }
    if (ans == INT_MAX) ans = -1;
    dp[idx] = ans;
    return ans;
}

// Time - O(n^2)
// Space - O(n)
int min_bars(string s, string words[], int n){
    unordered_set<string> dict;
    for(int i=0; i<n; i++){
        dict.insert(words[i]);
    }

    int dp[s.length()+1];
    memset(dp, 0, sizeof(dp));
    dp[s.length()] = 1;

    return _min_bars(s, s.length()-1, dict, dp) - 1; // recursive

    // TODO: iterative version
}