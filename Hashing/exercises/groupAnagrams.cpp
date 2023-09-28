#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/group-anagrams/

vector<int> getHash(string s){
    vector<int> hash(26,0);
    for(char ch : s){
        hash[ch - 'a']++;
    }
    return hash;
}

// Time - O(n*k log n)
// Space - O(n)
vector<vector<string>> groupAnagrams(vector<string> strs){
    map<vector<int>, vector<string>> groupWords;

    for(string word : strs) {
        vector<int> hash = getHash(word);
        groupWords[hash].push_back(word);
    }
    vector<vector<string>> ans;
    for(auto [hash, words] : groupWords){
        vector<string> group;
        for(string word : words) {
            group.push_back(word);
        }
        ans.push_back(group);
    }
    return ans;
}

int main() {
    vector<string> arr = {"eat","tea","tan","ate","nat","bat"};

    auto ans = groupAnagrams(arr);

    for(auto groupWords : ans) {
        cout << "group: ";
        for(string word : groupWords){
            cout << word << " ";
        }
        cout << endl;
    }
}