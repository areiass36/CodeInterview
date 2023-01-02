#include <bits/stdc++.h>

using namespace std;

//Course Solution
string uniqueSubstring(string str){
    int i = 0;
    int j = 0;

    int windowLen = 0;
    int maxWindowLen = 0;
    int startWindow = -1;

    unordered_map<char, int> m;

    while(j < str.length()){
        char ch = str[j];

        //if it is inside hashmap & its idx >= start of the current window
        if(m.count(ch) and m[ch] >= i){
            i = m[ch] + 1;
            windowLen = j - i; //updated remaining window len excluding current char
        }

        //update the last occurrence
        m[ch] = j;
        windowLen++;
        j++;

        //update maxWindowLen at every step
        if (windowLen > maxWindowLen){
            maxWindowLen = windowLen;
            startWindow = i;
        }
    }

    return str.substr(startWindow, maxWindowLen);
}

//Ryan Solution
//O(n) - time
//O(n) - space
string uniqueSubstring2(string str){
    int n = str.length();

    unordered_map<char,int> hashMap;

    pair<int, int> substringIndex;

    int startIndex = 0;
    int currentIndex = 0;
    int maxSubstringSize = INT_MIN;

    //O(n)
    while(currentIndex < n){
        char c = str[currentIndex];
        auto found = hashMap.find(c);
        if (found != hashMap.end()){ //Found character
            int nextIndex = hashMap[c] + 1;
            startIndex = max(nextIndex, startIndex);
            hashMap[c] = currentIndex;
        } else {
            hashMap[c] = currentIndex;
        }
        int currentSize = currentIndex - startIndex;
        if (currentSize > maxSubstringSize){
            maxSubstringSize = currentSize;
            substringIndex = make_pair(startIndex, currentIndex);
        }
        currentIndex++;
    }

    int size = substringIndex.second - substringIndex.first + 1;
    
    //O(n)
    string ans = str.substr(substringIndex.first, size);
    
    return ans;
}

int main() {

    string input1 = "prateekbhaiya"; //ekbhaiy
    string input2 = "abcabcdsabc"; //abcdsab

    cout << uniqueSubstring(input1) << endl;
    cout << uniqueSubstring(input2) << endl;

    return 0;
}