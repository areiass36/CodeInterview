#include <bits/stdc++.h>

using namespace std;

bool lexicoCompare(string str1, string str2){
    return str1 + str2 < str2 + str1;
}

string smallestString(vector<string> arr){
    sort(arr.begin(),arr.end(), lexicoCompare);

    string ans = "";

    for(string str : arr){
        ans += str;
    }

    return ans;
}

int main() {

    vector<string> arr = {"a","ab","aba"};

    cout << smallestString(arr) << endl;

    return 0;
}