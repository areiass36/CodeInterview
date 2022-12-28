#include <bits/stdc++.h>

using namespace std;

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

    string inputString = "aab";

    auto output = getSubsequence(inputString);

    for(string str : output){
        cout << str << " ";
    }
    cout << endl;

    return 0;
}