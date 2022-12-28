#include <bits/stdc++.h>

using namespace std;

//Course Solution
bool isSubset(string s1, string s2){
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    while(i >= 0 and j >= 0){
        if (s2[j] == s1[i]){
            i--;
            j--;
        } else {
            i--;
        }
    }
    if (j == -1)
        return true;
    else {
        return false;
    }
}

//Ryan Solution 
//O(m + n) - time
//O(1) - space
bool checkSubset(string s1, string s2){
    if (s1.length() < s2.length()){
        return false;
    }

    int cnt = 0;
    int n = s2.length();
    for(int i = 0; i < s1.length(); i++){
        if (s2[cnt] == s1[i]){
            cnt++;
        }
        if (cnt == n)
            return true;
    }
    return false;
}

int main() {
    
    string s1 = "coding minutes";
    //string s2 = "wrong";
    string s2 = "cines";

    //bool ans = checkSubset(s1,s2);
    bool ans = isSubset(s1,s2);

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}