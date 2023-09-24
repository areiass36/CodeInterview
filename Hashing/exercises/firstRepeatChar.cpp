#include <bits/stdc++.h>

using namespace std;

char firstRepeatChar(string input){
    // unordered_map<char,int> m;
    // for(char ch : input){
    //     m[ch]++;
    //     if (m[ch] > 1){
    //         return ch;
    //     }
    // }
    unordered_set<char> s;
    for(char ch : input){
        if (s.find(ch) != s.end()){
            return ch;
        }
        s.insert(ch);
    }
    return '\0';
}