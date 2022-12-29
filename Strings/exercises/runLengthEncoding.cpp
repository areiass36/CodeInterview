#include<bits/stdc++.h>
using namespace std;

//Little different on Leetcode
//https://leetcode.com/problems/string-compression/

//O(n) - time
//O(n) - space
string compressString(const string &str){   
    map<char, int> map;
    for(char ch : str){
        map[ch]++;
    }
    
    string ans = "";
    for(auto pair : map){
        ans += pair.first + to_string(pair.second);
    }
    
    if (ans.length() >= str.length())
        return str;
    
    return ans;  
}


int main(){
    cout << compressString("bbbaaaadexxxxxx") << endl; //b3a4d1e1x6
    cout << compressString("abcd") << endl; //abcd 

    return 0;
}