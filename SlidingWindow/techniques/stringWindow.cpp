#include <bits/stdc++.h>

using namespace std;

//Course Solution -Hashing Solution
//O(m + n) - time
//O(1) - space
string stringWindow(string s, string p){
    int FP[256] = {0};
    int FS[256] = {0};

    for(int i = 0; i < p.length(); i++){
        FP[p[i]]++;
    }
    
    int cnt = 0;
    int start = 0; //left contraction
    int startIdx = -1; //StartIdx for best window 
    int minSoFar = INT_MAX; //large number
    int windowSize = 0;

    //Sliding Window Algorithm
    for(int i = 0; i < s.length(); i++){
        //Expand the window by including current character
        char ch = s[i];
        FS[ch]++;
        
        //Count how many characters have been matched till now (string and pattern)
        if (FP[ch] != 0 and FS[ch] <= FP[ch]){
            cnt++;
        }

        //Another Thing
        //If all characters of the pattern are found in the current window
        //then you can start contracting
        if (cnt == p.length()){
            //start contracting from the left to remove unwanter characters
            while(FP[s[start]] == 0 or FS[s[start]] > FP[s[start]]){
                FS[s[start]]--;
                start++;
            }

            //note. the window size
            int windowSize = i - start + 1;
            if (windowSize < minSoFar){
                minSoFar = windowSize;
                startIdx = start;
            }
        }
    }
    if (startIdx == -1){
        return "no window found";
    }  
    return s.substr(startIdx, minSoFar);
}

//Sliding Window solution
//O(m + n) - time
//O(1) - space
string stringWindow2(string str1, string str2){
    unordered_map<char,int> frequencyMap;
    
    int minStringSize = INT_MAX;
    int startIdx = -1;
    int cnt = 0;

    for(char ch : str2){
        if(frequencyMap[ch] == 0){
            cnt++;
        }
        frequencyMap[ch]++;
    }

    int leftPtr = 0;
    int rightPtr = 0;

    while(rightPtr < str1.length()){
        char rightChar = str1[rightPtr];
        frequencyMap[rightChar]--;

        if(frequencyMap[rightChar] == 0){
            cnt--;
        }

        if (cnt == 0){
            while(cnt == 0){
                int windowSize = rightPtr - leftPtr + 1;
                if(windowSize < minStringSize){
                    minStringSize = windowSize;
                    startIdx = leftPtr;
                }

                char leftChar = str1[leftPtr];
                frequencyMap[leftChar]++;

                if (frequencyMap[leftChar] > 0){
                    cnt++;
                }
                leftPtr++;
            }
        }
        rightPtr++;
    }

    if (minStringSize == INT_MAX){
        return "no window found";
    }
    return str1.substr(startIdx, minStringSize);
}

int main() {

    cout << stringWindow2("hello_world","lol") << endl; //llo
    cout << stringWindow2("hello","eol") << endl; //ello
    cout << stringWindow2("papo reto","pprt") << endl; //papo ret

    return 0;
}