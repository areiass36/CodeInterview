#include <bits/stdc++.h>

using namespace std;

//Little different on Leetcode
//https://leetcode.com/problems/minimum-window-substring/

//Neetcode solution - https://youtu.be/jSto0O4AJbM
//O(m + n) - time
//O(1) - space
string smallestWindow(string str){
    unordered_map<char,int> freqMap;
    
    int minWindow = INT_MAX;
    int distinctChars = 0;
    int startIdx = -1;
    
    for(char ch : str){
        if (freqMap[ch] == 0)
            distinctChars++;
        freqMap[ch]++;
    }
    
    int leftPtr = 0;
    int rightPtr = 0;
    
    unordered_map<char,int> windowMap;
    
    int windowCharsCnt = 0;
    
    while (rightPtr < str.length()){
        char rch = str[rightPtr];
        windowMap[rch]++;
        
        if(windowMap[rch] == 1){
            windowCharsCnt++;
        }
        
        if (windowCharsCnt == distinctChars){
            while(windowCharsCnt == distinctChars){
                int windowSize = rightPtr - leftPtr + 1;
                if (windowSize < minWindow){
                    minWindow = windowSize;
                    startIdx = leftPtr;
                }
                
                char lch = str[leftPtr];
                windowMap[lch]--;
                
                if (windowMap[lch] == 0){
                    windowCharsCnt--;
                }
                leftPtr++;
            }
        }
        rightPtr++;
    }
    
    return str.substr(startIdx, minWindow);
}

int main(){
    cout << smallestWindow("aabcbcdbcaaad") << endl; //dbca
    cout << smallestWindow("aaaa") << endl; //a
}