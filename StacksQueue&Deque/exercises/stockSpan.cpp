#include <bits/stdc++.h>

using namespace std;

//Brute Force - First Approach
//Time - O(n^2)
vector<int> stockSpanBruteForce(vector<int> v){
    vector<int> ans(v.size());

    for(int i = 0; i < v.size(); i++){
        int cnt = 1;
        int j = i;
        while(j-1 >= 0 and v[j-1] <= v[i]){
            cnt++;
            j--;
        }
        ans[i] = cnt;
    }
    return ans;
}

//Efficient solution
//Time - O(n)
vector<int> stockSpan(vector<int> v){
    vector<int> ans(v.size());
    stack<pair<int,int>> s;
    for(int i = 0; i < v.size(); i++){
        int currentPrice = v[i];
        while(not s.empty() and currentPrice >= s.top().second){
            s.pop();
        }
        if(not s.empty()){
            int prevHighest = s.top().first;
            ans[i] = i - prevHighest;
        }else{
            ans[i] = i + 1;
        }
        s.push({i,v[i]});
    }
    return ans;
}

int main(){

    auto ans = stockSpanBruteForce({100, 80, 60, 70, 60, 75, 85});
    for(int num : ans){
        cout << num << " ";
    }

    return 0;
}