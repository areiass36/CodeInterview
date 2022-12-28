#include <bits/stdc++.h>

using namespace std;

//Course Solution
//O(2^N) - time
//O(n) - space (due to recursive call stack)
void subsequence(string s, string o, vector<string> &v){
    //Base case
    if (s.length() == 0){
        v.push_back(o);
        return;
    }

    char ch = s[0];
    string reduced_input = s.substr(1);
    
    //Goes to left - Includes  
    subsequence(reduced_input, o + ch, v);

    //Goes to right - Excludes
    subsequence(reduced_input, o, v);
}

bool lexicoCompare(string s1, string s2){
    if (s1.length() == s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

//Parcial Solution - Ryan
//O(m * 2^n) - time (n is string length and m binary string length.)
//O(1) - space (answer vector doesn't count, [I think])
vector<string> getSubsequence(string str){
    int n = str.length();

    vector<string> v; // Doesn't sort the answer, maybe a map or set will sort it

    int max = 1 << n;
    for(int i = 0; i < max; i++){
        string ans = "";
        int num = i;
        int cnt = 0;
        while(num > 0){
            int lastBit = num & 1;
            if (lastBit){
                ans += str[cnt];
            }
            cnt++;
            num >>= 1;
        }
        v.push_back(ans);
    }
    sort(v.begin(), v.end());

    return v;
}

int main() {

    string inputString = "abcd";

    //auto output = getSubsequence(inputString); //Ryan Solution

    //Course Solution
    vector<string> output;
    subsequence(inputString, "", output);
    sort(output.begin(), output.end(), lexicoCompare);

    for(string str : output){
        cout << str << " ";
    }
    cout << endl;

    return 0;
}