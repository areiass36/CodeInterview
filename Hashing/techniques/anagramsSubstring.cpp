#include <bits/stdc++.h>

using namespace std;

/*
1. Generate all substrings
2. Generate their hash
3. Hash the 'hash' values to club all anagrams in single bucket, to get their frequency count
4. From freq count, wecan easily count the pairs
*/

vector<int> getHashValue(string s, int i, int j){
    vector<int> freq(26,0);
    for(int k = i; k <= j; k++){
        char ch = s[k];
        freq[ch-'a']++;
    }
    return freq;
}

// Time - O(n³ + n²) -> O(n³)
// Space - O(n²)
int anagrams_substrings(string s){
    map<vector<int>,int> freqMap;
    for(int i = 0; i < s.length();i++){
        for(int j = i; j < s.length();j++){
            vector<int> hash = getHashValue(s,i,j);
            freqMap[hash]++;
        }
    }

    // count pairs
    int ans = 0;
    for(auto [hash, freq] : freqMap) {
        if (freq >= 2){
            ans++;
        }
    }
    return ans;
}

int main(){
    cout << anagrams_substrings("abba") << endl;
}