#include <bits/stdc++.h>

using namespace std;


int _countWordBreak(string s, vector<string> words, int idx, unordered_set<string> &wordSet){
    //base case
    if (idx == s.length()){
        return 0;
    }
    //rec case
    int ans = INT_MAX;
    string currString = "";
    for (int k = idx; k < s.length(); k++){
        currString += s[k];
        if (wordSet.find(currString) != wordSet.end()){
            int remaingAns = _countWordBreak(s,words,k+1,wordSet);
            if (remaingAns != -1){
                ans = min(ans, remaingAns+1);
            }
        }
    }
    if (ans == INT_MAX){
        return -1;
    }
    return ans;
}

// TODO: Use dynamic programming to optmize this

int countWordBreak(string str, vector<string> words){
    unordered_set<string> wordSet;
    for(string word : words){
        wordSet.insert(word);
    }

    return _countWordBreak(str, words, 0, wordSet) - 1;
}

int main() {
    string str = "thequickbrownfoxjumpsoverthehighbridge";

    vector<string> words = {"the","fox", "thequickbrownfox", "jumps", "lazy", 
                        "lazyfox", "highbridge", "the", "over", "bridge", 
                        "high", "tall", "quick", "brown"};

    cout << countWordBreak(str,words) << endl;
}